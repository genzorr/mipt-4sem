cmake_minimum_required(VERSION 3.16)
project(Collision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(Collision PUBLIC include)
file(GLOB SOURCES
        include/*.h
        src/*.cpp
        )
add_executable(Collision ${SOURCES})

target_link_libraries(Collision sfml-graphics sfml-window sfml-system)
