var express = require('express');
var router = express.Router();

// 第一引数：アクセスする（相対）パス、第二引数：実行する処理
router.get('/', function(req, res, next) {
    let opt = {
        title: 'Hello!',
        form: null
    }
    res.render('2_scriptlet', opt);
});

// フォーム送信された時に呼ばれる
router.post('/', function(req, res, next) {
    let opt = {
        title: 'Hello!',
        form: req.body
    }
    res.render('2_scriptlet', opt);
});

module.exports = router;
