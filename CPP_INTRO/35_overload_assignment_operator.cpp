#include <iostream>
using namespace std;

class PtrClass {
    public:
        int *ptr;  // ポインタのメンバ変数

        PtrClass() {  // コンストラクタ
            cout << "コンストラクタが呼び出されました" << endl;
            this->ptr = new int[3];
        }

        ~PtrClass() {  // デストラクタ
            cout << "デストラクタが呼び出されました" << endl;
            delete[] ptr;
        }

        PtrClass &operator=(const PtrClass &obj) {  // 代入演算子のオーバーロード
            cout << "代入演算子のオーバーロード" << endl;
            this->ptr[0] = obj.ptr[0];
            this->ptr[1] = obj.ptr[1];
            this->ptr[2] = obj.ptr[2];
            return *this;  // *this: オブジェクトそのもの
        }
};


int main() {
    PtrClass obj1;
    obj1.ptr[0] = 123;
    obj1.ptr[1] = 456;
    obj1.ptr[2] = 789;

    PtrClass obj2;
    obj2.ptr[0] = 111;
    obj2.ptr[1] = 222;
    obj2.ptr[2] = 333;
    cout << "----------------" << endl;
    cout << "obj2.ptr[0]の値: " << obj2.ptr[0] << endl;
    cout << "obj2.ptr[1]の値: " << obj2.ptr[1] << endl;
    cout << "obj2.ptr[2]の値: " << obj2.ptr[2] << endl;

    //obj2にobj1を代入する
    obj2 = obj1;

    cout << "-----------------" << endl;
    cout << "obj1のメンバ変数ptrの値: " << obj1.ptr << endl;
    cout << "obj1の中身の値: " << obj1.ptr[0] << ", " << obj1.ptr[1] 
         << ", " << obj1.ptr[2] << endl;
    cout << "obj2のメンバ変数ptrの値: " << obj2.ptr << endl;
    cout << "obj2の中身の値: " << obj2.ptr[0] << ", " << obj2.ptr[1]
         << ", " << obj2.ptr[2] << endl;
    cout << "------------------" << endl;

    return 0;
}
