cmake_minimum_required(VERSION 3.2)
project(Contour)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(SOURCE_FILES
#     # src/Arc.cpp
#     # src/Contour.cpp
#     # src/Line.cpp
#     src/Segment.cpp
#     )

# add_library(COUNTOUR_LIB SHARED ${SOURCE_FILES})

add_executable(${PROJECT_NAME} src/main.cpp src/Segment.cpp) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# target_link_libraries(${PROJECT_NAME} PUBLIC ${COUNTOUR_LIB})
