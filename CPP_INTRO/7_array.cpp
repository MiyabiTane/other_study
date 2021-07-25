#include <iostream>
using namespace std;

int ave_point() {
    const int DATA_NUM = 10;
    // 10人の学生のテスト得点を格納した配列
    int point[DATA_NUM] = {85, 72, 63, 45, 100, 98, 52, 88, 74, 65};
    int i, sum;
    double average;

    sum = 0;
    for (i = 0; i < DATA_NUM; i++) {
        sum += point[i];
    }

    average = (double)sum / DATA_NUM;
    cout << "平均点: " << average << endl;

    return 0;
}

int find_point() {
    const int DATA_NUM = 10;
    int point[DATA_NUM] = {85, 72, 63, 45, 100, 98, 52, 88, 74, 65};
    int find_point;
    int i, pos = -1;

    cout << "見つける得点: ";
    cin >> find_point;

    for (i = 0; i < DATA_NUM; i++) {
        if (point[i] == find_point) {
            pos = i + 1;
            break;
        }
    }

    if (pos == -1) {
        cout << "得点が見つかりませんでした。" << endl;
    } else {
        cout << pos << "番目にあります。" << endl;
    }

    return 0;
} 

int use_continue() {
    const int DATA_NUM = 10;
    int point[DATA_NUM] = {85, 72, 63, 45, 100, 98, 52, 88, 74, 65};
    int i, data;
    char grade;

    /* コンパイル失敗
    for (auto data : point) {
        if (data < 60) continue;
        if (data >= 80) grade = 'A';
        else if (data >= 70) grade = 'B';
        else grade = 'C';

        cout << data << "評価は" << grade << "です。" << endl;
    }
    */

    for (i = 0; i < DATA_NUM; i++) {
        if (point[i] < 60) continue;

        if (point[i] >= 80) grade = 'A';
        else if (point[i] >= 70) grade = 'B';
        else grade = 'C';

        cout << point[i] << "の評価は" << grade << "です。" << endl;
    }

    return 0;
}

int main () {
    ave_point();
    find_point();
    use_continue();
    return 0;
}