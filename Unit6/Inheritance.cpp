#include <iostream>
#include "Person.hpp"
#include <string>

using namespace std;
using namespace string_literals;


//C++11:派生类不继承的特殊函数
//(1)析构函数
//(2)友元函数
class Man : public Person {
private:
    int high{};
public:
    //继承所有基类ctor，但是不能指定是哪个ctor
    using Person::Person;

    Man(string name, int age);

    Man(string name, int age, int high);
//    void say(){
//        cout << "high: " << high  << endl;
//    }
};

Man::Man(string name, int age, int high) : Person(name, age) {
    cout << "Man(name,age,high)" << endl;
    this->high = high;
    this->say();
}

Man::Man(string name, int age) : Person(name, age) {
    cout << "Man(name,age)" << endl;
}

int main() {
//    Person("Person",34).say();
    Man m{"Man", 23};
    m.say();
    Man{"man2", 23, 123};
    return 0;
}