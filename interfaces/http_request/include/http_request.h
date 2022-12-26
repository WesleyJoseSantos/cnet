/**
 * @file http_request.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "http_request_cfg.h"
#include "http_response.h"

int http_request_start(http_request_cfg_t *cfg);
int http_request_get_resp(http_response_t *resp);

