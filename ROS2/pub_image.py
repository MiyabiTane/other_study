import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image


class ImagePublisher(Node):

    def __init__(self):
        super().__init__('image_publisher')
        self.publisher_ = self.create_publisher(Image, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        # make imagee
        image_array = []
        for i in range(480):
            if i <= 160:
                image_array += [255, 0, 0] * 640
            elif i <= 320:
                image_array += [0, 255, 0] * 640
            else:
                image_array += [0, 0, 255] * 640
        self.image_array = image_array

    def timer_callback(self):
        msg = Image()
        msg.height = 480
        msg.width = 640
        msg.encoding = "rgb8"
        msg.is_bigendian = 0
        msg.step = 1920
        msg.data = self.image_array
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing image of len: "%s"' % str(len(msg.data)))


def main(args=None):
    rclpy.init(args=args)

    image_publisher = ImagePublisher()

    rclpy.spin(image_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    image_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
