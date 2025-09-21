#include <functional>
#include <memory>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Subscriber : public rclcpp::Node
{
public:
    Subscriber();

private:
    void topic_callback(const std_msgs::msg::String &msg) const;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};