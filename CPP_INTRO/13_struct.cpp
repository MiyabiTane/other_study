// g++ 13_getBmi_st.cpp 8_getBmi.cpp 13_struct.cpp -o out 
#include <iostream>
#include <string>
#include "13_struct.h"
using namespace std;

int main() {
    const int DATA_NUM = 3;
    HealthData people[DATA_NUM] = {
        {"山田一郎", 170, 67.5, 0},
        {"佐藤花子", 160, 54.5, 0},
        {"鈴木二郎", 180, 85.5, 0}
    };
    double m_height;
    int i;
    HealthData person;

    for (i = 0; i < DATA_NUM; i++) {
        person = people[i];
        // m_height = person.height / 100;
        // person.bmi = person.weight / m_height / m_height;
        person.bmi = getBmi_struct(&person);
        cout << person.name << "さんのBMIは" << person.bmi << "です" << endl;
    }
    return 0;
}