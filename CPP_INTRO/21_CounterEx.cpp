// g++ 19_Counter.cpp 21_CounterEx.cpp 21_CounterEx_main.cpp -o out
#include "19_Counter.h"
#include "21_CounterEx.h"

void CounterEx::downVal() {
    this-> val--;
}

CounterEx::CounterEx() : Counter () {
}  // コンストラクタ