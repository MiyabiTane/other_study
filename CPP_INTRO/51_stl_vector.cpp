#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v;  //　ベクトルの作成

    //ベクトルを用いているので任意の文字数で良い
    string s;
    cout << "打ち終わったら..を入力してください";
    do {
        cout << "文字列の入力";
        cin >> s;
        v.push_back(s);  // 末尾に要素を追加
    } while(s != "..");
    v.pop_back();  // 末尾の要素を削除

    // ベクトルの中身を確認
    int length = v.size();
    cout << "ベクトルの内容:" << endl;
    for (int i = 0; i < length; i++) {
        cout << v[i] << " " << endl;
    }

    return 0;
}