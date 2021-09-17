from flask import Flask, render_template, request
import random

app = Flask(__name__)

@app.route('/', methods=['GET'])
def index():
    n = random.randrange(5, 10)
    data = []
    for n in range(n):
        data.append(random.randrange(0, 100))
    return render_template('index11.html',
            title="Template sample", message="合計を計算する： ", data=data)

@app.route('/next', methods=['GET'])
def next():
    return render_template('index10.html', title="Next page",
                            message='※これは別ページ用のサンプルです。',
                            data = ['One, Two, Three'])

@app.template_filter('sum')
def sum_filter(data):
    total = 0
    for item in data:
        total += item
    return total

@app.context_processor
def sample_processor():  #　引数のない関数を埋め込む
    def total(n):
        total = 0
        for i in range(n + 1):
            total += i
        return total
    return dict(total=total)

app.jinja_env.filters['sum'] = sum_filter

if __name__ == '__main__':
    app.debug = True
    app.run(host='localhost')
