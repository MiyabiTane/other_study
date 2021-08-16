#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);

    int length = v.size();
    cout << "ソート前";
    for (int i = 0; i < length; i++) {
        cout << "[" << v[i] << "]";
    }
    cout << endl;

    // ベクトルをソート
    sort(v.begin(), v.end());
    cout << "ソート後";
    for (int i = 0; i < length; i++) {
        cout << "[" << v[i] << "]";
    }
    cout << endl;

    // ベクトルをソート
    sort(v.rbegin(), v.rend());
    cout << "ソート後 (大きい順)";
    for (int i = 0; i < length; i++) {
        cout << "[" << v[i] << "]";
    }
    cout << endl;

    return 0;
}