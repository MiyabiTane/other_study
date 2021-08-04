#include <memory>

#include "rclcpp/rclcpp.hpp"
// #include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>
#include "cv_bridge/cv_bridge.h"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

    }

  private:
    void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: image");
      cv_bridge::CvImagePtr cv_ptr;
      cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
      // std::cout << typeid(cv_ptr).name() << std::endl;
      // std::cout << cv_ptr->image << std::endl;
      // https://github.com/ros-perception/vision_opencv/blob/ros2/cv_bridge/include/cv_bridge/cv_bridge.h
      cv::imwrite("output2.jpg", cv_ptr->image);
    }
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
