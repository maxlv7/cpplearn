#include "Vec2D.hpp"
#include <iostream>

int main() {
    Vec2D v1(3, 4), v2{4, 6};
    //重载二元的运算符(+,-,*,/)
    auto a = v1 + v2; //等价于v1.operator+(v2);
    cout << a.toString() << endl;
    auto b = v1 + 10;
    cout << b.toString() << endl;
    auto c = v1 - v2;
    cout << c.toString() << endl;
    // 因为100没有重载+运算符,所以这里调用的是为的友元函数+
    auto d = 100 + v2;
    cout << d.toString() << endl;


    //重载二元的复合运算符(+=,-=,*=,/=)
    v1 += v2;
    cout << v1.toString() << endl;

    return 0;
}
