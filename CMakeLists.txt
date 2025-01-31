cmake_minimum_required(VERSION 3.30)
project(cute_driver C)

set(CMAKE_C_STANDARD 11)

if (DEFINED KERNEL_TYPE)
    message("DEFINED KERNEL_TYPE : " ${KERNEL_TYPE})
else ()
    set(KERNEL_TYPE "TK" CACHE STRING "")
endif()

set_property(CACHE KERNEL_TYPE PROPERTY STRINGS "TK")

if(KERNEL_TYPE STREQUAL "TK")
    message("TK kernel selected!!!")
    set(KERNEL_TYPE "TK" CACHE STRING "")
    add_definitions(-DTK)
else ()
    message(FATAL_ERROR "Invalid KERNEL_TYPE!!!")
endif ()

if (DEFINED OPER_TYPE)
    message("DEFINED OPER_TYPE : " ${OPER_TYPE})
else ()
    set(OPER_TYPE "V1" CACHE STRING "")
endif()

set_property(CACHE OPER_TYPE PROPERTY STRINGS "V1")

if(OPER_TYPE STREQUAL "V1")
    message("V1 operation selected!!!")
    set(OPER_TYPE "V1" CACHE STRING "")
    add_definitions(-DV1)
else ()
    message(FATAL_ERROR "Invalid OPER_TYPE!!!")
endif ()

add_subdirectory(common)
add_subdirectory(board_low)
add_subdirectory(board_high)

set(TARGET_NAME ${PROJECT_NAME})

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/shared)

add_library(${TARGET_NAME}_shared SHARED ${SRC_FILES})
add_library(${TARGET_NAME}_static STATIC ${SRC_FILES})

target_include_directories(${TARGET_NAME}_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${TARGET_NAME}_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    message(FATAL_ERROR "MSVC is not supported")
else ()
    set_target_properties(${TARGET_NAME}_shared PROPERTIES OUTPUT_NAME ${TARGET_NAME})
    set_target_properties(${TARGET_NAME}_static PROPERTIES OUTPUT_NAME ${TARGET_NAME})
endif ()

if (USE_CUSTOM_ALLOCATOR)
    target_compile_definitions(${TARGET_NAME}_shared PRIVATE USE_CUSTOM_ALLOCATOR)
    target_compile_definitions(${TARGET_NAME}_static PRIVATE USE_CUSTOM_ALLOCATOR)
endif ()

target_link_libraries(${TARGET_NAME}_shared PRIVATE common board_low board_high)
target_link_libraries(${TARGET_NAME}_static PRIVATE common board_low board_high)