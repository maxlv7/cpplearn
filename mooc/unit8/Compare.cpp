#include "Vec2D.hpp"
#include <iostream>

class Test {
private:
    int v;
public:
    Test(const Test &test) {
        cout << "Test(const Test& test)" << endl;
        this->v = test.v;
    }

    Test(Test &test) {
        cout << "Test(Test& test)" << endl;
        this->v = test.v;
    }

    Test &operator=(const Test &test) {
        cout << "Test&operator=(const Test& test)" << endl;
        this->v = test.v;
        return *this;
    }

    Test &operator=(Test &test) {
        cout << "Test&operator=(Test& test)" << endl;
        this->v = test.v;
        return *this;
    }

    Test() = default;
};

int main() {
    Test t1{};
    Test t2{t1};
    // 调用的是拷贝构造函数
    Test t3 = t2;
    // 调用的是重载的=运算符
    t1 = t3;
    return 0;
}
