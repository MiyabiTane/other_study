#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
// #include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<sensor_msgs::msg::Image>("topic", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      // 画像の作成
      int i, j;
      std::vector<uint8_t> img_array(480 * 640 * 3, 0);
      for (i = 0; i < 480; i++) {
        if (i <= 160) {
          for (j = 0; j < 640; j = j + 3) img_array[i * 640 + j] = 255;
        } else if (i <= 320) {
          for (j = 0; j < 640; j = j + 3) img_array[i * 640 + j] = 255;
        } else {
          for (j = 0; j < 640; j = j + 3) img_array[i * 640 + j] = 255;
        }
      }
      auto message = sensor_msgs::msg::Image();
      message.height = 480;
      message.width = 640;
      message.encoding = "rgb8";
      message.is_bigendian = 0;
      message.step = 1920;
      message.data = img_array;
      RCLCPP_INFO(this->get_logger(), "Publishing: image");
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
