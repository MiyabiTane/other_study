// g++ 37_MyCircle.cpp 37_MyCircle_main.cpp -o out
#include <iostream>
#include "37_MyCircle.h"
using namespace std;

int main() {
    MyCircle obj(10);
    cout << "半径10の円の面積: " << obj.getArea() << endl;

    return 0;
}
