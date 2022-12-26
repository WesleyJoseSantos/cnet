/**
 * @file http_request_std.c
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
#include "http_request_cfg.h"
#include "http_response.h"

int http_request_start(http_request_cfg_t *cfg)
{
    printf("http_request_start\n");
    return CNET_ERR_OK;
}

int http_request_get_resp(http_response_t *resp)
{
    printf("http_request_get_resp\n");
    return CNET_ERR_OK;
}

#endif