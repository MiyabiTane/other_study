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

    // 代入ではコピーコンストラクタが呼び出されないチェック
    cout << endl;
    MyClass obj3(123);
    cout << "obj3のメンバ変数dataの値: " << obj3.getData() << endl;
    cout << "----------------" << endl;

    MyClass obj4(456);
    cout << "obj4のメンバ変数dataの値（代入前）: " << obj4.getData() << endl;
    cout << "-----------------" << endl;

    obj4 = obj3;
    cout << "obj4のメンバ変数dataの値（代入後）: " << obj4.getData() << endl;

    return 0;
}