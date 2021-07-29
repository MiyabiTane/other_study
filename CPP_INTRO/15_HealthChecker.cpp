#include <iostream>
#include <string>
using namespace std;
#include "15_HealthChecker.h"

// BMIを返すメンバ関数の実装
double HealthChecker::getBmi() {
    // まだBMIが計算されていなかったら処理を行う
    if (this->bmi == 0) {
        double m_height = this->height / 100;
        this->bmi = this->weight / m_height / m_height;
    }
    return this->bmi;
}

string HealthChecker::getName() {
    return this->name;
}

int HealthChecker::getStdBmi() {
    return HealthChecker::STD_BMI;
}

// 標準体重を返すメンバ関数の実装
double HealthChecker::getStdWeight() {
    double m_height = this->height / 100;
    return HealthChecker::STD_BMI * m_height * m_height;
}

// コンストラクタの実装
HealthChecker::HealthChecker(string name, double height, double weight) {
    // init
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->bmi = 0;
}