#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    try {
        cout << "1. int型の例外, 2.double型の例外, 3.string型の例外: ";
        cin >> n;
        if (n == 1) throw -1;  // int型の例外を投げる
        if (n == 2) throw -123.456;  // double型の例外を投げる
        if (n == 3) throw string("文字列");  // string型の例外を投げる
        // ""だけで渡すとchar型になる
    }
    catch (int num) {
        cout << "int型の例外: " << num << endl; 
    } catch (...) {
        cout << "int型以外の例外" << endl;
    }

    return 0;
}
