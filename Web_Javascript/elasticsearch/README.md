## Elasticsearch

今回は[この記事](https://qiita.com/kiyokiyo_kzsby/items/344fb2e9aead158a5545)を参考にしてDockerで動かす<br>
他参考記事：[触って学ぶElasticsearch](https://qiita.com/sakashin10291029/items/9a6ba5738a45577db481)、[初心者のためのElasticsearchその2 -いろいろな検索-](https://dev.classmethod.jp/articles/es-02/)、[公式ドキュメント](https://www.elastic.co/guide/en/elasticsearch/reference/current/index.html)

### 動かし方

Dockerイメージのビルド
```
$ docker-compose build
```

Dockerコンテナの起動
```
$ docker-compose up -d
```
http://localhost:9200にアクセスするとes01コンテナに接続でき、そこを介してes02にアクセスできるという仕組み

Dockerコンテナの停止
```
$ docker-compose down
```

### 基本処理

**index関連**

Indexの作成
```
$ curl -X PUT "localhost:9200/[index name]?pretty&pretty"
```

Indexのステータス確認
```
$ curl -X GET "localhost:9200/_cat/indices?v&pretty"
```

Indexの削除
```
$ curl -X DELETE "localhost:9200/[index name]?pretty&pretty"
```

**Document関連**

documentの作成
```
$ curl -X PUT "localhost:9200/[index_name]/_doc/1?pretty&pretty" -H 'Content-Type: application/json' -d'
{
  "[hoge]": "[fuga]"
}
'
```

Documentの取得
```
$ curl -X GET "localhost:9200/[index name]/_doc/[document id]?pretty&pretty"
```

Documentの更新
```
$ curl -X POST "localhost:9200/[index name]/_update/[document id]?pretty&pretty" -H 'Content-Type: application/json' -d [json data]
```

Documentの削除
```
$ curl -X DELETE "localhost:9200/[index name]/_doc/[document id]?pretty&pretty"
```

### 検索

[bank]Indexの作成
```
$ curl -X PUT 'localhost:9200/bank' -H 'Content-Type: application/json' -d'
{
    "settings" : {
        "index" : {
            "number_of_shards" : 5,
            "number_of_replicas" : 1
        }
    }
}
'
```

jsonファイルからデータを読み込み
```
$ curl -H "Content-Type: application/json" -X POST "localhost:9200/bank/_bulk?pretty&refresh" --data-binary "@accounts.json"
```

**検索の基本**

* query：検索の条件
* _source：取得するフィールド名
* from：取得開始位置
* size：取得件数
* sort：ソート条件

**match_all**

全てのドキュメントを返す
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "match_all": {} },
  "_source": ["account_number", "balance"],
  "from": 10,
  "size": 10,
  "sort": { "balance": { "order": "desc" } }
}
'
```

**match**

指定したフレーズが含まれているドキュメントを返す<br>
以下の例では"mill"または"lane"が含まれているドキュメントが返される
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "match":
                {"address": "mill lane"} }
}
'
```

**match_phrase**

指定したフレーズが含まれているドキュメントを返す<br>
以下の例では"mill lane"という文字列が含まれているドキュメントを返す
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "match_phrase":
                {"address": "mill lane"} }
}
'
```

**range**

指定した項目の値が`gte`以上`lte`以下のドキュメントを返す
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "range":
                {"age": {"gte": 20, "lte": 29}} }
}
'
```

**bool: must**

複数条件での検索にはboolを用いる。mustに書いた条件は必ず満たされる。
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "bool" : 
            { "must" : [
                { "match" : { "address" : "mill" } },
                { "range" : { "age" : { "gte" : 21, "lte" : 30 }}}
            ]} }
}
'
```

**bool: should**

shouldで指定した条件は必ずしも満たされなくても良いが、満たされるドキュメントが上位に出力される。
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "bool" : 
            { "should" : [
                { "match" : { "address" : "mill" } },
                { "range" : { "age" : { "gte" : 21, "lte" : 30 }}}
            ]} }
}
'
```

**bool: must_not**

must_notに書いた条件を満たすドキュメントは出力されない
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "bool" : 
            { "must_not" : [
                { "match" : { "address" : "mill" } },
                { "range" : { "age" : { "gte" : 21, "lte" : 30 }}}
            ]} }
}
'
```

**bool: filter**

mustの適合度を計算しないバージョン。単純なフィルタリングにはこっちの方が良い。
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": { "bool" : 
            { "filter" : [
                { "match" : { "address" : "mill" } },
                { "range" : { "age" : { "gte" : 21, "lte" : 30 }}}
            ]} }
}
'
```

**bool: must: exists**
指定したフィールドが存在するドキュメントのみを出力する
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": {
    "bool" : {
      "must" : {
        "exists" : { "field" : "city" }
      },
      "should" : {
        "range" : { "balance" : { "gte" : 30000 } } 
      }
    }
  }
}
'
```

**bool: must_not: exists**
指定したフィールドが存在しないドキュメントのみを出力する
```
$ curl -X GET "localhost:9200/bank/_search?pretty" -H 'Content-Type: application/json' -d'
{
  "query": {
    "bool" : {
      "must_not" : {
        "exists" : { "field" : "hello" }
      },
      "should" : {
        "range" : { "balance" : { "gte" : 30000 } } 
      }
    }
  }
}
'
```



