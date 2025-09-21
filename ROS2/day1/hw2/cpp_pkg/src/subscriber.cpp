#include "subscriber.hpp"

Subscriber::Subscriber() : Node("subscriber")
{
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10,
        [this](const std_msgs::msg::String &msg)
        {
            topic_callback(msg);
        });
}

void Subscriber::topic_callback(const std_msgs::msg::String &msg) const
{
    std::cout << msg.data.c_str() << std::endl;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}