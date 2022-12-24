/**
 * @file net_info.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __NET_INFO__H__
#define __NET_INFO__H__

/**
 * @brief Network interface information
 * 
 */
typedef struct net_info
{
    char ip[16];    ///< Network interface IP
    char mac[13];   ///< Network interface MAC
    char ssid[13];  ///< Network interface SSID
} net_info_t;

#endif  //!__NET_INFO__H__