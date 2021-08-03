#include <iostream>
#include <string>
using namespace std;
#include "20_Account.h"

string Account::getNumber() {
    return this->number;
}

int Account::getBalance() {
    return this->balance;
}

void Account::setBalance(int balance) {
    if (balance >= 0){
        this->balance = balance;
    }
}

// コンストラクタ
Account::Account(string number, int balance) {
    this->number = number;
    this->balance = balance;
}
