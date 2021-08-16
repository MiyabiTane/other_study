// 43_make_file.cppを先に実行すること（あるいはmyFile.txtを同ディレクトリ下に用意する）
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string s;
    // 入力用テキストファイルオープン
    ifstream fin("myFile.txt");
    // ファイルがオープンできたかどうかチェック
    if (!fin.is_open()) {
        cout << "ファイルをオープンできません";
        return 1;
    }
    // ファイル1行ずつ読み出す
    while (getline(fin, s)) {
        cout << s << endl;
    }
    fin.close();

    return 0;
}