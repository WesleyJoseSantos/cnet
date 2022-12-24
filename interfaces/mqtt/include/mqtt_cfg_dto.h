/**
 * @file mqtt_cfg_dto.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MQTT_CFG_DTO__H__
#define __MQTT_CFG_DTO__H__

#include "dto_helpers.h"
#include "mqtt_cfg.h"

cJSON *mqtt_cfg_to_json(DTO_TO_JSON_PARAMETERS(mqtt_cfg_t));
void mqtt_cfg_from_json(DTO_FROM_JSON_PARAMETERS(mqtt_cfg_t));

#endif  //!__MQTT_CFG_DTO__H__
