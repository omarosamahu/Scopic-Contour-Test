cmake_minimum_required(VERSION 3.2)
project(Contour)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES
    src/Arc.cpp
    src/Line.cpp
    src/Contour.cpp
    )

add_library(CONTOUR_LIB SHARED ${SOURCE_FILES})

target_include_directories(CONTOUR_LIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(${PROJECT_NAME} src/main.cpp) 

target_link_libraries(${PROJECT_NAME} PUBLIC CONTOUR_LIB)

install(TARGETS CONTOUR_LIB
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib    
    RUNTIME DESTINATION bin
)

install(DIRECTORY inc/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

