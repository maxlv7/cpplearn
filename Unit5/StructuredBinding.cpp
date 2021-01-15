#include <iostream>

using namespace std;

class C {
public:
    int a{0};
    int b{1};
};

int main() {
    C c;
    auto[x, y]{c};
    cout << x << y << endl;
    int array[]{1, 2, 3};
    auto[a1, a2, a3] = array;
    cout << a1 << a2 << a3 << endl;
    const auto[b1, b2, b3](array);
    cout << b1 << b2 << b3 << endl;
    auto &[c1, c2, c3]{array};
    c1 = 999;
    cout << c1 << c2 << c3 << endl;

    return 0;
}
