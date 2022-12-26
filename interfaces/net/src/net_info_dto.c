/**
 * @file net_info_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "net_info_dto.h"

cJSON *net_info_to_json(DTO_TO_JSON_PARAMETERS(net_info_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_CHAR_ARRAY(ip);
    DTO_TO_JSON_CHAR_ARRAY(mac);
    DTO_TO_JSON_CHAR_ARRAY(ssid);
    DTO_TO_JSON_END();
}

void net_info_from_json(DTO_FROM_JSON_PARAMETERS(net_info_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_CHAR_ARRAY(ip);
    DTO_FROM_JSON_CHAR_ARRAY(mac);
    DTO_FROM_JSON_CHAR_ARRAY(ssid);
    DTO_FROM_JSON_END();
}
