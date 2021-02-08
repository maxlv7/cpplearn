#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<typename T, typename S>
auto add(T a, S b) {
    return a + b;
}

template<typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

//显示实例化
template<int, int>
int max(int, int);

int main() {
    // 隐式实例化模板
    cout << add<int, double>(1, 3.5) << endl;
    cout << add(1, 3.5) << endl;
    cout << ::max(5, 6) << endl;
    return 0;
}

