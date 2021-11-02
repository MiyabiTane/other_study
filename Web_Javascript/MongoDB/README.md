## Node.jsからMongoDBのデータを触る

参考記事：[【入門】Node.jsでMongoDBに値を書き込むハンズオン](https://www.mtioutput.com/entry/node-js-handson1)、[Node.jsでMongoDBを使用する方法](https://www.tech-wiki.online/jp/node-mongodb.html)<br>
[Docker: DockerfileでExpectスクリプトを使うと複雑になる例](https://www.hiroom2.com/2017/02/24/docker-dockerfile%E3%81%A7expect%E3%82%B9%E3%82%AF%E3%83%AA%E3%83%97%E3%83%88%E3%82%92%E4%BD%BF%E3%81%86%E3%81%A8%E8%A4%87%E9%9B%91%E3%81%AB%E3%81%AA%E3%82%8B%E4%BE%8B/)、[Ubuntuにnpmが入らないときの解決法](https://kataware.hatenablog.jp/entry/2017/06/27/125618)

### 動かし方

Dockerfileのビルド
```
$ docker build --rm -t node_mongo .
```

コンテナの立ち上げ
```
$ docker run --rm -it node_mongo
```

mongodbの起動
```
$ service mongodb start
```

スクリプトの実行
```
$ node operate_data.js
```
