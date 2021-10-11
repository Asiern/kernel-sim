cmake_minimum_required(VERSION 3.16.3)

project(kernel-sim)

set(CMAKE_C_FLAGS "-pthread")

# Compiler flags
if(UNIX AND NOT MACOS)
    if(${CMAKE_BUILD_TYPE} STREQUAL "RELEASE")
        message(STATUS "Using Release flags")
        set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -Werror")
    else()
        message(STATUS "Using Debug flags")
        set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -ggdb")
    endif()
elseif(WIN32)
    message(WARNING "Windows config found")
else()
    message(WARNING "MACOS config found")
endif()

add_subdirectory(src)