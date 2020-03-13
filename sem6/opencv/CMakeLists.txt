cmake_minimum_required(VERSION 3.16)
project(opencv)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

message( STATUS "Build type: ${CMAKE_BUILD_TYPE}" )
message( STATUS "Configuration types: ${CMAKE_CONFIGURATION_TYPES}" )

#set(OpenCV_INCLUDE_DIRS "/usr/include/opencv4/opencv2/")
#set(OpenCV_LIBS "/usr/lib/")
find_package(OpenCV 4 REQUIRED)

include_directories(opencv PUBLIC include)

#set(SOURCES src/main.cpp)
file(GLOB SOURCES
        include/*.h
        src/*.cpp
        )
add_executable(opencv ${SOURCES})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(opencv ${OpenCV_LIBS})
configure_file(include/donov.jpg donov.jpg COPYONLY)