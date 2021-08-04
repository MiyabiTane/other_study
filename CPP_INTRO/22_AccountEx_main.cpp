#include <iostream>
#include <string>
using namespace std;
#include "20_Account.h"
#include "22_AccountEx.h"

int main() {
    AccountEx act("12345678", "山田一郎", 10000);

    cout << "口座番号: " << act.getNumber() << endl;
    cout << "口座名義人: " << act.getName();
    cout << " , 残高" << act.getBalance() << endl;

    return 0;
}