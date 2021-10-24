const fs = require('fs');

// 同期処理でファイルを読み込み
const f1 = fs.readFileSync('./index.html');
console.log(f1.toString());
