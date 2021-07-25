#include <iostream>
using namespace std;

int for_loop() {
    int month;
    for (month = 1; month <= 12; month++) {
        cout << month << "月\t";
    }
    cout << endl;

    return 0;
}

int while_loop() {
    int month;
    month = 1;
    while (month <= 12) {
        cout << month << "月\t";
        month++;
    }
    cout << endl;

    return 0;
}

int many_loop() {
    int step;
    int num;

    for (step = 1; step <= 9; step++) {
        cout << step << "の段: \t";
        for (num = 1; num <=9; num++) {
            cout << step * num << "\t";
        }
        cout << endl;
    } 

    return 0;
}

int main() {
    for_loop();
    cout << endl;
    while_loop();
    cout << endl;
    many_loop();
    return 0;
}