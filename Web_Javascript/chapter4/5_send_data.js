const https = require("https");
const r1 = require("./1_getline.js");

async function main() {
    let msg = await r1.getline("type your message: ");
    msg = '{"message":' + msg + '"}';

    const options = {
        hostname: 'tuya-no.firebaseio.com',
        path: '/dummy.json',
        method: 'PUT',
        headers: {
            'Content-Type': 'application/json',
            'Content-length': Buffer.byteLength(msg)
        }
    };

    // サーバーにアクセス。アクセスのみでデータ送信はしていない。
    // 第一引数: 設定情報、第二引数: サーバーからの返信時の処理を行うアロー関数
    let req = https.request(options, (res) => {
        console.log('STATUS: ' + res.statusCode);
    });

    req.on('error', (e) => {
        console.log(e);
    });

    // サーバーにデータ送信
    // 第一引数: 送信するデータ（テキスト）、第二引数: エラー情報。正常ならundefinedが渡される
    req.write(msg, (err) => {
        if (err != undefined) {
            console.log(err);
        }
    });

    req.end(() => {
        console.log('finished!!');
    });
}

main();

/* ステータスコード
200: OK
400: Bad Request
401: Unauthorized. 認証が必要
403: Forbidden. アクセス禁止
500: Internal Server Error. サーバー内部でエラー発生
*/