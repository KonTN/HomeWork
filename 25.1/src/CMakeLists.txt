cmake_minimum_required(VERSION 3.0.0)


add_executable(player_sim 
               main.cpp
               player.cpp 
               track.cpp
               )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tracks.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(player_sim PUBLIC ${PR_DIR})