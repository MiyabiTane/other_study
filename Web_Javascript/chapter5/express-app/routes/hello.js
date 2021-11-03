var express = require('express');
var router = express.Router();

let opt = {
    title: 'Hello!',
    message: 'これは新しいWebページです'
}
// 第一引数：アクセスする（相対）パス、第二引数：実行する処理
router.get('/', function(req, res, next) {
    // クエリーパラメータ
    // アクセスするURLの例：http://localhost:3000/hello?name=hanako&pass=flower
    let name = req.query.name;
    let pass = req.query.pass;
    let msg = 'name: ' + name + '<br>password: ' + pass;
    let opt = {
        title: 'Hello',
        message: msg
    }
    // レンダリング：HTMLをソースコードとして実行
    res.render('hello', opt);
});
module.exports = router;
