cmake_minimum_required(VERSION 3.16.3)

project(kernel-sim)

set(CMAKE_C_FLAGS "-pthread -ansi")

# Compiler flags
if(UNIX AND NOT MACOS)
    if(${CMAKE_BUILD_TYPE} STREQUAL "RELEASE")
        message(STATUS "Using Release flags")
        set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -Werror")
    else()
        message(STATUS "Using Debug flags")
        set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -g")
        add_definitions(-DDEBUG)
    endif()
elseif(WIN32)
    message(WARNING "Windows config not found")
else()
    message(WARNING "MACOS config not found")
endif()

add_subdirectory(src)