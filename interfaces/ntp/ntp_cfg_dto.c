/**
 * @file ntp_cfg_dto.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ntp_cfg_dto.h"

cJSON *ntp_cfg_to_json(DTO_TO_JSON_PARAMETERS(ntp_cfg_t))
{
    DTO_TO_JSON_INIT();
    DTO_TO_JSON_BOOLEAN(enabled);
    DTO_TO_JSON_NUMBER(op_mode);
    DTO_TO_JSON_NUMBER(sync_mode);
    DTO_TO_JSON_NUMBER(sync_interval);
    DTO_TO_JSON_CHAR_ARRAY(server1);
    DTO_TO_JSON_CHAR_ARRAY(server2);
    DTO_TO_JSON_CHAR_ARRAY(server3);
    DTO_TO_JSON_END();
}

void ntp_cfg_from_json(DTO_FROM_JSON_PARAMETERS(ntp_cfg_t))
{
    DTO_FROM_JSON_INIT();
    DTO_FROM_JSON_BOOLEAN(enabled);
    DTO_FROM_JSON_NUMBER(op_mode);
    DTO_FROM_JSON_NUMBER(sync_mode);
    DTO_FROM_JSON_NUMBER(sync_interval);
    DTO_FROM_JSON_CHAR_ARRAY(server1);
    DTO_FROM_JSON_CHAR_ARRAY(server2);
    DTO_FROM_JSON_CHAR_ARRAY(server3);
    DTO_FROM_JSON_END();
}
