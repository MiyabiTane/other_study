#include <iostream>
using namespace std;

double getCircleArea(double r);  // プロトタイプ宣言

int main() {
    cout << "半径10の円の面積: " << getCircleArea(10) << endl;

    return 0;
}

double getCircleArea(double r) {
    return r * r * 3.14;
}
