//
// Created by 박경빈 on 25. 1. 30.
//
#pragma once

#include "../common/include/type.h"
#include "../common/include/error.h"
#include "constants.h"
#include "input.h"
#include "output.h"

__BEGIN_DECLS
/*
 * 임베디드 영역의 요소들을 초기화 합니다.
 *
 * 이작업은 초기화 할 필요가 없는 경우 생략합니다.
 */
cute_driver_result init_driver();
/*
 * 임베디드 영역의 요소를 해제합니다.
 *
 * 초기화떄 사용했던 요소를 반환받아 수행이 가능합니다.
 */
void destroy_driver(cute_driver_result* self);

/*
 * driver 의 작업을 생성합니다.
 *
 * parameter 및 task 를 입력 받습니다.
 *
 * 이때 execute 의 결과는 create_driver_task 로 생긴 `result` 영역에 저장하기 바랍니다.
 */
cute_driver_result create_driver_task(u32 protocol,void* parameter);
/*
 * 생성한 작업을 실행합니다.
 *
 * 실행시 결과는 mut 한 parameter 를 이용하여 담아서 보내야 합니다.
 */
cute_driver_result execute_driver_task(u32 protocol,cute_driver_result* self);
/*
 * 생성한 작업 및 실행한 작업 물을 할당 해제 합니다.
 */
void destroy_driver_task(u32 protocol,cute_driver_result* self);

/*
 * driver 의 version 을 가져옵니다. 숫자 0 은 _ 와 같습니다.
 */
u32 get_driver_version();
__END_DECLS