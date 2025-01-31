file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_subdirectory(cute_operate)

add_library(board_high STATIC ${SRC_FILES})

target_compile_definitions(board_high PUBLIC ${OPER_TYPE})
target_include_directories(board_high PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../)
# 항상 math library 를 링크 걸어줌.
target_link_libraries(board_high PRIVATE common board_low cute_operate m)
add_dependencies(board_high common board_low cute_operate)