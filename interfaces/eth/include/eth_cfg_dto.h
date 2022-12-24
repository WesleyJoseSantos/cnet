/**
 * @file eth_cfg_dto.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ETH_CFG_DTO__H__
#define __ETH_CFG_DTO__H__

#include "dto_helpers.h"
#include "eth_cfg.h"

cJSON *eth_cfg_to_json(DTO_TO_JSON_PARAMETERS(eth_cfg_t));
void eth_cfg_from_json(DTO_FROM_JSON_PARAMETERS(eth_cfg_t));

#endif  //!__ETH_CFG_DTO__H__