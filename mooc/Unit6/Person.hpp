//
// Created by itsuy on 2021/1/16.
//

#ifndef CPPLEARN_PERSON_HPP
#define CPPLEARN_PERSON_HPP

#include <string>
#include <iostream>
#include <utility>

using namespace std;

//演示继承的基类
class Person {
private:
    string name;
    int age{};
public:
    void say() {
        cout << "name: " << name << " age " << age << endl;
    }

    Person(string name, int age) : name(name), age(age) {
        cout << "Person(name,age)" << endl;
    }

    Person() { cout << "Person()" << endl; };
};


#endif //CPPLEARN_PERSON_HPP
