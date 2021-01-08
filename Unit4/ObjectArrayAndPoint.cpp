#include <iostream>
#include "Person.hpp"

int main() {
    // 栈上创建对象数组
    Person p[4]{{"1"},
                {"2"},
                {"3"},
                {}};
    int array[4]{1, 2, 3, 4};
    for (const auto &t:p) {
        t.showName();
    }
    //堆上创建对象数组
    auto *p_p = new Person[3]{{"p1"},
                              {"p2"},
                              {}};
    for (int i = 0; i < 3; ++i) {
        p_p->showName();
        p_p++;
    }
    delete[] p_p;
    return 0;
}
