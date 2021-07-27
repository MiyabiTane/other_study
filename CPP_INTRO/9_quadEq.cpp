#include <iostream>
#include <math.h>
using namespace std;

bool quadEq_func(double a, double b, double c, double *px1, double *px2) {
    double inRoot;  // 平方根の中身
    bool ans;  // 解ありならTrue

    inRoot = b * b - 4 * a * c;
    if (inRoot < 0) {
        ans =false;
    } else {
        ans = true;
        // ポインタに変数を格納
        *px1 = (-b + sqrt(inRoot)) / (2 * a);
        *px2 = (-b - sqrt(inRoot)) / (2 * a);
    }

    return ans;
}