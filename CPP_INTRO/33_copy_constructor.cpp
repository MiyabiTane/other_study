#include <iostream>
using namespace std;

// MyClassの定義と実装
class MyClass {
    private:
        int data;
    public:
        int getData() {
            return this->data;
        }
        // コンストラクタ
        MyClass(int data) {
            cout << "コンストラクタが呼び出されました" << endl;
            this->data = data;
        }
        // デストラクタ
        ~MyClass() {
            cout << "デストラクタが呼び出されました" << endl;
        }
        // コピーコンストラクタ
        // これを記述しなくてもデフォルトコピーインストラクタが作られる
        MyClass(const MyClass &obj) {
            cout << "コピーコンストラクタが呼び出されました" << endl;
            this->data = obj.data;
        }
};

int main() {
    MyClass obj1(123);
    MyClass obj2 = obj1;

    cout << "obj1のメンバ関数のdataの値: " << obj1.getData() << endl;
    cout << "obj2のメンバ関数のdataの値: " << obj2.getData() << endl;

    return 0;
}