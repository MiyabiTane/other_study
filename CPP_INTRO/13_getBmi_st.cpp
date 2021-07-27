#include <iostream>
#include <string>
using namespace std;
#include "13_struct.h"

double getBmi_struct(const HealthData *phc) {
    // 構造体のポインタでメンバの値を読み書きする時は. でなくて->
    return getBmi_func(phc->height, phc->weight);
}
