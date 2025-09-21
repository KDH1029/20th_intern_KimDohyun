cmake_minimum_required(VERSION 3.8)
project(hw1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(std_msgs REQUIRED)
find_package(lifecycle_msgs REQUIRED)

include_directories(include)

add_executable(publisher src/publisher.cpp)
ament_target_dependencies(publisher
  rclcpp
  rclcpp_lifecycle
  std_msgs
)

add_executable(subscriber src/subscriber.cpp)
ament_target_dependencies(subscriber
  rclcpp
  lifecycle_msgs
  std_msgs
)

install(TARGETS
  publisher
  subscriber
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

ament_package()