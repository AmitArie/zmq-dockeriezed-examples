
cmake_minimum_required(VERSION 3.10)
project(zmq VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEBUG)
        set(COMPILE_FLAGS "-Wall -Werror -g -ggdb3 -gdwarf-2  -O0  -pthread")
else(DEBUG)
        set(COMPILE_FLAGS "-Wall -Werror -O3  -pthread")
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

add_subdirectory(pub)
add_subdirectory(sub)