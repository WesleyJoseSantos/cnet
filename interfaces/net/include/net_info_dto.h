/**
 * @file net_info_dto.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __NET_INFO_DTO__H__
#define __NET_INFO_DTO__H__

#include "dto_helpers.h"
#include "net_info.h"

cJSON *net_info_to_json(DTO_TO_JSON_PARAMETERS(net_info_t));
void net_info_from_json(DTO_FROM_JSON_PARAMETERS(net_info_t));

#endif //!__NET_INFO_DTO__H__