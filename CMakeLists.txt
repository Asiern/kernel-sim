cmake_minimum_required(VERSION 3.16.3)

project(kernel-sim)

set(CMAKE_C_FLAGS "-pthread")

if(CMAKE_BUILD_TYPE STREQUAL "RELEASE")
    set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -Werror")
else()
    set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -ggdb")
endif()

add_subdirectory(src)