cmake_minimum_required(VERSION 3.11)
project( hw1 )
find_package( OpenCV REQUIRED )
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include/hw1
)
add_executable( hw1 src/main.cpp )
target_link_libraries( hw1 ${OpenCV_LIBS} )
