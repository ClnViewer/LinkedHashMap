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

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D__BUILD_HASHMAP=1")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__BUILD_HASHMAP=1")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

