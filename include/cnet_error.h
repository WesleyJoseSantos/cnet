/**
 * @file cnet_error.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __CNET_ERROR__H__
#define __CNET_ERROR__H__

#include <stdio.h>
#include "cnet_config.h"

#define CNET_FAIL -1                                               ///!< Operation failed
#define CNET_ERR_OK 0                                              ///!< No Error
#define CNET_ERR_TIMEOUT (CNET_CONFIG_ERR_BASE + 1)                ///!< Operation timed out
#define CNET_ERR_NOT_IMPLEMENTED (CNET_CONFIG_ERR_BASE + 2)        ///!< Operation is not implemented
#define CNET_ERR_UNRECOGNIZED_INTERFACE (CNET_CONFIG_ERR_BASE + 3) ///!< Selected interface not recognized

#define CNET_ERROR_CHECK(x)                                                                                                      \
    do                                                                                                                           \
    {                                                                                                                            \
        int cnet_err = x;                                                                                                        \
        if (cnet_err != CNET_ERR_OK)                                                                                             \
        {                                                                                                                        \
            printf("FAIL: err 0x%x \nfile: \"%s\" line %d\nfunc: %s \nexpression: %s\n", __FILE__, __LINE__, __ASSERT_FUNC, #x); \
            return cnet_err;                                                                                                     \
        }                                                                                                                        \
    } while (0)

#endif //!__CNET_ERROR__H__