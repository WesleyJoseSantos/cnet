/**
 * @file wifi_ap_cfg_dto.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __WIFI_AP_CFG_DTO__H__
#define __WIFI_AP_CFG_DTO__H__

#include "dto_helpers.h"
#include "wifi_ap_cfg.h"

cJSON *wifi_ap_cfg_to_json(DTO_TO_JSON_PARAMETERS(wifi_ap_cfg_t));
void wifi_ap_cfg_from_json(DTO_FROM_JSON_PARAMETERS(wifi_ap_cfg_t));

#endif //!__WIFI_AP_CFG_DTO__H__