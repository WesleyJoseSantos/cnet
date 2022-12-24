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

#include "interfaces/eth/include/eth.h"
#include "interfaces/wifi/include/wifi_ap.h"
#include "interfaces/wifi/include/wifi_sta.h"
#include "interfaces/http_server/include/http_server.h"
#include "interfaces/http_request/include/http_request.h"
#include "interfaces/ntp/include/ntp.h"
#include "interfaces/mqtt/include/mqtt.h"

#ifndef BaseType_t
#warning "freeRTOS library BaseType_t definition is missing
#define BaseType_t int
#endif

/**
 * @brief CNET application available interfaces
 *
 */
typedef enum cnet_app_interface
{
    CNET_APP_ETHERNET,     ///!< Ethernet network interface
    CNET_APP_WIFI_AP,      ///!< WiFi Access Point network interface
    CNET_APP_WIFI_STA,     ///!< WiFi Station network interface
    CNET_APP_WIFI_SCAN,    ///!< WiFi Scanner interface
    CNET_APP_HTTP_SERVER,  ///!< HTTP Server interface
    CNET_APP_HTTP_REQUEST, ///!< HTTP Request interface
    CNET_APP_NTP,          ///!< NTP interface
    CNET_APP_MQTT,         ///!< MQTT interface
    CNET_APP_PING,         ///!< Ping protocol interface
    CNET_APP_OTA,          ///!< OTA interface
} cnet_app_interface_t;

/**
 * @brief CNET application available message IDs
 *
 */
typedef enum cnet_app_msg_id
{
    CNET_APP_MSG_ID_START,      ///!< Request to start an interface
    CNET_APP_MSG_ID_STOP,       ///!< Request to stop an interface
    CNET_APP_MSG_ID_GET_INFO,   ///!< Request to get interface information
    CNET_APP_MSG_ID_GET_STATUS, ///!< Request to get interface status
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
    uint8_t interface;        ///!< Interface number that identify who interface will consume the message
    uint32_t timeout;         ///!< Timeout of message processing
    cnet_app_msg_data_t data; ///!< Data with parameters to be used by selected interface
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