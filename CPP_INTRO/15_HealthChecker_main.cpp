// g++ 15_HealthChecker.cpp 15_HealthChecker_main.cpp -o out
#include <iostream>
#include <string>
using namespace std;
#include "15_HealthChecker.h"

const int HealthChecker::STD_BMI = 22;  // global

int main() {
    const int DATA_NUM = 3;
    HealthChecker people[DATA_NUM] = {
        HealthChecker("山田一郎", 170, 67.5),
        HealthChecker("佐藤花子", 160, 54.5),
        HealthChecker("鈴木次郎", 180, 85.5)
    };
    /* structの時はこうだった
    HealthData people[DATA_NUM] = {
        {"山田一郎", 170, 67.5, 0},
        {"佐藤花子", 160, 54.5, 0},
        {"鈴木二郎", 180, 85.5, 0}
    };
    */
   cout << "標準BMIは" << HealthChecker::getStdBmi() << "です。" << endl;

   for (int i = 0; i < DATA_NUM; i++) {
       cout << people[i].getName() << "さんのBMIは" << people[i].getBmi() << "で、"
       << "標準体重は" << people[i].getStdWeight() << "です。" << endl;
   }
   return 0;
}

/*
int main() {
    // HealthCheckerのインスタンス作成
    HealthChecker yamada("山田一郎", 170, 67.5);

    //BMIの値を表示
    cout << yamada.getName() << "さんのBMIは" << yamada.getBmi() << "です。" << endl;

    return 0;
}
*/