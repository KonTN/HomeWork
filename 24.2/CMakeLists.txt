cmake_minimum_required(VERSION 3.0.0)
project(computer_sim VERSION 0.1.0)

include(CTest)


set(PR_DIR ${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
