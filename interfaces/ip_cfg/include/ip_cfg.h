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

#include <inttypes.h>

typedef enum ip_cfg_dhcp_mode
{
    IP_CFG_DHCP_MODE_CLIENT,
    IP_CFG_DHCP_MODE_SERVER,
    IP_CFG_DHCP_MODE_DISABLED,
} ip_cfg_dhcp_mode_t;

/**
 * @brief IP Configuration
 *
 */
typedef struct ip_cfg
{
    uint8_t dhcp;     ///< DHCP Mode
    char ip[16];      ///< Device IP
    char mask[16];    ///< Mask
    char gateway[16]; ///< Gateway IP
    char dns[16];     ///< DNS IP
} ip_cfg_t;

int ip_cfg_set(void *interface, ip_cfg_t *cfg);

#endif //!__IP_CONFIG__H__