const https = require('https');

// https.get("https://tuya-no.firebaseio.com/message.json", (res) => {
https.get("https://tuya-no.firebaseio.com/mydata.json", (res) => {
    let body = '';
    res.setEncoding('utf8');
    // データを受け取った時のイベント。データ蓄積
    res.on('data', (chunk) => {  // chunk: 送られてきたデータ
        body += chunk;
    });
    // 受け取ったデータを用いた処理
    res.on('end', (res) => {
        // console.log(body);
        json = JSON.parse(body);
        console.table(json);
    });
});
