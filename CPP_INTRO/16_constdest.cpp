#include <iostream>
#include <string>
using namespace std;

class TestConstDest {
    private:
        string name;
    public:
        TestConstDest(string name);  // コンストラクタ
        ~TestConstDest();  // デストラクタ
};

// コンストラクタ
TestConstDest::TestConstDest(string name) {
    cout << name << "のコンストラクタが呼び出されました。" << endl;
    this->name = name;
}

// デストラクタ
TestConstDest::~TestConstDest() {
    cout << this->name << "のデストラクタが呼び出されました。" << endl;
}

// グローバルオブジェクトの宣言
TestConstDest globalObj("グローバルオブジェクト");

void sub() {
    cout << "sub関数が呼び出されました。" << endl;
    TestConstDest localObj("ローカルオブジェクト");
    cout << "sub関数の終了" << endl;
    
    return ;
}

int main() {
    cout << "main関数が呼び出されました。" << endl;
    sub();
    sub();
    cout << "main関数を終了します。" << endl;

    return 0;
}

/*
- 実行結果 -
グローバルオブジェクトのコンストラクタが呼び出されました。
main関数が呼び出されました。
sub関数が呼び出されました。
ローカルオブジェクトのコンストラクタが呼び出されました。
sub関数の終了
ローカルオブジェクトのデストラクタが呼び出されました。
sub関数が呼び出されました。
ローカルオブジェクトのコンストラクタが呼び出されました。
sub関数の終了
ローカルオブジェクトのデストラクタが呼び出されました。
main関数を終了します。
グローバルオブジェクトのデストラクタが呼び出されました。
- - - - - - 
グローバル関数▷プログラム起動時に生成され、プログラム終了時に破棄される。
ローカル関数▷関数が呼び出された時に生成され、関数が終了する時に破棄される。
*/