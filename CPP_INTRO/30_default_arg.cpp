#include <iostream>
#include <string>
using namespace std;

class Pupil {
    private:
        string name;
        int point;
    public:
        void speak();
        // デフォルト引数をつけることで引数なしのコンストラクタの役割も果たす
        Pupil(string name = "未設定", int point = 0);    
};

// 引数があるコンストラクタの実装
Pupil::Pupil(string name, int point) {
    this->name = name;
    this->point = point;
}

void Pupil::speak() {
    cout << "氏名: " << this->name << endl;
    cout << "得点: " << this->point << endl;
}

int main() {
    Pupil p1;
    Pupil p2("山田一郎", 95);
    Pupil p3("佐藤花子");

    p1.speak();
    p2.speak();
    p3.speak();

    return 0;
}
