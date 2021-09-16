from urllib.parse import urlparse, parse_qs
from cgi import FieldStorage
from http.server import BaseHTTPRequestHandler, HTTPServer

#htmlファイルの読み込み
with open('html/index7.html', mode='r') as f:
    index = f.read()
with open('html/index4.html', mode='r') as f:
    nxt = f.read()


routes = []  # global
def route(path, method):
    routes.append((path, method))
# add route setting
route('/', 'index')
route('/index', 'index')
route('/next', 'next')
route('/xml', 'xml')


class HelloServerHandler(BaseHTTPRequestHandler):

    def do_GET(self):  # 最初から用意されている関数
        _url = urlparse(self.path)
        for url, func in routes:
            if url == _url.path:
                eval('self.' + func + '()')  # 文字列をpythonのコードとして実行
                break
        else:
            self.error()
        return

    def do_POST(self):
        form = FieldStorage(
            fp=self.rfile,
            headers=self.headers,
            environ={'REQUEST_METHOD':'POST'}
        )
        if 'check1' in form:
            ck1 = True
        else:
            ck1 = False
        if 'check2' in form:
            ck2 = True
        else:
            ck2 = False
        res = 'Check1: ' + str(ck1) + ', Check2: ' + str(ck2)
        self.send_response(200)
        self.end_headers()
        html = nxt.format(
            message='you typed: ' + res,
            data=form
        )
        self.wfile.write(html.encode('utf-8'))
        return
        
    def index(self):
        self.send_response(200)
        self.end_headers()
        html = index.format(
            title='Hello',
            message='Form送信'
        )
        self.wfile.write(html.encode('utf-8'))
        return
    
    def next(self):
        _url = urlparse(self.path)
        query = parse_qs(_url.query)
        id = query['id'][0]
        password = query['pass'][0]
        # msg = 'id=' + id + ', password=' + password
        self.send_response(200)
        self.end_headers()
        html = nxt.format(
            message = "header data.",
            data = self.headers
        )
        self.wfile.write(html.encode('utf-8'))
        return

    def xml(self):
        xml = '''<?xml version="1.0" encoding="UTF-8"?>
        <data>
            <person>
                <name>Taro</name>
                <mail>taro@yamada</mail>
                <age>39</age>
            </person>
            <message>Hello Python!!</message>
        </data>'''
        self.send_response(200)
        self.send_header('Content-Type', 'application/xml; charset=utf-8')
        # self.send_header('Content-Type', 'text/plain; charset=utf-8')
        self.end_headers()
        self.wfile.write(xml.encode('utf-8'))
        return

    def error(self):
        self.send_error(404, "CANNOT ACCESS!!")
        return

HTTPServer(('', 8000), HelloServerHandler).serve_forever()
