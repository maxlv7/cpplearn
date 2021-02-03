#include "Vec2D.hpp"
#include <iostream>

int main() {
    Vec2D v1(3, 4), v2{4, 6};
    //重载一元的运算符(--,++,-)
    auto a = -v1; //等价于v1.operator+(v2);
    cout << a.toString() << endl;
    //重载前置的 ++(返回值是lvalue)
    cout << "++v1: " << (++v1).toString() << endl;
    //重载后置的 ++(返回值是rvalue)
    cout << "v1++: " << (v1++).toString() << endl;
    cout << v1.toString() << endl;

    return 0;
}
