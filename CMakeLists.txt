cmake_minimum_required(VERSION 3.16.3)

project(kernel-sim)


set(
    SRC
    "src/utils.h"
    "src/defines.h"
    "src/clock.h"
    "src/core.h"
    "src/scheduler.h"
    "src/thread.h"
    "src/timer.h"
    "src/process.h"
    "src/machine.h"
    "src/main.c"
)

set(CMAKE_C_FLAGS "-pthread")


if(CMAKE_BUILD_TYPE STREQUAL "RELEASE")
    set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -Werror")
else()
    set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -ggdb")
endif()

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SRC})
else()
    add_executable(${PROJECT_NAME} ${SRC})
endif()