cmake_minimum_required(VERSION 3.0.0)
project(27_1 VERSION 0.1.0)

include(CTest)
enable_testing()

set(PR_DIR ${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)