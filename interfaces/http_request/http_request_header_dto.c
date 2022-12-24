/**
 * @file http_request_header_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "http_request_header_dto.h"

cJSON *http_request_header_to_json(DTO_TO_JSON_PARAMETERS(http_request_header_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_CHAR_ARRAY(name);
    DTO_TO_JSON_CHAR_ARRAY(value);
    DTO_TO_JSON_END();
}

void http_request_header_from_json(DTO_FROM_JSON_PARAMETERS(http_request_header_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_CHAR_ARRAY(name);
    DTO_FROM_JSON_CHAR_ARRAY(value);
    DTO_FROM_JSON_END();
}