const fs = require('fs');

// 同期処理でファイルを読み込み
const f1 = fs.readFileSync('./index.html');
console.log(f1.toString());

// 非同期処理でファイルを読み込み
// 第一引数：エラー情報をまとめたオブジェクト
// 第二引数：読み込んだデータを扱うBufferオブジェクト
fs.readFile('./index.html', (err, data) => {
    console.log(data.toString());
});


// awaitで非同期処理を同期的に呼び出す
function getFile(fname) {
    return new Promise((resolve, reject) => {
        fs.readFile(fname, (err, data) => {
            resolve(data)
        });
    });
}

async function main_read() {
    var data = await getFile('./index.html');
    console.log("===")
    console.log(data.toString());
}
// main_read();


// ファイル書き込み
const r1 = require('./1_getline.js');

// 同期処理
async function main_write() {
    let msg = await r1.getline('please type:');
    fs.writeFileSync('./data.txt', msg);
    console.log('save data.txt to write:' + msg);
}

// 非同期処理
async function main_write_2() {
    let msg = await r1.getline('please type:');
    fs.writeFile('./data.txt', msg, (err) => {
        console.log('save data.txt to write: ' + msg);
    });
}
// main_write();

// ファイルに追記
async function main_update() {
    while(true) {
        let msg = await r1.getline('please type: ');
        if (msg == '') {
            return;
        }
        fs.appendFileSync('./data.txt', msg + '\n');
    }
}
// main_update();


// フォルダ内のファイルを表示
// 同期処理
let counter = 0;
let files = fs.readdirSync('./');
for (var i in files) {
    counter++
    console.log(counter + ': ' + files[i]);
}


// 同期処理
counter = 0;
fs.readdir('./', (err, files) => {
    for (let i in files) {
        counter++
        console.log(counter + ': ' + files[i]);
    }
})


// ファイルの情報を得る
let fname = './6_file_operation.js';
fs.stat(fname, (err, st) => {
    console.log('NAME: ' + fname);
    console.log('SIZE: ' + st.size);
    console.log('CREATE: ' + st.birthtime);
    console.log('MODIFY: ' + st.mtime);
});


// ファイルのコピーなどの操作
let dir = './';
let bk = dir + 'backup/';

let files_ = fs.readdirSync(dir);
fs.mkdirSync(bk);
console.log(bk + ' created.');
for (let i in files_) {
    fs.copyFileSync(dir + files_[i], bk + files_[i]);
    console.log(files_[i] + ' backuped.');
}
console.log('backup completed!');
