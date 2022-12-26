/**
 * @file http_response_dto.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __HTTP_RESPONSE_DTO__H__
#define __HTTP_RESPONSE_DTO__H__

#include "dto_helpers.h"
#include "http_response.h"

cJSON *http_response_to_json(DTO_TO_JSON_PARAMETERS(http_response_t));
void http_response_from_json(DTO_FROM_JSON_PARAMETERS(http_response_t));

#endif  //!__HTTP_RESPONSE_DTO__H__