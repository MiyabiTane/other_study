// g++ 40_getFee.cpp -o hello
// g++ g++ 48_myDump.cpp -o out
// ./out hello
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char * argv[]) {
    char data;
    int num;

    if (argc != 2) {
        // cerr: 標準エラー出力 リダイレクトできない
        cerr << "使い方 ./out ファイル名" << endl;
        return 1;
    }

    // 入力用のバイナリファイルオープン
    ifstream fin(argv[1], ios::in | ios::binary);
    if (!fin.is_open()) {
        cerr << "ファイルを開けません";
        return 2;
    }

    // ファイルから１バイトずつ読み出す
    num = 0;
    while (fin.get(data)) {
        cout << setw(2) << setfill('0') << hex << uppercase << ((int)data & 0xff) << ' ';
        num++;
        if (num % 16 == 0) cout << endl;
    }
    cout << endl;

    fin.close();

    return 0;
}