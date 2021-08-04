#include <iostream>
#include <string>
using namespace std;
#include "20_Account.h"
#include "22_AccountEx.h"

string AccountEx::getName() {
    return this->name;
}

AccountEx::AccountEx(string number, string name, int balance) : Account(number, balance) {
    this-> name = name;
}
