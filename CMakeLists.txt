cmake_minimum_required(VERSION 2.8)

project(median)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

SET (SRCS src/medianstructure.cpp)

include(cmake/FindCppUnit.cmake)
include(cmake/CMakeIntegrateCPPUnit.cmake)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -fvar-tracking")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -fvar-tracking")

include_directories(include)

add_executable(${PROJECT_NAME} src/main.cpp "${SRCS}")
