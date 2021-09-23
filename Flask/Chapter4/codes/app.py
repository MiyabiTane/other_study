from flask import Flask, render_template
from flask import Flask, render_template, request, session, redirect, jsonify

app = Flask(__name__)


@app.route('/', methods=['GET'])
def index():
    return render_template('index15_ajax.html', title='Index', message='※Vue.js')

@app.route('/index4', methods=['GET'])
def index2():
    return render_template('index4_pass_data.html',
                            title='Index', message='※Vue.js', data="['one', 'two', 'three']")

@app.route('/ajax/<id>', methods=['GET'])
def ajax(id):
    data = {
        1: {'id':1, 'name':'Taro', 'mail': 'taro@yamada'},
        2: {'id':2, 'name':'Hanako', 'mail':'hanako@flower'},
        3: {'id':3, 'name':'Sachiko', 'mail':'sachiko@happy'}
    }
    n = int(id)
    if n < 1:
        n = 1
    if n > len(data):
        n = 3
    return jsonify(data[n])


if __name__ == '__main__':
    app.debug = True
    app.run(host='localhost')
