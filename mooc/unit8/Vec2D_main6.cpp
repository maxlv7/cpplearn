#include "Vec2D.hpp"
#include <iostream>


int main() {

    Vec2D v1(3, 4), v2{4, 6};
    //重载=运算符
    //默认情况下，进行1对1的成员拷贝
    v1 = v2;
    v1.operator=(v2);
    cout << v1;
    cout << v2;
    return 0;
}
