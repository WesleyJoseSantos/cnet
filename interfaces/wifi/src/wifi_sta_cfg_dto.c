/**
 * @file wifi_sta_cfg_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "wifi_sta_cfg_dto.h"

cJSON *wifi_sta_cfg_to_json(DTO_TO_JSON_PARAMETERS(wifi_sta_cfg_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_BOOLEAN(enabled);
    DTO_TO_JSON_CHAR_ARRAY(ssid);
    DTO_TO_JSON_CHAR_ARRAY(password);
    DTO_TO_JSON_CHAR_ARRAY(identity);
    DTO_TO_JSON_CHAR_ARRAY(username);
    DTO_TO_JSON_BOOLEAN(enterprise);
    DTO_TO_JSON_OBJ(ip_cfg);
    DTO_TO_JSON_END();
}

void wifi_sta_cfg_from_json(DTO_FROM_JSON_PARAMETERS(wifi_sta_cfg_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_BOOLEAN(enabled);
    DTO_FROM_JSON_CHAR_ARRAY(ssid);
    DTO_FROM_JSON_CHAR_ARRAY(password);
    DTO_FROM_JSON_CHAR_ARRAY(identity);
    DTO_FROM_JSON_CHAR_ARRAY(username);
    DTO_FROM_JSON_BOOLEAN(enterprise);
    DTO_FROM_JSON_OBJ(ip_cfg);
    DTO_FROM_JSON_END();
}
