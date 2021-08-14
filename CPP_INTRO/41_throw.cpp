#include <iostream>
#include <string>
using namespace std;

int getFee(int age) throw(string) {
    int fee;

    if (age < 0) {  // 異常系の処理: string型が返される
        throw string("マイナスの年齢が指定されました");
    } else if (age > 150) {
        throw string("年齢が大きすぎます");
    }

    if (age < 20) {  // 正常系の処理
        fee = 500;
    } else {
        fee = 1000;
    }

    return fee;
}


int main() {
    int age, fee;

    try {
        cout << "年齢を入力してください";
        cin >> age;
        fee = getFee(age);
        cout << "料金は" << fee << "円です" << endl;
    } catch (string ex) {
        cout << ex << endl;
    }

    return 0;
}