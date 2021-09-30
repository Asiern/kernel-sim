cmake_minimum_required(VERSION 3.21.2)

project(kernel-sim)

set(
    SRC
    src/clock.h
    src/core.h
    src/scheduler.h
    src/thread.h
    src/timer.h
    src/utils.h
    src/main.c
)

set(CMAKE_C_FLAGS "-pthread")

add_executable(${PROJECT_NAME} ${SRC})