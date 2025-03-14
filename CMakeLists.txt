cmake_minimum_required(VERSION 3.2)
project(Contour)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES
    src/Contour.cpp
    src/Segment.cpp
    )

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCE_FILES}) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

