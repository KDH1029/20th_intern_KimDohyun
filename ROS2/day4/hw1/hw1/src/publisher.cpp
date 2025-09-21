#include "hw1/publisher.h"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

Publisher::Publisher(const std::string &node_name)
    : rclcpp_lifecycle::LifecycleNode(node_name) {}

void Publisher::publish()
{
    static size_t count = 0;
    auto msg = std::make_unique<std_msgs::msg::String>();
    msg->data = std::to_string(count++);
    if (!publisher_->is_activated())
    {
        RCLCPP_INFO(
            get_logger(), "inactive");
    }
    else
    {
        RCLCPP_INFO(
            get_logger(), msg->data.c_str());
    }
    publisher_->publish(std::move(msg));
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
Publisher::on_configure(const rclcpp_lifecycle::State &)
{
    rclcpp::QoS(rclcpp::KeepAll()).reliable().transient_local();
    publisher_ = this->create_publisher<std_msgs::msg::String>("lifecycle_chatter", 10);
    timer_ = this->create_wall_timer(1s, std::bind(&Publisher::publish, this));
    RCLCPP_INFO(this->get_logger(), "configure");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
Publisher::on_activate(const rclcpp_lifecycle::State &)
{
    publisher_->on_activate();
    RCUTILS_LOG_INFO_NAMED(get_name(), "activate");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
Publisher::on_deactivate(const rclcpp_lifecycle::State &)
{
    publisher_->on_deactivate();
    RCUTILS_LOG_INFO_NAMED(get_name(), "deactivate");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
Publisher::on_cleanup(const rclcpp_lifecycle::State &)
{
    timer_.reset();
    publisher_.reset();
    RCUTILS_LOG_INFO_NAMED(get_name(), "cleanup");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
Publisher::on_shutdown(const rclcpp_lifecycle::State &)
{
    timer_.reset();
    publisher_.reset();
    RCUTILS_LOG_INFO_NAMED(get_name(), "shutdown");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::executors::SingleThreadedExecutor exe;
    std::shared_ptr<Publisher> lc_node =
        std::make_shared<Publisher>("publisher");
    exe.add_node(lc_node->get_node_base_interface());
    exe.spin();
    rclcpp::shutdown();
    return 0;
}