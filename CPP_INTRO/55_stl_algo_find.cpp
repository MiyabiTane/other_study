#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> v;
    v.push_back("apple");
    v.push_back("banana");
    v.push_back("melon");
    v.push_back("lemon");
    v.push_back("orange");

    string s;
    cout << "探索するデータ";
    cin >> s;

    // ベクトルからデータ探索
    vector<string>::iterator it = find(v.begin(), v.end(), s);
    if (it != v.end()) { // v.end(): 末尾の次のイテレータ
        cout << *it << "が見つかりました" << endl;
    } else {
        cout << "そのデータは見つかりません" << endl;
    }

    return 0;
}