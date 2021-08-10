// g++ 32_Point.cpp 32_Point_main.cpp -o out
#include <iostream>
#include <string>
using namespace std;
#include "32_Point.h"

int main() {
    Point p1(3, 5);
    Point p2(2, 4);
    Point p3, p4;

    p3 = p1 + p2;
    p4 = p1 - p2;

    cout << "p1:x = " << p1.getX() << ", y = " << p1.getY() << endl;
    cout << "p2:x = " << p2.getX() << ", y = " << p2.getY() << endl;
    cout << "p3:x = " << p3.getX() << ", y = " << p3.getY() << endl;
    cout << "p4:x = " << p4.getX() << ", y = " << p4.getY() << endl;

    Point p5(3, 5);
    if (p1 == p5) {
        cout << "p1とp5は等しい" << endl;
    }
    if (p1 != p2) {
        cout << "p1とp2は等しくない" << endl;
    }

    cout << "1 + 2 = " << 1 + 2 << endl;
    if (1 != 2) {
        cout << "1と2は等しくない" << endl;
    }

    Point p;
    cout << "x座標とy座標を入力してください: ";
    cin >> p;
    cout << "入力された座標は、" << p << "です。" << endl;

    return 0;
}
