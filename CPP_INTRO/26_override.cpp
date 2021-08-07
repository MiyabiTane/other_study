#include <iostream>
#include <string>
using namespace std;

class Human {
    protected:
        string name;
    public:
        // 仮想関数：戻り値なし、純粋仮想関数：戻り値 = 0
        virtual void speak();
        void speakWithDecoration();
        Human(string name);  
};

void Human::speak() {
    cout << "氏名：" << this->name << endl;
}


void Human::speakWithDecoration() {
    cout << "==============" << endl;
    this->speak();
    cout << "==============" << endl;
}

Human::Human(string name) {
    this->name = name;
}

class Student : public Human {
    protected:
        string number;
    public:
        void speak();
        Student(string name, string number);
};

Student::Student(string name, string number) :
Human(name) {
    this->number = number;
}

// オーバーライド（上書き）
void Student::speak() {
    //  cout << "氏名：" << this->name << endl;
    Human::speak();
    cout << "学籍番号：" << this->number << endl;
}

int main() {
    Student yamada("山田一郎", "ABC123456");
    yamada.speak();
    // speak関数が仮想関数であればStudent::speakが呼び出される
    // そうでなければHuman::speakが呼び出される
    yamada.speakWithDecoration();

    return 0;
}