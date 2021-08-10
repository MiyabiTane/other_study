#include <iostream>
using namespace std;

// 関数名が同じでも、引数名でどの関数を呼ぶか判断できる
// 型が異なり、関数名と引数が同じ関数は実装不可
int getMax(int a, int b) {
    return a > b ? a : b;
}

double getMax(double a, double b) {
    return a > b ? a : b;
}

int getMax(int a[], int length) {
    int ans = a[0];
    for (int i = 1; i < length; i++) {
        if (ans < a[i]) {
            ans = a[i];
        }
    }
    return ans;
}

int main() {
    cout << getMax(123, 567) << endl;
    cout << getMax(1.23, 5.67) << endl;

    const int DATA_NUM = 5;
    int a[DATA_NUM] = {22, 44, 33, 55, 11};
    cout << getMax(a, DATA_NUM) << endl;

    return 0;
}