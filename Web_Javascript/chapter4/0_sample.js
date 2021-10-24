// プリント文
console.log("This is Node.js");

// 簡単な計算
var n = 12345;
var total = 0;
for (var i = 1; i <= n; i++) {
    total += i;
}
console.log('total: ' + total);

// 時間の計測
console.time('test');

var result = [];
for (let i = 2; i < 1000; i++) {
    var num = 2;
    var flg = true;
    while (num < i) {
        if (i % num == 0) {
            flg = false;
            break;
        }
        num ++;
    }
    if (flg) {
        result.push(i);
    }
}
console.log(result);
console.timeEnd('test');

// 値の入力
const readline = require('readline');
const read = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// テキストが入力されると第２引数のアロー関数が呼ばれる(非同期処理のcb関数)
// この時、引数のanswerに入力したテキストが渡される
read.question('type any words: ', (answer) => {
    read.write("you typed: " + answer);
    read.close();
});

// アロー関数を使わない場合
/*
function answer(answer) {
    read.write("you typed: " + answer);
    read.close();
}
read.question('type any words: ', answer);
*/
