/**
 * @file net_status_dto.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __NET_STATUS_DTO__H__
#define __NET_STATUS_DTO__H__

#include "dto_helpers.h"
#include "net_status.h"

cJSON *net_status_to_json(DTO_TO_JSON_PARAMETERS(net_status_t));
void net_status_from_json(DTO_FROM_JSON_PARAMETERS(net_status_t));

#endif //!__NET_STATUS_DTO__H__