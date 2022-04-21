cmake_minimum_required(VERSION 3.0.0)


add_executable(computer_sim 
               main.cpp
               cpu.cpp
               disk.cpp
               gpu.cpp 
               kbd.cpp 
               ram.cpp
               ${PR_DIR}/cpu.h 
               ${PR_DIR}/disk.h 
               ${PR_DIR}/gpu.h 
               ${PR_DIR}/kbd.h 
               ${PR_DIR}/ram.h)



target_include_directories(computer_sim PUBLIC ${PR_DIR})