/**
 * @file http_request_cfg.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __HTTP_REQUEST_CFG__H__
#define __HTTP_REQUEST_CFG__H__

#include <inttypes.h>
#include "http_request_header.h"

/**
 * @brief HTTP Request configuration
 *
 */
typedef struct http_request_cfg
{
    char *url;                      ///!< HTTP Request URL
    uint8_t method;                 ///!< HTTP Request method
    uint8_t transport;              ///!< HTTP Request transport
    char *cert;                     ///!< HTTP Request cert
    char *content;                  ///!< HTTP Request content
    http_request_header_t *headers; ///!< HTTP Request headers
    uint8_t headers_count;          ///!< HTTP Headers count
} http_request_cfg_t;

#endif //!__HTTP_REQUEST_CFG__H__