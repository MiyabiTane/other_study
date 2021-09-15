from urllib.parse import urlparse, parse_qs
from http.server import BaseHTTPRequestHandler, HTTPServer

#htmlファイルの読み込み
with open('html/index5.html', mode='r') as f:
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
        
    def index(self):
        _url = urlparse(self.path)
        self.send_response(200)
        self.end_headers()
        html = index.format(
            title = 'Hello',
            link = '/next?' + _url.query,
            message = 'ようこそ、HTTPServerの世界へ！'
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
