//
// Created by 박경빈 on 25. 1. 31.
//
#include "board_low/include/board_low.h"
#include "board_high/cute_operate/include/cute_operate.h"
#include "board_high/include/board_high.h"


typedef struct {
    i32 count;
} echo_context;

/*
 * 입력으로 들어오는 것은 NULL 임. 신경 안써도 됨.
 */
cute_driver_result create_echo_task(void *parameter) {
    echo_context ctx;
    ctx.count = 0;

    cute_driver_result res;
    res.code = CUTE_STACK_OK;
    res.len = sizeof(echo_context);
    memcpy(res.result.stack_data, &ctx,sizeof(echo_context));
    return res;
}

/*
 * execute 를 동작 요청하면 create 에서 생성한 `echo_context` 의 count 값을 증가시킴.
 *
 * code 가 맞지 않는 경우이거나 길이가 맞지 않는 경우 error 반환.
 *
 * 그 외에는 잘못된 것을 넣어도 제작자의 책임을 물어야함.
 */

cute_driver_result execute_echo_task(cute_driver_result* self) {
    if(self->code != CUTE_STACK_OK) {
        return cute_internal_err("결과 code 가 올바르지 않습니다.");
    }

    if(self->len != sizeof(echo_context)) {
        return cute_internal_err("요구했던 데이터의 길이와 일치하지 않습니다.");
    }

    echo_context* ctx = (echo_context*)self->result.stack_data;
    ctx->count += 1;

    echo_output output;
    output.count = ctx->count;

    cute_driver_result res;
    res.code = CUTE_STACK_OK;
    res.len = sizeof(echo_output);
    memcpy(res.result.stack_data, &output, sizeof(echo_output));
    return res;
}

/*
 * 동작 할당 요소가 없기에 해제하지 아니함.
 */
void destroy_echo_task(cute_driver_result* self) {
    if (self == NULL) {
        return;
    }
}

char* get_board_high_name() {
    return get_operation_name();
}