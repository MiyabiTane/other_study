from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/', methods=['GET'])
def index():
    data = ['One', 'Two', 'Three']
    person = {'name' : 'Taro', 'mail' : 'taro@yamada'}
    # フィルターを用いると値を変えることなく処理を行うことができる
    return render_template('index8.html',
        title='Template sample', message='This is sample message.',
        data=data, person=person
    )

@app.route('/', methods=['POST'])
def form():
    field = request.form['field']
    return render_template('index2.html', title="Form",
                            message="こんにちは、%sさん！" % field)

if __name__ == '__main__':
    app.debug = True
    app.run(host='localhost')
