// g++ 20_Account_main.cpp 20_Account.cpp -o out
// 口座番号にはセッタがないため後から書き込みができない->データ保護
#include <iostream>
#include <string>
using namespace std;
#include "20_Account.h"

int main() {
    Account act("12345678", 10000);

    cout << "口座番号: " << act.getNumber();
    cout << ", 残高: " << act.getBalance() << endl;

    act.setBalance(30000);

    cout << "口座番号: " << act.getNumber();
    cout << ", 残高: " << act.getBalance() << endl;

    act.setBalance(-30000);

    cout << "口座番号: " << act.getNumber();
    cout << ", 残高: " << act.getBalance() << endl;

    return 0;
}