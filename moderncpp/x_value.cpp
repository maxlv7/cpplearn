#include <iostream>
/*
 * c++ 左值,右值,纯右值,将亡值
 * */


using namespace std;

//测试将亡值
struct Sum {
    Sum() {
        cout << "ctor" << endl;
    }

    Sum(initializer_list<int> f) {
        cout << "ctor initializer_list" << endl;
        int sum = 0;
        for (auto v:f) {
            sum += v;
        }
        cout << "sum =" << sum << endl;
    }

    ~Sum() {
        cout << "dtor" << endl;
    }
};

Sum Test() {
    Sum temp;
//    return temp;
    return static_cast<Sum &&>(temp);
}

Sum my_sum(initializer_list<int> f) {
    Sum temp = f;
    // 这里做了隐式右值转换 等价于static_cast<Sum &&>(temp);
    return temp;
//    return static_cast<Sum &&>(temp); // 会执行两次析构函数
}

int main() {
    // m是左值 my_sum的返回值是右值(纯右值)
    // m会将my_sum的返回值进行移动(移动语义)
//    Sum m = my_sum({1, 2, 3, 4, 5});
    Sum test = Test();
    return 0;
}