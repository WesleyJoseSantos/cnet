/**
 * @file ntp_cfg.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __NTP_CFG__H__
#define __NTP_CFG__H__

#include <stdbool.h>
#include <inttypes.h>

/**
 * @brief NTP configuration
 *
 */
typedef struct ntp_cfg
{
    bool enabled;           ///< Enable NTP connection
    uint8_t op_mode;        ///< NTP operation mode
    uint8_t sync_mode;      ///< NTP sync mode
    uint32_t sync_interval; ///< NTP sync interval (ms)
    char server1[64];       ///< NTP server 1
    char server2[64];       ///< NTP server 2
    char server3[64];       ///< NTP server 3
} ntp_cfg_t;

#endif //!__NTP_CFG__H__