/**
 * @file mqtt.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MQTT__H__
#define __MQTT__H__

#include "mqtt_cfg.h"

int mqtt_start(mqtt_cfg_t *cfg);
int mqtt_stop(void);

#endif  //!__MQTT__H__