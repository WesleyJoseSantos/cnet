/**
 * @file wifi_sta.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __WIFI_STA__H__
#define __WIFI_STA__H__

#include "wifi_sta_cfg.h"
#include "net_status.h"
#include "net_info.h"

int wifi_sta_start(wifi_sta_cfg_t *cfg);
int wifi_sta_stop(void);
int wifi_sta_get_status(net_status_t *status);
int wifi_sta_get_info(net_info_t *info);

#endif  //!__WIFI_STA__H__