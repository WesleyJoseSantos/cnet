/**
 * @file wifi_ap_cfg.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __WIFI_AP_CFG__H__
#define __WIFI_AP_CFG__H__

#include <stdbool.h>
#include "ip_cfg.h"

/**
 * @brief WiFi Access Point configuration
 *
 */
typedef struct wifi_ap_cfg
{
    bool enabled;      ///!< Enable WiFi access point
    char ssid[32];     ///!< WiFi access point ssid
    char password[64]; ///!< WiFi access point password
    ip_cfg_t ip_cfg;   ///!< WiFi access point ip configuration
} wifi_ap_cfg_t;

#endif //!__WIFI_AP_CFG__H__