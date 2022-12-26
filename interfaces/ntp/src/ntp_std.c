/**
 * @file ntp_std.c
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

#include "ntp_cfg.h"
#include "cnet_error.h"

int ntp_start(ntp_cfg_t *cfg)
{
    printf("ntp_start\n");
    return CNET_ERR_OK;
}

int ntp_stop(void)
{
    printf("ntp_stop\n");
    return CNET_ERR_OK;
}

#endif  //CNET_CONFIG_HARDWARE_STD