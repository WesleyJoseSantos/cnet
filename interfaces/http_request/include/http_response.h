/**
 * @file http_response.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __HTTP_RESPONSE__H__
#define __HTTP_RESPONSE__H__

typedef struct http_response
{
    int status_code;
    char content[1023];
} http_response_t;

#endif  //!__HTTP_RESPONSE__H__