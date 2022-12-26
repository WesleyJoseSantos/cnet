/**
 * @file cnet_app.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __CNET_APP__H__
#define __CNET_APP__H__

#include "eth.h"
#include "wifi_ap.h"
#include "wifi_sta.h"
#include "http_server.h"
#include "http_request.h"
#include "ntp.h"
#include "mqtt.h"
#include "cnet_config.h"

#ifdef CNET_CONFIG_OS_WINDOWS
#include "FreeRTOS.h"
#include "event_groups.h"
#include "queue.h"
#include "task.h"
#endif // CNET_CONFIG_OS_WINDOWS

/**
 * @brief CNET application available channels
 *
 */
typedef enum cnet_app_channel
{
    CNET_APP_ETHERNET,     ///!< Ethernet network channel
    CNET_APP_WIFI_AP,      ///!< WiFi Access Point network channel
    CNET_APP_WIFI_STA,     ///!< WiFi Station network channel
    CNET_APP_WIFI_SCAN,    ///!< WiFi Scanner channel
    CNET_APP_HTTP_SERVER,  ///!< HTTP Server channel
    CNET_APP_HTTP_REQUEST, ///!< HTTP Request channel
    CNET_APP_NTP,          ///!< NTP channel
    CNET_APP_MQTT,         ///!< MQTT channel
    CNET_APP_PING,         ///!< Ping protocol channel
    CNET_APP_OTA,          ///!< OTA channel
} cnet_app_channel_t;

/**
 * @brief CNET application available message IDs
 *
 */
typedef enum cnet_app_msg_id
{
    CNET_APP_MSG_ID_START,      ///!< Request to start an channel
    CNET_APP_MSG_ID_STOP,       ///!< Request to stop an channel
    CNET_APP_MSG_ID_GET_INFO,   ///!< Request to get channel information
    CNET_APP_MSG_ID_GET_STATUS, ///!< Request to get channel status
    CNET_APP_RESET_SETTINGS,    ///!< Request to reset application settings
    CNET_APP_SAVE_SETTINGS,     ///!< Request to save application settings
    CNET_APP_LOAD_SETTINGS,     ///!< Request to load application settings
} cnet_app_msg_id_t;

/**
 * @brief CNET application settings
 *
 */
typedef struct cnet_app_settings
{
    eth_cfg_t eth;           //!< CNET ethernet configuration
    wifi_ap_cfg_t wifi_ap;   //!< CNET wifi access point configuration
    wifi_sta_cfg_t wifi_sta; //!< CNET wifi station configuration
    ntp_cfg_t ntp;           //!< CNET ntp client configuration
    mqtt_cfg_t mqtt;         //!< CNET mqtt client configuration
} cnet_app_settings_t;

/**
 * @brief CNET application message data
 *
 */
typedef union cnet_app_msg_data
{
    eth_cfg_t eth;                   //!< CNET ethernet configuration
    wifi_ap_cfg_t wifi_ap;           //!< CNET wifi access point configuration
    wifi_sta_cfg_t wifi_sta;         //!< CNET wifi station configuration
    ntp_cfg_t ntp;                   //!< CNET ntp client configuration
    mqtt_cfg_t mqtt;                 //!< CNET mqtt client configuration
    http_request_cfg_t http_request; //!> CNET http request configuration
} cnet_app_msg_data_t;

/**
 * @brief CNET application queue message
 *
 */
typedef struct cnet_app_queue_msg
{
    uint8_t id;               ///!< ID number that identify message objective
    uint8_t channel;          ///!< Interface number that identify who channel will consume the message
    uint32_t timeout;         ///!< Timeout of message processing
    cnet_app_msg_data_t data; ///!< Data with parameters to be used by selected channel
} cnet_app_queue_msg_t;

/**
 * @brief CNET application queue result
 *
 */
typedef struct cnet_app_queue_result
{
    uint8_t id;         ///!< ID of message that produced the queue result
    bool available;     ///!< Flag if an queue result is available
    char content[1023]; ///!< Queue result content
} cnet_app_queue_result_t;

/**
 * @brief Start cnet RTOS application
 *
 * @return int error code
 */
int cnet_app_start(void);

/**
 * @brief Sends a message to CNET application queue
 *
 * @param msg Message to be queued
 * @return BaseType_t pvTRUE if an intem was sucessfully added to the queue otherwise pdFALSE
 */
BaseType_t cnet_app_send_msg(cnet_app_queue_msg_t *msg);

/**
 * @brief Waits for message processing
 *
 * @param msg_id ID of message to wait
 * @param timeout Timeout
 */
void cnet_app_wait_msg_processing(cnet_app_msg_id_t msg_id, uint32_t timeout);

/**
 * @brief Get last error code
 *
 * @return int error code
 */
int cnet_app_get_error_code(void);

/**
 * @brief Set msg event bit to confirm that msg processing is done
 *
 * @param msg_id ID of message to be confirmed
 * @return EventBits_t event bits after set
 */
EventBits_t cnet_app_set_msg_event_bit(cnet_app_msg_id_t msg_id);

#endif //!__CNET_APP__H__