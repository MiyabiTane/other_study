#include "19_Counter.h"

void Counter::resetVal() {
    this->val = 0;
}

void Counter::upVal() {
    this->val++;
}

int Counter::getVal() {
    return this->val;
}

Counter::Counter() {
    this->resetVal();
}
