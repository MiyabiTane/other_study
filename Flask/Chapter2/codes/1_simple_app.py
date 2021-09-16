from flask import Flask

app = Flask(__name__)

@app.route('/')  # デコレーター：rootにアクセスするとこの関数が呼ばれる
def hello_world():
    return 'Welcome!!'  # 表示するテキストをreturn

# 以下の記述を加えればpythonコマンドで実行可能になる
if __name__ == '__main__':
    app.debug = True
    app.run(host='localhost')