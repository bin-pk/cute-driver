file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(common STATIC ${SRC_FILES})
target_include_directories(common PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../)