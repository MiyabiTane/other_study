// g++ 19_Counter.cpp 23_GenderCounterBoard.cpp -o out
#include <iostream>
#include <string>
using namespace std;
#include "19_Counter.h"

// Counterクラスの集約（クラスをそのまま使う）
// 継承ではないため、Counterクラスのprotectedメンバ関数は使えない
class GenderCountBoard {
    private:
        Counter male_count;
        Counter female_count;
    public:
        void upMaleCounter();
        void upFemaleCounter();
        int getMaleCounter();
        int getFemaleCounter();
        GenderCountBoard();
};

void GenderCountBoard::upMaleCounter() {
    this->male_count.upVal();
}

void GenderCountBoard::upFemaleCounter() {
    this->female_count.upVal();
}

int GenderCountBoard::getMaleCounter() {
    return this->male_count.getVal();
}

int GenderCountBoard::getFemaleCounter() {
    return this->female_count.getVal();
}

GenderCountBoard::GenderCountBoard() {  // コンストラクタ
}

int main() {
    GenderCountBoard gcb;

    gcb.upMaleCounter();
    gcb.upMaleCounter();

    gcb.upFemaleCounter();
    gcb.upFemaleCounter();
    gcb.upFemaleCounter();

    cout << "男性カウンタの値: " << gcb.getMaleCounter() << endl;
    cout << "女性カウンタの値: " << gcb.getFemaleCounter() << endl;

    return 0;
}