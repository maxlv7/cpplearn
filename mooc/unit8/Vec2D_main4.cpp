#include "Vec2D.hpp"
#include <iostream>

int main() {
    Vec2D v1(3, 4), v2{4, 6};
    //重载流操作运算符(<<,>>)
    cout << v1;
    // 二元操作运算符
    operator<<(cout, v1);
    //v1只能做为一个操作数
    v1 << cout;
    v1.operator<<(cout);

    return 0;
}
