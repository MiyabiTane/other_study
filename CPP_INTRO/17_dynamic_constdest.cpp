// g++ 15_HealthChecker.cpp 17_dynamic_constdest.cpp -o out
#include <iostream>
#include <string>
using namespace std;
#include "15_HealthChecker.h"

int main() {
    // ポインタを使ってオブジェクトを動的生成
    HealthChecker *ptr = new HealthChecker("山田一郎", 170, 67.5);
    cout << ptr->getName() << "さんのBMIは" << ptr->getBmi() << "です。" << endl;
    // オブジェクトを動的破棄（これを忘れるとメモリが食われるので注意）
    delete ptr;

    return 0;
}