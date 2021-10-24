const readline = require('readline');

exports.getline = function(msg) {
    const read = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    // 中断イベント(Ctrl + Cで呼ばれる)
    read.on('SIGINT', () => {
        console.log(' \n*** finish ***');
        read.close();
    });
    // resolve -> プロミスが解決した場合のcb関数
    // reject -> 拒否された場合のcb関数
    return new Promise((resolve, reject)=>{
        read.question(msg, (answer) => {
            resolve(answer);
            read.close();
        });
    })
};
