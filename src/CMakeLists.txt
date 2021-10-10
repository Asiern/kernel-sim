include_directories(${PROJECT_SOURCE_DIR}/include)

set(
    SRC
    "main.c"
)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SRC})
else()
    add_executable(${PROJECT_NAME} ${SRC})
endif()