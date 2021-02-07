#include "Vec2D.hpp"
#include <iostream>

int main() {
    Vec2D v1(3, 4), v2{4, 6};
    //重载对象转换运算符
    auto m1 = static_cast<double>(v1);
    auto m2 = static_cast<double>(v2);
    cout << "m1: " << m1 << endl;
    cout << "m2: " << m2 << endl;

    return 0;
}
