from http.server import SimpleHTTPRequestHandler, HTTPServer

server = HTTPServer(('', 8000), SimpleHTTPRequestHandler)
# SimpleHTTPRequestHandler -> クライアントからのアクセスに対応するファイルを読み込んで送り返す
server.serve_forever()

# このファイルを実行してhttp://localhost:8000/にアクセスする