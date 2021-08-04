#include <iostream>
#include <string>
using namespace std;
#include "19_Counter.h"
#include "21_CounterEx.h"

int main() {
    CounterEx cnt;
    cout << "カウンタの値 = " << cnt.getVal() << endl;

    cnt.upVal();
    cnt.upVal();
    cnt.upVal();
    cout << "カウンタの値 = " << cnt.getVal() << endl;

    cnt.downVal();
    cnt.downVal();
    cout << "カウンタの値 = " << cnt.getVal() << endl;

    return 0;
}