/**
 * @file ntp.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __NTP__H__
#define __NTP__H__

#include "ntp_cfg.h"

int ntp_start(ntp_cfg_t *cfg);
int ntp_stop(void);

#endif  //!__NTP__H__