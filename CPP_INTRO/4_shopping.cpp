#include <iostream>
using namespace std;

int main() {
    int money;  // 残金
    int price;  // 買い物金額

    money = 10000;
    while (money > 0) {
        cout << "残金: " << money << "円" << endl;
        cout << "買い物金額を入力して下さい: ";
        cin >> price;

        money -= price;
    }
    cout << "買い物終了" << endl;

    return 0;
}