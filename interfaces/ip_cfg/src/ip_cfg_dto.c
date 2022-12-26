/**
 * @file ip_cfg_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ip_cfg_dto.h"

cJSON *ip_cfg_to_json(DTO_TO_JSON_PARAMETERS(ip_cfg_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_NUMBER(dhcp);
    DTO_TO_JSON_CHAR_ARRAY(ip);
    DTO_TO_JSON_CHAR_ARRAY(mask);
    DTO_TO_JSON_CHAR_ARRAY(gateway);
    DTO_TO_JSON_CHAR_ARRAY(dns);
    DTO_TO_JSON_END();
}

void ip_cfg_from_json(DTO_FROM_JSON_PARAMETERS(ip_cfg_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_NUMBER(dhcp);
    DTO_FROM_JSON_CHAR_ARRAY(ip);
    DTO_FROM_JSON_CHAR_ARRAY(mask);
    DTO_FROM_JSON_CHAR_ARRAY(gateway);
    DTO_FROM_JSON_CHAR_ARRAY(dns);
    DTO_FROM_JSON_END();
}
