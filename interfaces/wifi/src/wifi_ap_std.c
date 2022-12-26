/**
 * @file wifi_ap_std.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "cnet_config.h"

#ifdef  CNET_CONFIG_HARDWARE_STD

#include <string.h>

#include "wifi_ap_cfg.h"
#include "cnet_error.h"

#include "net_info.h"
#include "net_status.h"

typedef struct wifi_ap_std
{
    net_info_t info;
    net_status_t status;
} wifi_ap_std_t;

static wifi_ap_std_t this;

int wifi_ap_start(wifi_ap_cfg_t *cfg)
{
    this.status.started = true;
    this.status.connected = true;
    memcpy(this.info.ip, cfg->ip_cfg.ip, sizeof(this.info.ip));
    memcpy(this.info.ssid, cfg->ssid, sizeof(this.info.ssid));
    printf("wifi_ap_start\n");
    return CNET_ERR_OK;
}

int wifi_ap_stop(void)
{
    printf("wifi_ap_stop\n");
    return CNET_ERR_OK;
}

int wifi_ap_get_status(net_status_t *status)
{
    this.status.started = false;
    this.status.connected = false;
    printf("wifi_ap_get_status\n");
    return CNET_ERR_OK;
}

int wifi_ap_get_info(net_info_t *info)
{
    *info = this.info;
    printf("wifi_ap_get_info\n");
    return CNET_ERR_OK;
}

#endif  //CNET_CONFIG_HARDWARE_STD