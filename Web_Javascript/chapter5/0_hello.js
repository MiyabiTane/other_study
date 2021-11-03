const http = require('http');

var server = http.createServer(
    (req, res) => {
        // サーバーにアクセスした時の処理
        res.end('Hello Node.js!');
    }
)
server.listen(3000);
