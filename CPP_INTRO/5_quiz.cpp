#include <iostream>
using namespace std;

int main() {
    const char RIGHT_ANS = 'c';
    char ans;

    // 解答が不正解である限り繰り返す
    do {
        cout << "日本で一番長い川は？" << endl;
        cout << "a. 利根川, b. 石狩川, c. 信濃川" << endl;

        cout << "解答: ";
        cin >> ans;
    } while (ans != RIGHT_ANS);

    cout << "正解！" << endl;
    return 0;
}