#include <memory>
#include <string>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Publisher : public rclcpp::Node
{
public:
    Publisher();
    void publish();

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};