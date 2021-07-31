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

Docker内でrosbagファイルを使った操作を行う場合は、test.bagという名前で同ディレクトリ下に置いて、
Dockerfileの以下の箇所の```#```を消す。
```
# COPY test.bag /root/
```


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
$ catkin build -> colcon build
$ rosrun -> ros2 run
$ roscd [pkg] -> colcon_cd [pkg]
```

topic関連
```
$ rostopic list -> ros2 topic list
$ rostopic echo /topic_name -> ros2 topic echo /topic_name
$ rostopic info /topic_name -> ros2 topic info /topic_name
$ rosmsg show /msg_name -> ros2 msg show /msg_name
```

topicのpublish例
```
$ rostopic pub /topic_test example/msg/String "hello"
-> ros2 topic pub /topic_test example/msg/String '{data: hello}'
```

rosbag関連


<!-- 参考記事
https://qiita.com/porizou1/items/16ea8783f41fc5cac361
https://qiita.com/NeK/items/33d62c61fc1a8c0c233e
-->

<!-- ROS2でUSBカメラ
https://github.com/klintan/ros2_usb_camera
-->