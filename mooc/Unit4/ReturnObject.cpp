#include <iostream>
#include "Person.hpp"

int main() {
    // 对象返回本身的引用
    Person p{"li",0};
    p.addMoney(1).addMoney(1);
    p.showMoney();
    return 0;
}
