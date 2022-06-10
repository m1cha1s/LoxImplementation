cmake_minimum_required(VERSION 3.16)
project(Lox)

set(EXECUTABLE_SRC src/main.cpp)
set(LIBRARY_SRC src/lox.cpp)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "Building Lox as executable!")
    add_executable(${PROJECT_NAME}
        ${EXECUTABLE_SRC}
        ${LIBRARY_SRC}
    )
else()
    message(STATUS "Building Lox as library!")
    add_library(${PROJECT_NAME}
        ${LIBRARY_SRC}
    )
endif()

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)