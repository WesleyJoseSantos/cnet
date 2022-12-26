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

#ifndef __ETH__H__
#define __ETH__H__

#include "eth_cfg.h"
#include "net_status.h"
#include "net_info.h"

typedef struct eth
{
    net_status_t status;
    net_info_t info;
} eth_t;

int eth_init(void);
int eth_start(eth_cfg_t *cfg);
int eth_stop(void);
int eth_get_status(net_status_t *status);
int eth_get_info(net_info_t *info);

#endif  //!__ETH__H__