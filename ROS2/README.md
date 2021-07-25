## ROS2を動かす

### 環境構築（Docker）
1. [公式ページ](https://hub.docker.com/editions/community/docker-ce-desktop-mac)からDocker Desktop for Macをインストール。可能なら右上の歯車マーク▷Resources▷Memoryのバーを動かしてメモリを増やしておくと良い。

2. Dockerfileをおいたディレクトリ直下で以下のコマンドを叩く。
```
$ docker build --rm -t ros2:dashing .
```

3. TalkerとListenerを立ち上げて動作確認

先にListenerを立ち上げる
```
$ docker run --rm -it ros2:dashing
# ros2 run demo_nodes_cpp listener
```

別ターミナルでコンテナを起動してTalkerを立ち上げる
```
$ docker run --rm -it ros2:dashing
# ros2 run demo_nodes_cpp talker
```

<!-- 参考記事
https://tshell.hatenablog.com/entry/2020/02/13/174414
https://qiita.com/NeK/items/33d62c61fc1a8c0c233e
-->