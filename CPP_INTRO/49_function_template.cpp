#include <iostream>
using namespace std;

// 汎用関数：関数テンプレートを使った関数
template <class T> T getMin(T a, T b) {
    return a < b ? a : b;
}

/*
int getMin(int a, int b) {
    return a < b ? a : b;
}

double getMin(double a, double b) {
    return a < b ? a : b;
}
*/

// 汎用関数：２つの型の使用
template <class T1, class T2> T1 getMin(T1 a[], T2 length) {
    T1 ans = a[0];
    for (T2 i = 1; i < length; i++) {
        if (ans > a[i]) ans = a[i];
    }
    return ans;
}

int main() {
    int a, b, c;
    a = 123;
    b = 456;
    c = getMin(a, b);
    cout << c << endl;

    double x, y, z;
    x = 1.23;
    y = 4.56;
    z = getMin(x, y);
    cout << z << endl;

    // char型のgetMin関数を呼び出す
    char cArray[] = {'c', 'b', 'f', 'a', 'e'};
    int cLength = 5;
    char cAns = getMin(cArray, cLength);
    cout << cAns << endl;

    // float型のgetMin関数(配列)を呼び出す
    float fArray[] = {2.22F, 3.33F, 1.11F, 5.55F, 4.44F};  // Fをつけるとfloat型になる
    int fLength = 5;
    float fAns = getMin(fArray, fLength);
    cout << fAns << endl;

    return 0;
}
