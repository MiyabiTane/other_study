#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, s3;
    s1 = "apple";
    s2 = "banana";

    //　文字列比較
    if (s1 > s2) {
        cout << "s1の方が大きい" << endl;
    } else if (s1 < s2) {
        cout << "s1の方が小さい" << endl;
    } else {
        cout << "等しい" << endl;
    }

    s3 = s1 + s2;  // 文字列を連結する
    cout << s3 << endl;

    cout << s3.length() << endl;  // 長さを求める

    cout << s3.substr(5, 3) << endl;  // 5番目から3文字分の部分文字列を取り出す。

    cout << s3[5] << endl;

    cout << s3.find("na") << endl;  // "na"という文字列を見つけて頭の位置を返す

    s3.clear();  // 文字列を空にする
    if (s3.empty()) {
        cout << "文字列は空です。" << endl;
    } else {
        cout << "空ではありません。" << endl;
    }

    return 0;
}

/* 文字列オブジェクトstringの使用
int main() {
    int ans;
    string s;

    s = "hello, world";
    ans = s.length();
    cout << ans << endl;

    return 0;
}
*/

/* strlenの使用
int main() {
    int ans;
    ans = strlen("hello, world");
    cout << ans << endl;

    return 0; 
}
*/