cmake_minimum_required(VERSION 3.0.0)




add_executable(
    phone_sim
    main.cpp
    phone.cpp
    contact.cpp
)

target_include_directories(phone_sim PUBLIC ${PR_DIR})