#include <iostream>

using namespace std;

class A {
private:
    int a{5}, b{6};
public:
    A(A &other) {
        cout << "没有const" << endl;
    }

    A(const A &other) {
        cout << "有const" << endl;
    }


    A() = default;
};

class B {
public:
    //c++ 11带有额外默认参数的拷贝构造函数
    B(B &other) {
        cout << "没有const 带有额外默认参数" << endl;
    }

    B() = default;
};

int main() {
    A a;
    // 调用拷贝构造
    A b = a;
    auto c = a;
    auto m1{a};
    auto m2 = {a};
    //不调用拷贝构造
    A d, e;
    d = e;
    //
    B bb;
    auto cc{b};

    return 0;
}
