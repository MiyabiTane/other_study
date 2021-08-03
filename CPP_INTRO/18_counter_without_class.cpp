#include <iostream>
using namespace std;

// 10個のカウンタの値
int counterVal[10];

//指定されたカウンタを0にする
void resetCounterVal(int num) {
    counterVal[num] = 0;
}

// 指定されたカウンタの値をアップ
void upCounterVal(int num) {
    counterVal[num]++;
}

int main() {
    resetCounterVal(3);
    resetCounterVal(5);

    upCounterVal(3);
    upCounterVal(3);

    upCounterVal(5);
    upCounterVal(5);
    upCounterVal(5);
    upCounterVal(5);

    cout << "3番のカウンタの値 = " << counterVal[3] << endl;
    cout << "5番のカウンタの値 = " << counterVal[5] << endl;

    return 0;
}