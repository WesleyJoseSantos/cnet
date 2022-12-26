/**
 * @file net_status_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "net_status_dto.h"

cJSON *net_status_to_json(DTO_TO_JSON_PARAMETERS(net_status_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_BOOLEAN(started);
    DTO_TO_JSON_BOOLEAN(connected);
    DTO_TO_JSON_END();
}

void net_status_from_json(DTO_FROM_JSON_PARAMETERS(net_status_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_BOOLEAN(started);
    DTO_FROM_JSON_BOOLEAN(connected);
    DTO_FROM_JSON_END();
}
