/**
 * @file ip_cfg.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __IP_CONFIG__H__
#define __IP_CONFIG__H__

#include <stdbool.h>

/**
 * @brief IP Configuration
 *
 */
typedef struct ip_cfg
{
    bool dhcp;        ///< Enable dhcp
    char ip[16];      ///< Device IP
    char mask[16];    ///< Mask
    char gateway[16]; ///< Gateway IP
    char dns[16];     ///< DNS IP
} ip_cfg_t;

#endif //!__IP_CONFIG__H__