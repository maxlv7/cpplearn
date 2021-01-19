#pragma once

#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string name{"Not Init"};
    int total_money{0};
public:
    // 构造方法
    Person();

    // 析构方法
    ~Person();

    // 有参构造函数
    Person(const string &name);

    Person(int totalMoney);

    Person(const string &name, int totalMoney);

    // 拷贝构造
    Person(const Person &other);

    // 普通成员函数
    void showName() const;

    void showMoney() const;

    Person &addMoney(int money);

    // 重写流输出
    friend ostream &operator<<(ostream &os, const Person &person);

};

Person::Person(const string &name) : name(name) {
    cout << "Person {name}构造函数调用" << endl;
}

Person::Person() {
    cout << "Person {无参}构造函数调用" << endl;
}

Person::Person(int totalMoney) : total_money(totalMoney) {
    cout << "Person {totalMoney}构造函数调用" << endl;
}

//构造函数初始化列表
Person::Person(const string &name, int totalMoney) : name(name), total_money(totalMoney) {
    cout << "Person {name,totalMoney}构造函数调用" << endl;
}

void Person::showMoney() const {
    cout << "now money is : " << total_money << endl;

}

void Person::showName() const {
    if (!this->name.empty()) {
        cout << this->name << endl;
    } else {
        cout << "no name" << endl;
    }
}

Person &Person::addMoney(int money) {
    this->total_money += money;
    return *this;
}

Person::~Person() {
    cout << "Person析构函数调用" << name << "|"<< total_money << endl;
}

Person::Person(const Person &other) {
    cout << "Person拷贝构造函数调用" << endl;
    this->name = other.name;
    this->total_money = other.total_money;
}

ostream &operator<<(ostream &os, const Person &person) {
    os << "name: " << person.name << " total_money: " << person.total_money;
    return os;
}



