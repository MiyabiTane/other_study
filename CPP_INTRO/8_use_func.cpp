// $ g++ 8_getBmi.cpp 8_use_func.cpp -o out
// $ ./out
#include <iostream>
#include <math.h>
#include "8_getBmi.h"
using namespace std;

// プロトタイプ宣言
//double getBmi_func(double height, double weight);

int main () {
    double height;
    double weight;
    double bmi;

    cout << "身長[cm]を入力してください: ";
    cin >> height;
    cout << "体重[kg]を入力してください: ";
    cin >> weight;

    bmi = getBmi_func(height, weight);
    cout << "あなたのBMIは" << bmi << "です。" << endl;

    return 0;
}

/*　既存ライブラリの使用
int use_sqrt() {
    double data;
    double ans;

    cout << "平方根を求める数値: ";
    cin >> data;
    //　標準ライブラリに実装済みの関数を使う
    ans = sqrt(data);
    cout << ans;

    return 0;
}
*/