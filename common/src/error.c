//
// Created by 박경빈 on 25. 1. 31.
//

#include "../include/error.h"
#include <string.h>

cute_driver_result cute_empty_ok() {
    cute_driver_result res;
    res.code = CUTE_EMPTY;
    res.len = 0;
    res.result.heap_data = NULL;

    return res;
}
cute_driver_result cute_stack_ok(u32 length, void* ptr) {
    cute_driver_result res;
    res.code = CUTE_STACK_OK;
    res.len = length;
    memcpy(res.result.stack_data, ptr, length);

    return res;
}
cute_driver_result cute_heap_ok(u32 length, void* ptr) {
    cute_driver_result res;
    res.code = CUTE_HEAP_OK;
    res.len = length;
    res.result.heap_data = ptr;
    return res;
}
cute_driver_result cute_internal_err(char* err_str) {
    size_t str_len = strlen(err_str);

    cute_driver_result res;
    res.code = CUTE_INTERNAL_ERROR;
    res.len = (str_len < CUTE_STACK_MAXIMUM) ? str_len : CUTE_STACK_MAXIMUM - 1;
    memcpy(res.result.stack_data, err_str, res.len);
    res.result.stack_data[res.len] = '\0';

    return res;
}
cute_driver_result cute_driver_err(char* err_str) {
    size_t str_len = strlen(err_str);

    cute_driver_result res;
    res.code = CUTE_DRIVER_ERROR;
    res.len = (str_len < CUTE_STACK_MAXIMUM) ? str_len : CUTE_STACK_MAXIMUM - 1;
    memcpy(res.result.stack_data, err_str, res.len);
    res.result.stack_data[res.len] = '\0';

    return res;
}