#include <iostream>
using namespace std;

double getAverage(const int *a, int length) {
    double sum;
    double average;
    int i;

    sum = 0;
    for (i = 0; i < length; i++) {
        // 引数が渡された時点では、ポインタは配列の先頭の要素を指し示している。
        sum += *a;
        a++;
    }
    average = (double)sum / length;

    return average;
}

// ポインタを使わない場合
double getAverage_nopointer(const int a[], int length) {
    double sum;
    double average;
    int i;

    sum = 0;
    for (i = 0; i < length; i++) {
        sum += a[i];
    }

    average = (double)sum / length;

    return average;
}


int main() {
    const int DATA_NUM = 10;

    int point[DATA_NUM] = {85, 72, 63, 45, 100, 98, 52, 88, 74, 65};
    double average;

    average = getAverage(point, DATA_NUM);
    cout << "平均点： " << average << endl;

    return 0;
}
