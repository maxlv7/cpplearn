#include <iostream>
#include "Person.hpp"

using namespace std;

/*
 *c++ 11的类初始化
 *成员的初始化次序
 * 执行次序： 就地初始化 ->Ctor 初始化列表 -> 在Ctor 函数体中为成员赋值
 * 若一个成员同时有就地初始化和构造函数列表初始化，则就地初始化语句被忽略不执行
 **/

class A {
public:
    Person person; //如果没有构造函数初始化列表,那么在创建A对象时会调用Person的无参构造函数
    A(const string &name, int money) {
        cout << "A的{name,money}构造函数" << endl;
        //call copy constructor?
        // 这里调用了p1的析构函数
        person = Person(name, money);
        cout << person << endl;
    };

    A(const string &name) : person(name) {
        cout << "A的{name}构造函数" << endl;
        cout << person << endl;
    }
};


int main() {
    A a{"aaaa", 123};
//    a.person.showName();
    cout << "----------------------" << endl;
    A b{"bbbb"};
    cout << "----------------------" << endl;
    return 0;
}