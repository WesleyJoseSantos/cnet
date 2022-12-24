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

#define CNET_CONFIG_ERR_BASE 0x0
#define CNET_CONFIG_TASK_STACK_SIZE 4096
#define CNET_CONFIG_TASK_PRIORITY (tskIDLE_PRIORITY + 6)
#define CNET_CONFIG_SETTINGS_FILENAME "/cnet/cnet_settings.dat"

#endif //!__CNET_CONFIG__H__