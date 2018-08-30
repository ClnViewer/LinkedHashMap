cmake_minimum_required(VERSION 3.3)
project(TestLinkHasMap)
enable_language(C)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

set(app_srcs
    ${CMAKE_CURRENT_SOURCE_DIR}/../test/main.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/hashmap-link-hash.c
)

add_executable( TestLinkHasMap ${app_srcs} )

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

