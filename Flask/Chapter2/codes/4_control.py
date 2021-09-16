from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/', methods=['GET'])
def index():
    return render_template('index3.html', title="Form sample",
                            message="選択して下さい")

@app.route('/', methods=['POST'])
def form():
    ck = request.form.get('check')  # 空の場合、Noneを返す
    rd = request.form.get('radio')
    sel = request.form.getlist('sel')
    return render_template('index3.html', title="Form sample",
                            message=[ck, rd, sel])

if __name__ == '__main__':
    app.debug = True
    app.run(host='localhost')
