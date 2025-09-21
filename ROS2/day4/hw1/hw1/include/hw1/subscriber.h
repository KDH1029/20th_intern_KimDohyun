#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "lifecycle_msgs/msg/transition_event.hpp"

class Subscriber : public rclcpp::Node
{
public:
    Subscriber(const std::string &node_name);
    void data_callback(const std_msgs::msg::String::SharedPtr msg);
    void notification_callback(const lifecycle_msgs::msg::TransitionEvent::SharedPtr msg);

private:
    std::shared_ptr<rclcpp::Subscription<std_msgs::msg::String>> data_;
    std::shared_ptr<rclcpp::Subscription<lifecycle_msgs::msg::TransitionEvent>> notification_;
};