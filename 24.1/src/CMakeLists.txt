cmake_minimum_required(VERSION 3.0.0)




add_executable(surgeon_sim main.cpp instruments.cpp ${PR_DIR}/instruments.h)
target_include_directories(surgeon_sim PUBLIC ${PR_DIR})
