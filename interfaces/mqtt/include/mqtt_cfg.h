/**
 * @file mqtt_cfg.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __MQTT_CFG__H__
#define __MQTT_CFG__H__

#include <inttypes.h>
#include <stdbool.h>

/**
 * @brief MQTT configuration
 *
 */
typedef struct mqtt_cfg
{
    char host[64];     ///< MQTT host
    uint16_t port;     ///< MQTT port
    char username[32]; ///< MQTT username
    char password[32]; ///< MQTT password
    uint8_t transport; ///< MQTT transport
} mqtt_cfg_t;

#endif //!__MQTT_CFG__H__