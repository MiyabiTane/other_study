var express = require('express');
var router = express.Router();

// 第一引数：アクセスする（相対）パス、第二引数：実行する処理
router.get('/', function(req, res, next) {
    let opt = {
        title: 'Hello!',
        message: 'input form: '
    }
    res.render('1_form', opt);
});

router.post('/', function(req, res, next) {
    let name = req.body.f1;
    let pass = req.body.f2;
    let msg = 'name: ' + name + '<br>password: ' + pass;
    let opt = {
        title: 'Hello!',
        message: msg
    }
    res.render('1_form', opt);
});

module.exports = router;
