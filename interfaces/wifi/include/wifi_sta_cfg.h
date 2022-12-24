/**
 * @file wifi_sta_cfg.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __WIFI_STA_CFG__H__
#define __WIFI_STA_CFG__H__

#include <stdbool.h>
#include "ip_cfg.h"

/**
 * @brief WiFi Station configuration
 * 
 */
typedef struct wifi_sta_cfg
{
    bool enabled;       ///< Enable wifi station connection
    char ssid[32];      ///< WiFi station ssid
    char password[64];  ///< WiFi station password
    char identity[127]; ///< WiFi station enterprise identity
    char username[127]; ///< WiFi station enterprise username
    bool enterprise;    ///< Enable wifi station enterprise mode
    ip_cfg_t ip_cfg;    ///< WiFi station configuration
} wifi_sta_cfg_t;

#endif  //!__WIFI_STA_CFG__H__