/**
 * @file eth.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __ETH_CFG__H__
#define __ETH_CFG__H__

#include "ip_cfg.h"

/**
 * @brief Ethernet configuration
 *
 */
typedef struct eth_cfg
{
    ip_cfg_t ip_cfg; ///< Ethernet IP Configuration
} eth_cfg_t;

#endif //!__ETH_CFG__H__