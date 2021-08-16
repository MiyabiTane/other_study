#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 出力用テキスtファイルのオープン
    ofstream fout("myFile.txt");
    // ファイルがオープンできたかチェック
    if (!fout.is_open()) {
        cout << "ファイルをオープンできません";
        return 1;  // 異常終了で0以外を返す
    }

    //　ファイルに文字列を書き込む(<<がオーバーロードされている)    
    fout << "hello world" << endl;
    fout<< "皆さんこんにちは" << endl;
    // ファイルのクローズ
    fout.close();
    cout << "書き込み完了";

    return 0;
}