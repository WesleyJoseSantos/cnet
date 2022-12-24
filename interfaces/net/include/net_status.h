/**
 * @file net_status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __NET_STATUS__H__
#define __NET_STATUS__H__

#include <stdbool.h>

/**
 * @brief Network interface status
 * 
 */
typedef struct net_status
{
    bool started;   ///!< Network interface started
    bool connected; ///!< Network interface connected
} net_status_t;

#endif  //!__NET_STATUS__H__