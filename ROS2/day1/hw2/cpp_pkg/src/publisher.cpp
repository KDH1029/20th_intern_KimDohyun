#include "publisher.hpp"

Publisher::Publisher() : Node("publisher")
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
}
void Publisher::publish()
{
    std_msgs::msg::String message;
    std::getline(std::cin, message.data);
    publisher_->publish(message);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    std::shared_ptr<Publisher> node = std::make_shared<Publisher>();
    while (rclcpp::ok())
    {
        node->publish();
    }
    rclcpp::shutdown();
    return 0;
}