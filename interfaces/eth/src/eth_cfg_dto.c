/**
 * @file eth_cfg_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "eth_cfg_dto.h"
#include "ip_cfg_dto.h"

cJSON *eth_cfg_to_json(DTO_TO_JSON_PARAMETERS(eth_cfg_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_OBJ(ip_cfg);
    DTO_TO_JSON_END();
}

void eth_cfg_from_json(DTO_FROM_JSON_PARAMETERS(eth_cfg_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_OBJ(ip_cfg);
    DTO_FROM_JSON_END();
}
