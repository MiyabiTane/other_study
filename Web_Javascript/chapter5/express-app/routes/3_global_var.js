var express = require('express');
var router = express.Router();

var data = [];  // グローバル変数
router.get('/', function(req, res, next) {
    let opt = {
        title: 'Hello!',
        data: data
    }
    res.render('3_global_var', opt);
});

router.post('/', function(req, res, next) {
    data.unshift(req.body.msg);  // リストの頭に追加
    let opt = {
        title: 'Hello!',
        data: data
    }
    res.render('3_global_var', opt);
});

module.exports = router;
