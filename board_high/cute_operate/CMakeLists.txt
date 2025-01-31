if(WIN32)
    message(FATAL_ERROR "this system arch is window. do not use")
elseif (APPLE)
    add_compile_definitions(DAW)
    message(STATUS "this system arch is mac.")
else ()
    add_compile_definitions(POX)
    if (CMAKE_SYSTEM_PROCESSOR STREQUAL "i386" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "i686")
        message(STATUS "this system arch is amd32 bit")
        # 필요한 라이브러리 위치를 링크 걸기 등등 수행.
    elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "amd64")
        message(STATUS "this system arch is amd64 bit")
        # 필요한 라이브러리 위치를 링크 걸기 등등 수행.
    elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
        message(STATUS "this system arch is arm32 bit")
        # 필요한 라이브러리 위치를 링크 걸기 등등 수행.
    elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
        message(STATUS "this system arch is arm64 bit")
        # 필요한 라이브러리 위치 링크 걸기 등등 수행.
    else ()
        message(FATAL_ERROR "do not find arch")
    endif ()
endif ()

if (DEFINED OPER_TYPE)
else ()
    message("DO NOT DEFINED OPER_TYPE!!!")
    set(OPER_TYPE "V1" CACHE STRING "" FORCE)
endif ()

set_property(CACHE OPER_TYPE PROPERTY STRINGS "V1")

add_library(cute_operate STATIC src/cute_operate.c)
target_compile_definitions(cute_operate PUBLIC ${OPER_TYPE})
target_include_directories(cute_operate PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
target_link_libraries(cute_operate PRIVATE common board_low m)
add_dependencies(cute_operate board_low common)