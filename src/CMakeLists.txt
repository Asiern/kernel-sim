include_directories(${PROJECT_SOURCE_DIR}/include)

set(
    SRC
    "clock.c"
    "core.c"
    "cpu.c"
    "machine.c"
    "main.c"
    "procqueue.c"
    "thread.c"
    "process.c"
)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SRC})
else()
    add_executable(${PROJECT_NAME} ${SRC})
endif()