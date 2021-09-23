## Webアプリ/Flask

Flaskで学ぶWebアプリケーションのしくみとつくり方(掌田津耶乃[著])を使って勉強

* Chapter1: HTTPServer

    実行の仕方の一例
    ```
    $ cd Chaper1
    $ pipenv sync
    $ pipenv run pyton 9_minigame.py
    http://localhost:8000 にアクセスする
    ```

* Chapter2: Flask

    実行の仕方の一例
    ```
    $ cd Chapter2
    $ pipenv sync
    $ pipenv shell
    $ export FLASK_APP=codes/1_simple_app.py
    $ flask run
    ```
    http://localhost:5000/ にアクセスする

    Pipfileと同ディレクトリ下にコードを置いてしまうとexportできないので注意する。

* Chapter4: Vue.js

    実行の仕方の一例
    ```
    $ cd Chapter4
    $ pipenv sync
    $ pipenv run python app.py
    ```
    http://localhost:5000/ にアクセスする
