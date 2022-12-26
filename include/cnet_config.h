/**
 * @file cnet_config.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __CNET_CONFIG__H__
#define __CNET_CONFIG__H__

/* CNET Error Library Configuration */
#define CNET_CONFIG_ERR_BASE 0x0

/* CNET Main Taks Configuration*/
#define CNET_CONFIG_TASK_STACK_SIZE 4096
#define CNET_CONFIG_TASK_PRIORITY (tskIDLE_PRIORITY + 6)

/* CNET Settings Configuration */
#define CNET_CONFIG_SETTINGS_FILENAME "/cnet/cnet_settings.dat"

/* CNET OS Selection */
#define CNET_CONFIG_OS_WINDOWS
// #define CNET_CONFIG_OS_LINUX
// #define CNET_CONFIG_OS_NONE

/* CNET Hardware Selection */
#define CNET_CONFIG_HARDWARE_STD
// #define CNET_CONFIG_HARDWARE_ESP32_IDF

/* CNET Ethernet Configuration */
#define CNET_CONFIG_ETH_PHY_ADDR 0
#define CNET_CONFIG_ETH_PHY_RST_GPIO 5
#define CNET_CONFIG_ETH_MDC_GPIO 23
#define CNET_CONFIG_ETH_MDIO_GPIO 18

#endif //!__CNET_CONFIG__H__