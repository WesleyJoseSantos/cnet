/**
 * @file http_response_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "http_response_dto.h"

cJSON *http_response_to_json(DTO_TO_JSON_PARAMETERS(http_response_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_NUMBER(status_code);
    DTO_TO_JSON_CHAR_ARRAY(content);
    DTO_TO_JSON_END();
}

void http_response_from_json(DTO_FROM_JSON_PARAMETERS(http_response_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_NUMBER(status_code);
    DTO_FROM_JSON_CHAR_ARRAY(content);
    DTO_FROM_JSON_END();
}
