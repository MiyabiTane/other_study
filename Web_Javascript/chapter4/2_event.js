const readline = require('readline');

var counter = 0;

const read = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// on: イベント
// 第一引数: イベント名、第二引数: アロー関数（cb関数）
read.on('line', (line) => {
    counter++;
    console.log('(' + counter + ': ' + line.length + 'chars)');
});

var content = [ // 配列
    "-- begin --",
    "これは長文のコンテンツです",
    "長い文章を出力させる",
    "-- end --"].join('\n');
    // join: 配列データを一つのテキストにまとめる
    // 引数はつなげる時に間に入れる文字
read.write(content);
read.close();
