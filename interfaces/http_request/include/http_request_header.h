/**
 * @file http_request_header.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __HTTP_REQUEST_HEADER__H__
#define __HTTP_REQUEST_HEADER__H__

/**
 * @brief HTTP Request header
 *
 */
typedef struct http_request_header
{
    char *name;  ///!< Header name
    char *value; ///!< Header value
} http_request_header_t;

#endif  //!__HTTP_REQUEST_HEADER__H__