// 45_make_binary.cppを先に実行する
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char data;
    // 入力用のバイナリファイルをオープンする
    ifstream fin("myFile.bin", ios::in | ios::binary);
    // ファイルがオープンできたかどうかチェック
    if (!fin.is_open()) {
        cout << "ファイルを開けません";
        return 1;
    }
    // ファイルから1バイトずつ読み出す
    while (fin.get(data)) {
        cout << "[" << (int)data << "]";
    }
    cout << endl;
    // ファイルをクローズする
    fin.close();

    return 0;
}