#include <iostream>
#include <string>
using namespace std;

class Person {
    private:
        string name;
    public:
        void speak();
        void speak(string decolation);
        Person(string name);
};

void Person::speak() {
    cout << this->name << endl;
}

void Person::speak(string decolation) {
    cout << decolation << endl;
    cout << this->name << endl;
    cout << decolation << endl;
}

Person::Person(string name) {
    this->name = name;
}

int main() {
    Person p("山田一郎");
    p.speak();
    p.speak("----------");

    return 0;
}