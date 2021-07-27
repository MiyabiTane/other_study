// g++ 9_pointer.cpp 9_quadEq.cpp -o out
#include <iostream>
using namespace std;
#include "9_quadEq.h"

int main() {
    double a, b, c;
    double x1, x2;
    bool ans;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    // 関数呼び出し、ポインタ渡し
    ans = quadEq_func(a, b, c, &x1, &x2);

    if (ans) {
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else {
        cout << "解なし" << endl;
        cout << "この時x1,x2に入っている値は" << x1 << ", " << x2 << endl;
    }

    return 0;
}