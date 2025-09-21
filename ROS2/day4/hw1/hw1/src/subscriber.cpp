#include "hw1/subscriber.h"
#include "rclcpp/rclcpp.hpp"

Subscriber::Subscriber(const std::string &node_name)
    : rclcpp::Node(node_name)
{
    rclcpp::QoS(rclcpp::KeepAll()).reliable().transient_local();
    data_ = this->create_subscription<std_msgs::msg::String>(
        "lifecycle_chatter", 10,
        std::bind(&Subscriber::data_callback, this, std::placeholders::_1));
    notification_ = this->create_subscription<lifecycle_msgs::msg::TransitionEvent>(
        "/publisher/transition_event",
        10,
        std::bind(&Subscriber::notification_callback, this, std::placeholders::_1));
}

void Subscriber::data_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), msg->data.c_str());
}
void Subscriber::notification_callback(const lifecycle_msgs::msg::TransitionEvent::SharedPtr msg)
{
    RCLCPP_INFO(
        get_logger(), "Transition from state %s to %s",
        msg->start_state.label.c_str(), msg->goal_state.label.c_str());
}

int main(int argc, char **argv)
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    auto subscriber = std::make_shared<Subscriber>("subscriber");
    rclcpp::spin(subscriber);
    rclcpp::shutdown();
    return 0;
}