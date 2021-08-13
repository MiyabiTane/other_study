// g++ 37_MyCircle.cpp 37_MyCircle_main.cpp -o out
#include <iostream>
using namespace std;

class MyCircle {
    private:
        double r;
    public:
        MyCircle(double r) {
            this->r = r;
        }
        double getArea() {
            return this->r * this->r * 3.14;
        }
};

int main() {
    MyCircle obj(10);
    cout << "半径10の円の面積: " << obj.getArea() << endl;

    return 0;
}
