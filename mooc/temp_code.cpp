#include <iostream>

using namespace std;
struct Test {
    const char *s;
};


auto *set() {
    auto *m = new Test();
    const char *aaa = "aaaaa";
    m->s = aaa;
    return m;
}

int main() {
    cout << set()->s << endl;
    return 0;
}
