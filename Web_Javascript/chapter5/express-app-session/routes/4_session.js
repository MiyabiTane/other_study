var express = require('express');
var router = express.Router();

router.get('/', function(req, res, next) {
    // セッション：イメージはブラウザごとのグローバル変数
    if (req.session.data == undefined) {
        req.session.data = [];
    }
    let opt = {
        title: 'Hello!',
        data: req.session.data  // ブラウザ毎に違うデータを格納
    }
    res.render('4_session', opt);
});

router.post('/', function(req, res, next) {
    req.session.data.unshift(req.body.msg);
    let opt = {
        title: 'Hello!',
        data: req.session.data
    }
    res.render('4_session', opt);
});

module.exports = router;
