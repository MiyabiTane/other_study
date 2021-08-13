#include <iostream>
#include "37_MyCircle.h"

MyCircle::MyCircle(double r) {
    this->r = r;
}

double MyCircle::getArea() {
    return this->r * this->r * 3.14;
}
