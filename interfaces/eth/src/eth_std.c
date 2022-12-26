/**
 * @file eth_tst.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "include/cnet_config.h"

#ifdef CNET_CONFIG_HARDWARE_STD

#include <stdio.h>

#include "interfaces/net/include/net_info.h"
#include "include/cnet_error.h"
#include "include/cnet_app.h"
#include "include/eth.h"
#include "include/cnet_error.h"

int eth_init(void)
{
    printf("eth_init\n");
    return CNET_ERR_OK;
}

int eth_start(eth_cfg_t *cfg)
{
    printf("eth_start\n");
    cnet_app_set_msg_event_bit(CNET_APP_MSG_ID_START);
    return CNET_ERR_OK;
}

int eth_stop(void)
{
    printf("eth_stop\n");
    cnet_app_set_msg_event_bit(CNET_APP_MSG_ID_STOP);
    return CNET_ERR_OK;
}

int eth_get_status(net_status_t *status)
{
    printf("eth_get_status\n");
    return CNET_ERR_OK;
}

int eth_get_info(net_info_t *info)
{
    printf("eth_get_info\n");
    return CNET_ERR_OK;

}

#endif