//
// Created by 박경빈 on 25. 1. 31.
//
#ifdef DAW
#include "board_low/cute_kernel/src/mac/mac_kernel.c"
#elif POX
#ifdef TK
#include "board_low/cute_kernel/src/test/test_kernel.c"
#endif
#endif
