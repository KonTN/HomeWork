cmake_minimum_required(VERSION 3.0.0)


add_executable(${PROJECT_NAME}
               main.cpp
               shapes.cpp
               )


target_include_directories(${PROJECT_NAME} PUBLIC ${PR_DIR})