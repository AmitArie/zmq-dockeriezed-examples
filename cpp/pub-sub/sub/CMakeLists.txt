
cmake_minimum_required(VERSION 3.10)
project(zmq VERSION 0.1 LANGUAGES CXX)

add_executable(pub_sub_subscriber
        main.cpp
)

target_link_libraries(pub_sub_subscriber
        zmq
)
