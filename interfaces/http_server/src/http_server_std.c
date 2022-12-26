/**
 * @file http_server_std.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "cnet_config.h"

#ifdef CNET_CONFIG_HARDWARE_STD

#include <stdio.h>

#include "cnet_error.h"
#include "http_response.h"

int http_server_start(void)
{
    printf("http_server_start\n");
    return CNET_ERR_OK;
}

int http_server_stop(void)
{
    printf("http_server_stop\n");
    return CNET_ERR_OK;
}

#endif