//
// Created by 박경빈 on 25. 1. 31.
//

# pragma once
#include "common/include/common.h"
#include "input.h"
#include "output.h"

cute_driver_result create_echo_task(void *parameter);
cute_driver_result execute_echo_task(cute_driver_result* self);
void destroy_echo_task(cute_driver_result* self);

char* get_board_high_name();