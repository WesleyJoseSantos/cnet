/**
 * @file cnet_app.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cnet_app.h"
#include "cnet_config.h"
#include "cnet_error.h"

#include "net_info_dto.h"
#include "net_status_dto.h"
#include "http_response_dto.h"

#include "cJSON.h"

#define GET_EVT_BIT(msg_id) (1 << msg_id)

typedef struct cnet_app
{
    TaskHandle_t task;
    QueueHandle_t queue;
    EventGroupHandle_t event_group;
    cnet_app_settings_t settings;
    cnet_app_queue_result_t queue_result;
    int err_code;
} cnet_app_t;

static cnet_app_t this;

static void cnet_app_task(void *pvParameter);
static int cnet_app_channel_start(cnet_app_channel_t channel, cnet_app_msg_data_t *data);
static int cnet_app_channel_stop(cnet_app_channel_t channel);
static int cnet_app_channel_get_info(cnet_app_channel_t channel);
static int cnet_app_channel_get_status(cnet_app_channel_t channel);
static int cnet_app_data_to_queue_result(void *data_buf, void *get_data_handler(void*), void *to_json_handler(void*));
static int cnet_app_settings_reset(void);
static int cnet_app_settings_save(void);
static int cnet_app_settings_load(void);

int cnet_app_start(void)
{
    this.queue = xQueueCreate(5, sizeof(cnet_app_queue_msg_t));
    this.event_group = xEventGroupCreate();
    xTaskCreate(cnet_app_task, "cnet_app_task", CNET_CONFIG_TASK_STACK_SIZE, NULL, CNET_CONFIG_TASK_PRIORITY, &this.task);
}

BaseType_t cnet_app_send_msg(cnet_app_queue_msg_t *msg)
{
    this.err_code = CNET_ERR_OK;
    xEventGroupClearBits(this.event_group, GET_EVT_BIT(msg->id));
    return xQueueSend(this.queue, msg, 5000 / portTICK_PERIOD_MS);
}

void cnet_app_wait_msg_processing(cnet_app_msg_id_t msg_id, uint32_t timeout)
{
    xEventGroupWaitBits(this.event_group, GET_EVT_BIT(msg_id), pdFALSE, pdFALSE, timeout / portTICK_PERIOD_MS);
    EventBits_t event_bits = xEventGroupGetBits(this.event_group);
    if ((event_bits & GET_EVT_BIT(msg_id)) == false)
    {
        this.err_code = CNET_ERR_TIMEOUT;
    }
}

int cnet_app_get_error_code(void)
{
    return this.err_code;
}

static void cnet_app_task(void *pvParameter)
{
    cnet_app_queue_msg_t msg;

    for (;;)
    {
        if(xQueueReceive(this.queue, &msg, portMAX_DELAY))
        {
            switch (msg.id)
            {
            case CNET_APP_MSG_ID_START:
                this.err_code = cnet_app_channel_start(msg.channel, &msg.data);
                break;
            case CNET_APP_MSG_ID_STOP:
                this.err_code = cnet_app_channel_stop(msg.channel, &msg.data);
                break;
            case CNET_APP_MSG_ID_GET_INFO:
                this.err_code = cnet_app_channel_get_info(msg.channel);
                break;
            case CNET_APP_MSG_ID_GET_STATUS:
                this.err_code = cnet_app_channel_get_status(msg.channel);
                break;
            case CNET_APP_RESET_SETTINGS:
                this.err_code = cnet_app_settings_reset();
                break;
            case CNET_APP_SAVE_SETTINGS:
                this.err_code = cnet_app_settings_save();
                break;
            case CNET_APP_LOAD_SETTINGS:
                this.err_code = cnet_app_settings_load();
                break;
            default:
                break;
            }
        }
    }
}

static int cnet_app_channel_start(cnet_app_channel_t channel, cnet_app_msg_data_t *data)
{
    switch (channel)
    {
    case CNET_APP_ETHERNET:
        memcpy(&this.settings.eth, data, sizeof(*data));
        return eth_start(&data->eth);
    case CNET_APP_WIFI_AP:
        return wifi_ap_start(&data->wifi_ap);
    case CNET_APP_WIFI_STA:
        return wifi_sta_start(&data->wifi_sta);
    case CNET_APP_WIFI_SCAN:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_HTTP_SERVER:
        return http_server_start();
    case CNET_APP_HTTP_REQUEST:
    {
        http_response_t resp;
        http_request_start(&data->http_request);
        return cnet_app_data_to_queue_result(&resp, http_request_get_resp, http_response_to_json);
    }
    case CNET_APP_NTP:
        return ntp_start(&data->ntp);
    case CNET_APP_MQTT:
        return mqtt_start(&data->mqtt);
    case CNET_APP_PING:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_OTA:
        return CNET_ERR_NOT_IMPLEMENTED;
    default:
        return CNET_ERR_UNRECOGNIZED_INTERFACE;
    }
}

static int cnet_app_channel_stop(cnet_app_channel_t channel)
{
    switch (channel)
    {
    case CNET_APP_ETHERNET:
        return eth_stop();
    case CNET_APP_WIFI_AP:
        return wifi_ap_stop();
    case CNET_APP_WIFI_STA:
        return wifi_sta_stop();
    case CNET_APP_WIFI_SCAN:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_HTTP_SERVER:
        return http_server_stop();
    case CNET_APP_HTTP_REQUEST:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_NTP:
        return ntp_stop();
    case CNET_APP_MQTT:
        return mqtt_stop();
    case CNET_APP_PING:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_OTA:
        return CNET_ERR_NOT_IMPLEMENTED;
    default:
        return CNET_ERR_UNRECOGNIZED_INTERFACE;
    }
}

static int cnet_app_channel_get_info(cnet_app_channel_t channel)
{
    switch (channel)
    {
    case CNET_APP_ETHERNET:
    {
        net_info_t net_info;
        return cnet_app_data_to_queue_result(&net_info, eth_get_info, net_info_to_json);
    }
    case CNET_APP_WIFI_AP:
    {
        net_info_t net_info;
        return cnet_app_data_to_queue_result(&net_info, wifi_ap_get_info, net_info_to_json);
    }
    case CNET_APP_WIFI_STA:
    {
        net_info_t net_info;
        return cnet_app_data_to_queue_result(&net_info, wifi_sta_get_info, net_info_to_json);
    }
    case CNET_APP_WIFI_SCAN:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_HTTP_SERVER:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_HTTP_REQUEST:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_NTP:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_MQTT:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_PING:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_OTA:
        return CNET_ERR_NOT_IMPLEMENTED;
    default:
        return CNET_ERR_UNRECOGNIZED_INTERFACE;
    }
}

static int cnet_app_channel_get_status(cnet_app_channel_t channel)
{
    switch (channel)
    {
    case CNET_APP_ETHERNET:
    {
        net_status_t net_status;
        return cnet_app_data_to_queue_result(&net_status, eth_get_status, net_status_to_json);
    }
    case CNET_APP_WIFI_AP:
    {
        net_status_t net_status;
        return cnet_app_data_to_queue_result(&net_status, wifi_ap_get_status, net_status_to_json);
    }
    case CNET_APP_WIFI_STA:
    {
        net_status_t net_status;
        return cnet_app_data_to_queue_result(&net_status, wifi_sta_get_status, net_status_to_json);
    }
    case CNET_APP_WIFI_SCAN:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_HTTP_SERVER:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_HTTP_REQUEST:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_NTP:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_MQTT:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_PING:
        return CNET_ERR_NOT_IMPLEMENTED;
    case CNET_APP_OTA:
        return CNET_ERR_NOT_IMPLEMENTED;
    default:
        return CNET_ERR_UNRECOGNIZED_INTERFACE;
    }
}

static int cnet_app_data_to_queue_result(void *data_buf, void *get_data_handler(void*), void *to_json_handler(void*))
{
    int err = get_data_handler(data_buf);
    if(err != CNET_ERR_OK)
    {
        return err;
    }
    else
    {
        cJSON *json;
        json = to_json_handler(data_buf);
        cJSON_PrintPreallocated(json, this.queue_result.content, sizeof(this.queue_result.content), false);
        this.queue_result.available = true;
    }
    return err;
}

static int cnet_app_settings_reset(void)
{
    remove(CNET_CONFIG_SETTINGS_FILENAME);
}

static int cnet_app_settings_save(void)
{
    FILE *fd = fopen(CNET_CONFIG_SETTINGS_FILENAME, "w");
    if(fd != NULL)
    {
        fwrite(&this.settings, sizeof(this.settings), 1, fd);
        fclose(fd);
        return CNET_ERR_OK;
    }
    else
    {
        printf("Error opening the file %s for write:%s", CNET_CONFIG_SETTINGS_FILENAME, strerror(errno));
        fclose(fd);
        return CNET_FAIL;
    }
}

static int cnet_app_settings_load(void)
{
    return CNET_ERR_NOT_IMPLEMENTED;
}

EventBits_t cnet_app_set_msg_event_bit(cnet_app_msg_id_t msg_id)
{
    int tst = GET_EVT_BIT(4);
    xEventGroupSetBits(this.event_group, GET_EVT_BIT(msg_id));
}
