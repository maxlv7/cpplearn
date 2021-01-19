#include <iostream>
#include <cassert>
#include <array>

using namespace std;
//任务1∶用递归计算factorial，用assert检查3的阶乘
//任务2:将factorial变成常量表达式，用static_assert检查3的阶乘;
// 任务3:创建factorial(4)大小的数组

constexpr int factorial(int n) {
    if (n == 0) {
        return 1;//error
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
//    int x = 3;
    static_assert(factorial(3) == 6,"factorial(3) should be 6");

    array<int, factorial(4)> a{1,2,3};
    cout << a.size() << endl;
    assert(factorial(3) == 6);
    return 0;
}
