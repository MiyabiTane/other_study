#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = " << argv[i] << endl; 
    }

    // 10進数の0~15を2桁の16進数で表示するプログラム
    for (char data = 0; data <= 15; data++) {
        // setw(2): 2桁であることを示す
        // setfoll('0'): 上位桁を0で埋める
        // hex: 16進数
        // uppercase: a~fを大文字に
        cout << setw(2) << setfill('0') << hex << uppercase << ((int)data & 0xff) << ' ';
    }
    cout << endl;

    return 0;
}