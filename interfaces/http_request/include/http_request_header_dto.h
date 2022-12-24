/**
 * @file http_request_header_dto.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __HTTP_REQUEST_HEADER_DTO__H__
#define __HTTP_REQUEST_HEADER_DTO__H__

#include "dto_helpers.h"
#include "http_request_header.h"

cJSON *http_request_header_to_json(DTO_TO_JSON_PARAMETERS(http_request_header_t));
void http_request_header_from_json(DTO_FROM_JSON_PARAMETERS(http_request_header_t));

#endif  //!__HTTP_REQUEST_HEADER_DTO__H__