include_directories(${PROJECT_SOURCE_DIR}/include)

set(
    SRC
    "clock.c"
    "machine.c"
    "main.c"
    "process.c"
    "scheduler.c"
    "timer.c"
    "utils.c"
)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SRC})
else()
    add_executable(${PROJECT_NAME} ${SRC})
endif()