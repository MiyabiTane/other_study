#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    const int STD_BMI = 22;  // 標準BMI
    double height, weight, bmi;  // 身長、体重、BMI
    double std_weight;  // 標準体重

    cout << "身長[cm]を入力して下さい: ";
    cin >> height;
    height /= 100;
    cout << "体重[kg]を入力して下さい: ";
    cin >> weight;
    
    bmi = weight / pow(height, 2);
    std_weight = STD_BMI * pow(height, 2);

    cout << "あなたのBMIは" << fixed << setprecision(1) << bmi << "です。" << endl;
    cout << "あなたの標準体重は" << std_weight << "kgです。" << endl;

    // 肥満分類結果を表示
    if (bmi < 18.5) {
        cout << "低体重です。" << endl;
    } else if (bmi < 25.0) {
        cout << "普通体重です。" << endl;
    } else if (bmi < 30.0) {
        cout << "肥満（１度）です。" << endl;
    } else if (bmi < 35.0) {
        cout << "肥満（２度）です。" << endl;
    } else if (bmi < 40.0) {
        cout << "肥満（３度）です。" << endl;
    } else {
        cout << "肥満（４度）です。" << endl;
    }

    return 0;
}