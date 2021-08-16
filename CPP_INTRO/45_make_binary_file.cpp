#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 出力用バイナルファイルオープン
    ofstream fout("myFile.bin", ios::out | ios::binary);
    // ファイルがオープンできたかチェック
    if (!fout.is_open()) {
        cout << "ファイルをオープンできません";
        return 1;
    }
    // ファイルに1~10の数値を1バイトずつ書き込む
    // char型、２進数で書き込む
    for (char data = 1; data <= 10; data++) {
        fout.put(data);
    }
    //　ファイルをクローズする
    fout.close();
    cout << "ファイルに書き込みました";

    return 0;
}