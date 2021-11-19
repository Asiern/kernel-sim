include_directories(${PROJECT_SOURCE_DIR}/include)

set(
    SRC
    "clock.c"
    "machine.c"
    "main.c"
    "process.c"
    "utils.c"
    "timer.c"
    "scheduler.c"
)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SRC})
else()
    add_executable(${PROJECT_NAME} ${SRC})
endif()