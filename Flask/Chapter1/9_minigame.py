from cgi import FieldStorage
from urllib.parse import urlparse, parse_qs
from http.server import BaseHTTPRequestHandler, HTTPServer

with open('html/index10.html', mode='r', encoding="utf-8") as f:
    index = f.read()
with open('html/index11.html', mode='r', encoding="utf-8") as f:
    next = f.read()

routes = []

def route(path, method):
    routes.append((path, method))

route('/', 'index')
route('/index', 'index')

data = [
    ['それは人間のペットですか', 1, 2],
    ['それはニャーと鳴きますか', 'ネコ', 'イヌ'],
    ['それは食べると美味しいですか', 'うし', 'ライオン']
]

class HelloServerHandler(BaseHTTPRequestHandler):

    def do_GET(self):  # GET時に最初に呼び出される
        global routes
        a = 1
        print(type(a))
        _url = urlparse(self.path)
        for r in routes:
            if (r[0] == _url.path):
                eval('self.' + r[1] + '()')
                break
        else:
            self.error()
        return

    def index(self):
        self.send_response(200)
        self.end_headers()
        html = index.format(
            title='Animal', 
            message='質問に答えてね!',
            last=-1,
            animal='',
            yes=0,
            no=0,
        )
        self.wfile.write(html.encode('utf-8'))
        return

    def error(self):
        global routes
        self.send_error(404, "CANNOT ACCESS!!")
        return

    def do_POST(self):  # フォーム送信時に呼び出される
        _url = urlparse(self.path)
        if (_url.path == '/'):
            self.quiz()
        elif (_url.path == '/end'):
            self.end()
        return

    def quiz(self):
        form = FieldStorage(
            fp=self.rfile, 
            headers=self.headers,
            environ={'REQUEST_METHOD':'POST'})

        try:
            answer = int(form['answer'].value)
            if (answer == -1):
                html = index.format(
                    title='Animal', 
                    message='やった～!!',
                    last=-1,
                    animal='',
                    yes=0,
                    no=0,
                )
            elif (answer == -2):
                html = next.format(
                    title='Animal', 
                    message='うーん、答えを教えて。',
                    last=form['last'].value,
                    animal=form['animal'].value
                )
            else:
                html = index.format(
                    title='Animal', 
                    message=data[answer][0],
                    last=answer,
                    animal=form['answer'].value,
                    yes=data[answer][1],
                    no=data[answer][2],
                )
        except:
            html = index.format(
                title='Animal', 
                message='それは、' + form['answer'].value + 'ですか。',
                last=form['last'].value,
                animal=form['answer'].value,
                yes=-1,
                no=-2,
            )

        self.send_response(200)
        self.end_headers()
        self.wfile.write(html.encode('utf-8'))
        return

    def end(self):  # 新しいデータを追加する
        form = FieldStorage(
            fp=self.rfile, 
            headers=self.headers,
            environ={'REQUEST_METHOD':'POST'})
        animalname = form['animalname'].value
        question = form['question'].value
        last = int(form['last'].value)
        animal = form['animal'].value
        newdata = [question, animalname, animal]
        n = len(data)
        if (data[last][1] == animal):
            data[last][1] = n
        elif (data[last][2] == animal):
            data[last][2] = n

        data.append(newdata)

        html = index.format(
            title='Animal', 
            message='なるほど、わかりました！',
            last=-1,
            animal='',
            yes=0,
            no=0,
        )

        self.send_response(200)
        self.end_headers()
        self.wfile.write(html.encode('utf-8'))
        return
        
HTTPServer(('',8000), HelloServerHandler).serve_forever()
