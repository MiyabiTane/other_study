const g1 = require("./1_getline.js");

// 入力のメイン処理
async function main() { // async: awaitを用いた関数が呼ばれることを示す
    console.log(('-- begin --'));
    while(true) {
        // await: 非同期処理を同期的に呼び出す
        var result = await g1.getline('type any words: ');
        if (result == '') {
            break;
        }
        console.log('you typed: ' + result);
    }
    console.log('-- end --');
}

// 中断イベントを用いた入力処理
async function main_interrupt() { // async: awaitを用いた関数が呼ばれることを示す
    while (true) {
        var re = await g1.getline('input: ');
        console.log('(' + re.length + 'chars)');
    }
}

//main();
main_interrupt();
