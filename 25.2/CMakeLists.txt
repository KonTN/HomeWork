cmake_minimum_required(VERSION 3.0.0)
project(phone_sim VERSION 0.1.0)

include(CTest)
enable_testing()
set(PR_DIR ${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
<<<<<<< HEAD
include(CPack)
=======
include(CPack)
>>>>>>> 26e9fd103b5b7ef9b8f9dfc0d3276a3c05aedb4d
