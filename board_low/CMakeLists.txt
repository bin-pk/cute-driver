add_subdirectory(cute_kernel)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_library(board_low STATIC ${SRC_FILES})

target_compile_definitions(board_low PUBLIC ${KERNEL_TYPE})
target_include_directories(board_low PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../)
# 항상 math library 를 링크 걸어줌.
target_link_libraries(board_low PRIVATE common cute_kernel m)
add_dependencies(board_low common cute_kernel)