from http.server import BaseHTTPRequestHandler, HTTPServer

with open('html/index2.html', mode='r') as f:
    index2 = f.read()

class HelloServerHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        self.send_response(200)
        self.end_headers()
        # self.wfile.write(b'Sample web-server!!!')
        # htmlファイルを読み込んで値をはめ込み
        html = index2.format(
            title = "Hello",
            message = "ようこそ、HTTPServerの世界へ！"
        )
        self.wfile.write(html.encode('utf-8'))
        return

HTTPServer(('', 8000), HelloServerHandler).serve_forever()
        