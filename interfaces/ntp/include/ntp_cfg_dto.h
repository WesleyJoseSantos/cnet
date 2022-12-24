/**
 * @file ntp_cfg_dto.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __NTP_CFG_DTO__H__
#define __NTP_CFG_DTO__H__

#include "dto_helpers.h"
#include "ntp_cfg.h"

cJSON *ntp_cfg_to_json(DTO_TO_JSON_PARAMETERS(ntp_cfg_t));
void ntp_cfg_from_json(DTO_FROM_JSON_PARAMETERS(ntp_cfg_t));

#endif //!__NTP_CFG_DTO__H__