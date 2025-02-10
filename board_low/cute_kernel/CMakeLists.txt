if(WIN32)
    add_compile_definitions(WIN)
    message(STATUS "this system arch is window.")
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

if (DEFINED KERNEL_TYPE)
else ()
    message("DO NOT DEFINED KERNEL_TYPE!!!")
    set(KERNEL_TYPE "TK" CACHE STRING "" FORCE)
endif ()

set_property(CACHE KERNEL_TYPE PROPERTY STRINGS "TK")

add_library(cute_kernel STATIC src/cute_kernel.c)
target_compile_definitions(cute_kernel PUBLIC ${KERNEL_TYPE})
target_include_directories(cute_kernel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
target_link_libraries(cute_kernel PRIVATE common m)
add_dependencies(cute_kernel common)