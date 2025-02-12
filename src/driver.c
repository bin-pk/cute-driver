//
// Created by 박경빈 on 25. 1. 30.
//

#include "include/driver.h"
#include "board_high/include/board_high.h"

cute_driver_result init_driver() {
    return init_board_high();
}

cute_driver_result create_driver_task(u32 protocol,void* parameter) {
    if(protocol == 0) {
        return create_echo_task(parameter);
    } else {
        return cute_internal_err("알수 없는 protocol");
    }
}

cute_driver_result execute_driver_task(u32 protocol,cute_driver_result* self) {
    if(protocol == 0) {
        return execute_echo_task(self);
    } else {
        return cute_internal_err("알수 없는 protocol");
    }
}

u32 get_driver_version() {
    return LAST_VERSION;
}