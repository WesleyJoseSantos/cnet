/**
 * @file dto_helpers.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __DTO_HELPERS__H__
#define __DTO_HELPERS__H__

#include "modules/cJSON/cJSON.h"

#define DTO_FROM_JSON_INIT() memset(ptr, 0, sizeof(*ptr))
#define DTO_FROM_JSON_NUMBER_DEFAULT(x, val) ptr->x = val
#define DTO_FROM_JSON_PARAMETERS(type_t) type_t *ptr, cJSON *json
#define DTO_FROM_JSON_END() cJSON_Delete(json)
#define DTO_TO_JSON_INIT() cJSON *json = cJSON_CreateObject()
#define DTO_TO_JSON_END() return json
#define DTO_TO_JSON_PARAMETERS(type_t) type_t *ptr

#define DTO_FROM_JSON_BOOLEAN(x)                                \
    cJSON *x = cJSON_GetObjectItem(json, #x);                   \
    if (x && (x->type == cJSON_False || x->type == cJSON_True)) \
    ptr->x = x->valueint

#define DTO_FROM_JSON_NUMBER(x)               \
    cJSON *x = cJSON_GetObjectItem(json, #x); \
    if (x && x->type == cJSON_Number)         \
    ptr->x = x->valueint

#define DTO_FROM_JSON_CHAR_ARRAY(x)                                \
    cJSON *x = cJSON_GetObjectItem(json, #x);                      \
    if (x && x->type == cJSON_String && x->valuestring[0] != '\0') \
    strncpy((char *)ptr->x, x->valuestring, sizeof(ptr->x))

#define DTO_FROM_JSON_STRING(x)                                    \
    cJSON *x = cJSON_GetObjectItem(json, #x);                      \
    if (x && x->type == cJSON_String && x->valuestring[0] != '\0') \
    {                                                              \
        ptr->x = malloc(strlen(x->valuestring) + 1);               \
        strcpy((char *)ptr->x, x->valuestring);                    \
    }

#define DTO_FROM_JSON_IP_INFO(x)                                   \
    cJSON *x = cJSON_GetObjectItem(json, #x);                      \
    if (x && x->type == cJSON_String && x->valuestring[0] != '\0') \
    ptr->ip_info.x.addr = ipaddr_addr(x->valuestring)

#define DTO_FROM_JSON_DNS_INFO(x)                                  \
    cJSON *x = cJSON_GetObjectItem(json, #x);                      \
    if (x && x->type == cJSON_String && x->valuestring[0] != '\0') \
    ptr->dns_info.ip.u_addr.ip4.addr = ipaddr_addr(x->valuestring)

#define DTO_FROM_JSON_IP(x)                                        \
    cJSON *x = cJSON_GetObjectItem(json, #x);                      \
    if (x && x->type == cJSON_String && x->valuestring[0] != '\0') \
    ptr->x.u_addr.ip4.addr = ipaddr_addr(x->valuestring)

#define DTO_TO_JSON_BOOLEAN(x) cJSON_AddBoolToObject(json, #x, ptr->x)

#define DTO_TO_JSON_NUMBER(x) cJSON_AddNumberToObject(json, #x, ptr->x)

#define DTO_TO_JSON_CHAR_ARRAY(x) cJSON_AddStringToObject(json, #x, (char *)ptr->x)

#define DTO_TO_JSON_STRING(x) DTO_TO_JSON_CHAR_ARRAY(x)

#define DTO_TO_JSON_HEX_ARRAY(x)                  \
    char x[(sizeof(ptr->x) * 2) + 1];             \
    int len = 0;                                  \
    for (size_t i = 0; i < sizeof(ptr->x); i++)   \
    {                                             \
        len += sprintf(&x[len], "%X", ptr->x[i]); \
    }                                             \
    x[len] = '\0';                                \
    cJSON_AddStringToObject(json, #x, x);

#define DTO_TO_JSON_IP_INFO(x)                  \
    char x[16];                                 \
    sprintf(x, IPSTR, IP2STR(&ptr->ip_info.x)); \
    if (x[0] != '\0')                           \
    cJSON_AddStringToObject(json, #x, x)

#define DTO_TO_JSON_DNS_INFO(x)                              \
    char x[16];                                              \
    sprintf(x, IPSTR, IP2STR(&ptr->dns_info.ip.u_addr.ip4)); \
    if (x[0] != '\0')                                        \
    cJSON_AddStringToObject(json, #x, x)

#define DTO_TO_JSON_IP(x)                          \
    char x[16];                                    \
    sprintf(x, IPSTR, IP2STR(&ptr->x.u_addr.ip4)); \
    if (x[0] != '\0')                              \
    cJSON_AddStringToObject(json, #x, x)

#define DTO_FROM_JSON_OBJ(obj)                    \
    cJSON *obj = cJSON_GetObjectItem(json, #obj); \
    obj##from_json(&ptr->obj, obj)

#define DTO_TO_JSON_OBJ(obj)               \
    cJSON *obj = obj##_to_json(&ptr->obj); \
    cJSON_AddItemToObject(json, #obj, obj)

#define DTO_TO_JSON_OBJ_ARRAY(obj)                \
    cJSON *array = cJSON_CreateArray();           \
    for (size_t i = 0; i < ptr->obj##_count; i++) \
    {                                             \
        cJSON *obj = obj##_to_json(&ptr->obj);    \
        cJSON_AddItemToArray(array, obj);         \
    }                                             \
    cJSON_AddArrayToObject(array, #obj)

#define DTO_FROM_JSON_OBJ_TO_STR(obj)             \
    cJSON *obj = cJSON_GetObjectItem(json, #obj); \
    char *str = cJSON_PrintUnformatted(obj);      \
    sprintf(ptr->obj, str);                       \
    free(str)

#define DTO_FROM_JSON_OBJ_ARRAY(obj) DTO_FROM_JSON_OBJ_TO_STR(obj)   

int cJSON_ToString(char *str, cJSON *obj)
{
    char *buf = cJSON_PrintUnformatted(obj);
    int len = sprintf(str, buf);
    free(buf);
    return len;
}

#endif //!__DTO_HELPERS__H__