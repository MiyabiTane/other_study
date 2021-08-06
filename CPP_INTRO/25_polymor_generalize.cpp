#include <iostream>
#include <string>
using namespace std;

// 抽象クラス：インスタンス生成不可
class Animal {
    protected:
        string name;
    public:
        // 純粋仮想関数：プロトタイプは決められるが処理内容は記述できない関数
        // = 0：この関数は呼び出せないという意味
        virtual void speak() = 0;
        Animal(string name);
};

class Dog : public Animal {  // Animalが親クラス
    public:
        void speak();
        Dog(string name);
};

class Cat : public Animal {
    public:
        void speak();
        Cat(string name);
};

// 動物を表すクラスのコンストラクタ
Animal::Animal(string name) {
    this->name = name;
}

void Dog::speak() {
    cout << this->name << ": ワン！" << endl;
}

// 犬を表すクラスのコンストラクタ
Dog::Dog(string name) : Animal(name) {
}

void Cat::speak() {
    cout << this->name << ": ニャン！" << endl;
}

// 猫を表すクラスのコンストラクタ
Cat::Cat(string name) : Animal(name) {
}

// Animalクラスのポインタを引数としたsub関数
void sub(Animal *p) {
    p->speak();
}

int main() {
    const int DATA_NUM = 5;
    // 抽象クラスのポインタの配列
    // Animalクラスがあるから２種の動物を同じ配列に入れることができる
    Animal *p[DATA_NUM];

    p[0] = new Dog("ポチ");
    p[1] = new Cat("タマ");
    p[2] = new Dog("シロ");
    p[3] = new Cat("ミケ");
    p[4] = new Dog("クロ");

    for (int i = 0; i < DATA_NUM; i++) {
        p[i] -> speak();
    }

    return 0;

    /* 犬と猫のインスタンス生成
    Dog pochi("ポチ");
    Cat tame("タマ");

    sub(&pochi);
    sub(&tame);

    return 0;
    */
}
