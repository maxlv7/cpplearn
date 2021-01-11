#include <iostream>

using namespace std;

// c++ 11 代理构造

class A { ;
public:
    A() : A(3) {}

    A(int i) : A(i, 5) {};

    A(int a, int b) {
        cout << a + b << endl;
    }
};

int main() {
    // 执行顺序 A() -> A(int i) -> A(int a, int b)
    A{};
    return 0;
}
