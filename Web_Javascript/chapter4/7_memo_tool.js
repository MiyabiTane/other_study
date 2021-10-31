const fs = require('fs');
const { findSourceMap } = require('module');
const r1 = require('./1_getline.js');

var data = [];
let fname = './message.txt';

// 中でgetlineを呼び出しているためasyncを使う
async function main() {
    let opt = {encoding: 'utf8'}
    let bf = fs.readFileSync(fname, opt);
    data = JSON.parse(bf.toString('utf8'));

    while (true) {
        let cmd = await r1.getline('cmd(a/d/f/q)');
        switch(cmd.toString()) {
            case 'a':
                await add();
                break;
            case 'd':
                await del();
                break;
            case 'f':
                await find();
                break;
            case 'q':
                quit();
                return;
            default:
                console.log('no-command');
        }
    }
}

// メッセージの追加
async function add() {
    let bf = await r1.getline('type message: ');
    let msg = bf.toString('utf8');
    let item = {
        date: new Date(),
        message: msg
    }
    // unshift: 頭に要素を追加する。
    data.unshift(item);
    console.log('message added.');
}

// メッセージの削除
async function del() {
    let bf = await r1.getline('type number: ');
    // * 1をすることで文字列->数字に変換される
    let num = bf.toString() * 1;
    console.log('item: ' + data[num].message);
    bf = await r1.getline('delete it? (y/n):');
    if (bf.toString() == 'y') {
        // numで指定した位置の情報を削除
        data.splice(num, 1);
    }
}

// メッセージの検索
async function find() {
    let bf = await r1.getline('find: ');
    let find = bf.toString('utf8');
    for (let i in data) {
        // indexOf: 引数に指定したテキストが何文字目に入っているかを返す
        if (data[i].message.indexOf(find) > -1) {
            console.log(i + ': ' + data[i].message);
        }
    }
}

// スクリプトの終了
function quit() {
    let opt = {encoding: 'utf8'}
    // テキストファイルにdataの内容を保存
    fs.writeFileSync(fname, JSON.stringify(data), opt);
    console.log('quit now!');
}

// ファイルが存在しなければ作成
function make_file(fname) {
    let files = fs.readdirSync('./');
    let found_flg = false;
    for (var i in files) {
        console.log(files[i]);
        if ('./' + files[i] == fname) {
            found_flg = true;
        }
    }
    if (found_flg) {
        console.log('file already exists');
    } else {
        console.log('make file: ' + fname);
        fs.writeFileSync(fname, '[]');
        // fs.writeFile(fname, '[]', (err) => {
        //     console.log('make txt file');
        // });
    }
}

make_file(fname);
main();
