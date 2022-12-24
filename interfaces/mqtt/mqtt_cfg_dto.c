/**
 * @file mqtt_cfg_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "mqtt_cfg_dto.h"

cJSON *mqtt_cfg_to_json(DTO_TO_JSON_PARAMETERS(mqtt_cfg_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_CHAR_ARRAY(host);
    DTO_TO_JSON_NUMBER(port);
    DTO_TO_JSON_CHAR_ARRAY(username);
    DTO_TO_JSON_CHAR_ARRAY(password);
    DTO_TO_JSON_NUMBER(transport);
    DTO_TO_JSON_END();
}

void mqtt_cfg_from_json(DTO_FROM_JSON_PARAMETERS(mqtt_cfg_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_CHAR_ARRAY(host);
    DTO_FROM_JSON_NUMBER(port);
    DTO_FROM_JSON_CHAR_ARRAY(username);
    DTO_FROM_JSON_CHAR_ARRAY(password);
    DTO_FROM_JSON_NUMBER(transport);
    DTO_FROM_JSON_END();
}