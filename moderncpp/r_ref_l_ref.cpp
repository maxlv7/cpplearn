#include <iostream>
#include <string>

using namespace std;


void reference(std::string &str) {
    std::cout << "左值" << std::endl;
}

void reference(std::string &&str) {
    std::cout << "右值" << std::endl;
}

int main() {
    // r ->reference, rr->right value reference
    string a1 = "a1"; // a1是一个左值
//    string && rr_a1 = a1; //右值引用不能引用左值
    string &&rr_a1_1 = move(a1); //move可以把左值无条件转为右值
    rr_a1_1 += "test"; //rr_a1_1任然是一个左值，所以对它修改也就修改了原来的a1
    cout << "rr_a1_1: " << rr_a1_1 << endl;
    cout << "a1: " << a1 << endl;

    const string &r_a2 = a1 + a1; //常量左值引用能够延长临时变量的生命周期
    cout << "r_a2: " << r_a2 << endl;

    string &&rr_a3 = a1 + r_a2; // 右值引用延长临时变量的生命周期
    rr_a3 += "Test"; //合法,非常量引用能够修改临时变量
    cout << "rr_a3: " << rr_a3 << endl;

    reference(rr_a3);

    // int &a = std::move(1);    // 不合法，非常量左引用无法引用右值
    const int &b = move(1); // 合法, 常量左引用允许引用右值
    std::cout << b << std::endl;
    return 0;
}