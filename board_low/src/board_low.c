//
// Created by 박경빈 on 25. 1. 31.
//
#include "board_low/cute_kernel/include/cute_kernel.h"
#include "board_low/include/board_low.h"

cute_driver_result init_board() {
    return cute_empty_ok();
}
void destroy_board(cute_driver_result* self) {
    if (self == NULL) {
        return;
    }

    // heap 영역에 데이터가 있을 경우 메모리 해제
    if (self->code == CUTE_HEAP_OK && self->result.heap_data != NULL) {
        free(self->result.heap_data);
        self->result.heap_data = NULL;
    }

    // 구조체 초기화 (안전성 확보)
    self->code = CUTE_EMPTY;
    self->len = 0;
}

char* get_board_low_name() {
    return get_kernel_name();
}