//
// Created by itsuy on 2021/1/6.
//
#include <iostream>
#include <string>
#include "Person.hpp"
/*
 * 测试拷贝构造,构造,析构函数
 * */

using namespace std;

void show(const Person& person){
    cout << person << endl;
//    person.showName();
//    person.showMoney();
}

int main() {
    Person p{"li"};
//    p.showName();
    auto p2 = p;
    p2.addMoney(10).addMoney(10);
    cout << p2 << endl;

    show(p2);
    return 0;
}
