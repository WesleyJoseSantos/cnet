/**
 * @file http_request_cfg_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "http_request_cfg_dto.h"

cJSON *http_request_cfg_to_json(DTO_TO_JSON_PARAMETERS(http_request_cfg_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_STRING(url);
    DTO_TO_JSON_NUMBER(method);
    DTO_TO_JSON_NUMBER(transport);
    DTO_TO_JSON_STRING(cert);
    DTO_TO_JSON_STRING(content);
    DTO_TO_JSON_OBJ_ARRAY(headers);
    DTO_TO_JSON_END();
}

void http_request_cfg_from_json(DTO_FROM_JSON_PARAMETERS(http_request_cfg_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_STRING(url);
    DTO_FROM_JSON_NUMBER(method);
    DTO_FROM_JSON_NUMBER(transport);
    DTO_FROM_JSON_STRING(cert);
    DTO_FROM_JSON_STRING(content);
    DTO_FROM_JSON_OBJ_ARRAY(headers);
    DTO_FROM_JSON_END();
}
