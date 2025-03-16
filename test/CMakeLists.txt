cmake_minimum_required(VERSION 3.10)
project(ContourTest)

enable_testing()

set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/Arc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/Line.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/Contour.cpp
    contour_test.cpp
    )
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main pthread ${CONTOUR_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)
