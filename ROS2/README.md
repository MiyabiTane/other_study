## ROS2を動かす

### 環境構築（Docker）
1. [公式ページ](https://hub.docker.com/editions/community/docker-ce-desktop-mac)からDocker Desktop for Macをインストール。可能なら右上の歯車マーク▷Resources▷Memoryのバーを動かしてメモリを増やしておくと良い。

2. Dockerfileをおいたディレクトリ直下で以下のコマンドを叩く。

```
$ docker build --rm -t ros2:foxy .
```

imageファイルは[Dockerの公式ページ](https://hub.docker.com/_/ros)の
[foxy](https://github.com/osrf/docker_images/blob/df19ab7d5993d3b78a908362cdcd1479a8e78b35/ros/foxy/ubuntu/focal/ros-base/Dockerfile)
からとってきたものをベースに、[公式チュートリアルのInstallation](https://docs.ros.org/en/foxy/Installation/Ubuntu-Development-Setup.html)に従って内容を付け加えたものである。
実行するとROS2のコード類がビルドされた状態になる。ビルドにかなりの時間がかかるのと、11GB近くの容量を
必要とするため注意が必要。

3. TalkerとListenerを立ち上げて動作確認

先にListenerを立ち上げる
```
$ docker run --rm -it ros2:foxy
# ros2 run demo_nodes_cpp listener
```

別ターミナルでコンテナを起動してTalkerを立ち上げる
```
$ docker run --rm -it ros2:foxy
# ros2 run demo_nodes_cpp talker
```

### ROS2の使い方

#### コマンド（ROS -> ROS2）

ROSコマンド -> ROS2コマンドまとめ

よく使うもの
```
# catkin build -> colcon build
# rosrun -> ros2 run
# roscd [pkg] -> colcon_cd [pkg]
```

topic関連
```
# rostopic list -> ros2 topic list
# rostopic echo /topic_name -> ros2 topic echo /topic_name
# rostopic info /topic_name -> ros2 topic info /topic_name
# rosmsg show /msg_name -> ros2 msg show /msg_name
```

topicのpublish例
```
# rostopic pub /topic_test example/msg/String "hello"
-> ros2 topic pub /topic_test example/msg/String '{data: hello}'
```

画像データを取得するプログラム
```
// まず、型の存在と中身を確認
# ros2 pkg list | grep sensor
# colcon_cd sensor_msgs
# cd msg
# cat cat Image.msg
```

ターミナル1
```
$ docker run --rm -it ros2:foxy
# python3 ./pub_image.py
```

ターミナル2
```
$ docker run --rm -it ros2:foxy
# python3 ./sub_image.py
```


<!-- 参考記事
https://qiita.com/porizou1/items/16ea8783f41fc5cac361
https://qiita.com/NeK/items/33d62c61fc1a8c0c233e
-->

<!-- ROS2でUSBカメラ
https://github.com/klintan/ros2_usb_camera
https://www.slideshare.net/MasaruMorita/06-5157-ros2
-->

<!--
// 適当な画像をpublish
$ ros2 topic pub /cam/image_raw sensor_msgs/msg/Image '{height: 4, width: 4, data:[0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1]}'
-->

<!--
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image

std_msgs/Header header # Header timestamp should be acquisition time of image
                             # Header frame_id should be optical frame of camera
                             # origin of frame should be optical center of cameara
                             # +x should point to the right in the image
                             # +y should point down in the image
                             # +z should point into to plane of the image
                             # If the frame_id here and the frame_id of the CameraInfo
                             # message associated with the image conflict
                             # the behavior is undefined

uint32 height                # image height, that is, number of rows
uint32 width                 # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.ros.org and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.hpp

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)
-->
