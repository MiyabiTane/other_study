from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/', methods=['GET'])
def index():
    flg = False
    data = ['Windows', 'MacOS', 'Linux', 'ChromeOS']
    return render_template('index5.html', title="Form sample", message=data, data=data)

@app.route('/', methods=['POST'])
def form():
    field = request.form['field']
    return render_template('index2.html', title="Form",
                            message="こんにちは、%sさん！" % field)

if __name__ == '__main__':
    app.debug = True
    app.run(host='localhost')
