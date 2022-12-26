/**
 * @file ip_cfg_std.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "cnet_config.h"

#ifdef CNET_CONFIG_HARDWARE_STD

#include <stdio.h>
#include <string.h>

#include "ip_cfg.h"
#include "net_info.h"
#include "cnet_error.h"

int ip_cfg_set(void *interface, ip_cfg_t *cfg)
{
    net_info_t *netif = (net_info_t*)interface;
    memcpy(netif->ip, cfg->ip, sizeof(netif->ip));
    printf("ip_cfg_set\n");
    return CNET_ERR_OK;
}

#endif // CNET_CONFIG_HARDWARE_STD