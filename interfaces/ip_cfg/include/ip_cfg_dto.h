/**
 * @file ip_cfg_dto.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __IP_CFG_DTO__H__
#define __IP_CFG_DTO__H__

#include "dto_helpers.h"
#include "ip_cfg.h"

cJSON *ip_cfg_to_json(DTO_TO_JSON_PARAMETERS(ip_cfg_t));
void ip_cfg_from_json(DTO_FROM_JSON_PARAMETERS(ip_cfg_t));

#endif  //!__IP_CFG_DTO__H__