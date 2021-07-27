#include <iostream>
using namespace std;

// 引数をポインタ渡しで受け取る関数
void sub(int *ptr) {
    cout << "sub関数：引数ptrに渡されたアドレス = " << ptr << endl;
    cout << "sub関数：引数ptrが指し示す変数の値 = " << *ptr << endl;
    // 引き渡されたアドレスが指し示す変数に値を書き込み
    *ptr = 456;
    cout << "sub関数：引数ptrが指し示す変数の新しい値" << *ptr << endl;

    return;
}

int main() {
    int val = 123;
    cout << "main関数：変数valのアドレス = " << &val << endl;
    cout << "main関数：変数valの値 = " << val << endl;
    // ポインタ渡しで関数の呼び出し
    sub(&val);

    cout << "main関数：変数valの値 = " << val << endl;
    return 0;
}