/**
 * @file wifi_ap.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __WIFI_AP__H__
#define __WIFI_AP__H__

#include "wifi_ap_cfg.h"
#include "net_status.h"
#include "net_info.h"

int wifi_ap_start(wifi_ap_cfg_t *cfg);
int wifi_ap_stop(void);
int wifi_ap_get_status(net_status_t *status);
int wifi_ap_get_info(net_info_t *info);

#endif  //!__WIFI_AP__H__