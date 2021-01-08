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

int main() {
    Person p{"li"};
    p.showName();
    Person p1{"li1"};
    p1.showName();
    // 复制
    p = p1;
    p.showName();
    Person{"li_an"}.showName();
    Person{}.showName();
    //拷贝列表初始化的方式赋值
    Person p_copy= {"copy"};
    p_copy.showName();
    // 测试析构函数
    auto *pp = new Person{};
    delete pp;
    return 0;
}
