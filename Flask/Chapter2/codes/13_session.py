from flask import Flask, render_template, request, session, url_for, redirect
from flask.views import MethodView

app = Flask(__name__)

@app.route('/', methods=['GET'])
def index():
    n = random.randrange(5, 10)
    data = []
    for n in range(n):
        data.append(random.randrange(0, 100))
    return render_template('index11.html',
            title="Template sample", message="合計を計算する： ", data=data)

@app.context_processor
def sample_processor():  #　引数のない関数を埋め込む
    def total(n):
        total = 0
        for i in range(n + 1):
            total += i
        return total
    return dict(total=total)

# secret_keyにランダムなbyte文字列を設定する
app.secret_key = b'random string ...'

class HelloAPI(MethodView):
    send = ''

    def get(self):
        # セッション: クライアント毎に値を管理する
        if 'send' in session:
            msg = 'send: ' + session['send']
            send = session['send']
        else:
            msg = "何か書いて下さい。"
            send = ''
        return render_template('index12.html', title='Next Page',
                                message=msg, send=send)
    
    def post(self):
        session['send'] = request.form['send']
        return redirect('/hello/')

app.add_url_rule('/hello/', view_func=HelloAPI.as_view('hello'))


if __name__ == '__main__':
    app.debug = True
    app.run(host='localhost')
