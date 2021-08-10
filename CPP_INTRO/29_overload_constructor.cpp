#include <iostream>
#include <string>
using namespace std;

class Pupil {
    private:
        string name;
        int point;
    public:
        void speak();
        Pupil(string name, int point);  // コンストラクタ2
        Pupil();  // デフォルトコンストラクタ
};

void Pupil::speak() {
    cout << "氏名: " << this->name << endl;
    cout << "得点: " << this->point << endl;
}

Pupil::Pupil() {
    this->name = "未設定";
    this->point = 0;
}

Pupil::Pupil(string name, int point) {
    this->name = name;
    this->point = point;
}

int main() {
    Pupil p1;  // デフォルトコンストラクタ
    Pupil p2("山田一郎", 95);

    p1.speak();
    p2.speak();

    return 0;
}

/*
class Pupil {
    private:
        string name;
        int point;
    public:
        void speak();
        Pupil(string name, int point);  // (*)
};

void Pupil::speak() {
    cout << "氏名: " << this->name << endl;
    cout << "得点: " << this->point << endl;
}

// (*)
Pupil::Pupil(string name, int point) {
    this->name = name;
    this->point = point;
}

// (*)の部分をコメントアウトすればコンストラクタが自動生成される
int main1() {
    Pupil p;
    return 0;
}
*/


