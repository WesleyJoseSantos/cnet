/**
 * @file mqtt_std.c
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

#include "mqtt_cfg.h"
#include "cnet_error.h"

int mqtt_start(mqtt_cfg_t *cfg)
{
    printf("mqtt_start\n");
    return CNET_ERR_OK;
}

int mqtt_stop(void)
{
    printf("mqtt_stop\n");
    return CNET_ERR_OK;
}

#endif  //CNET_CONFIG_HARDWARE_STD