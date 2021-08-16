#include <iostream>
using namespace std;

template <class T> class MyTriangle {
    private:
        T bottom;  // 底辺
        T height;  // 高さ
    public:
        MyTriangle(T bottom, T height) {  // コンストラクタ
            this->bottom = bottom;
            this->height = height;
        }
        T getArea() {
            return this->bottom * this->height / 2;
        }
};

template <class T1, class T2> class MyTriangle_2 {
    private:
        T1 bottom;
        T2 height;
    public:
        MyTriangle_2(T1 bottom, T2 height) {
            this->bottom = bottom;
            this->height = height;
        }
        T1 getArea() {
            return this->bottom * this->height / 2;
        }
};

int main() {
    // int型でMyTriangleを使う
    MyTriangle<int> iObj(10, 20);
    cout << "int型の三角形の面積: " << iObj.getArea() << endl;

    // double型でMyTriangleを使う
    MyTriangle<double> dObj(30.0, 40.0);
    cout << "double型の三角形の面積: " << dObj.getArea() << endl;

    // int, double型でMyTriangle_2で使う
    MyTriangle_2<int, double> idObj(3, 4.0);
    int ans = idObj.getArea();
    cout << typeid(ans).name() << " 三角形の面積: " << ans << endl; 

    return 0; 
}
