#include <iostream>
#include <memory>


using namespace std;

void foo(std::shared_ptr<int> i) {
//    (*i)++;
    std::cout << *i << std::endl;
    // 获取原始指针
    std::cout << (i.get()) << std::endl;
    std::cout << *(i.get()) << std::endl;
}

class A {
public:
    A(int i, int i1) {
        cout << "i*i = " << i * i1 << endl;
    };

    ~A() {
        cout << "Delete A" << endl;
    }

    void show() {
        cout << "show A" << endl;
    }
};

typedef shared_ptr<A> ptrA;

// 这里模拟使用一个类,其中有A的指针成员
class ManageA {
public:
    //初始化A的指针成员
    ptrA ptrA1;

    void show(const ptrA &conn) {
        cout << "conn count: " << conn.use_count() << endl;
        conn->show();
    }

};

int main() {
    auto v{10};
    foo(std::make_shared<int>(v));
    cout << &v << endl;
    cout << v << endl;
    cout << "-----------" << endl;
    auto p1 = make_shared<int>(10);
    auto p2 = p1; //引用计数+1
    auto p3 = p1; //引用计数+1
    cout << "p1 count: " << p1.use_count() << endl;
    int *p = p1.get(); //不会增加引用记数
    // 减少引用记数
    p2.reset();
    // 这里就获取不到p2了
    if (p2.get()) {
        cout << "p2" << endl;
    }
    cout << "p1 count: " << p1.use_count() << endl;
    //手动管理资源的方式
    A *aa = new A{1, 2};
    delete aa;
    //用智能指针管理A
    auto pa = make_shared<A>(1, 2);
    pa->show();
    //使用A的指针成员
    // 这里其实就是A* a = new A{1,2} , a->show();
    shared_ptr<A> a = make_shared<A>(1, 2);
    a->show();
    // 指针做为其它类的成员
    ManageA manageA;
    //conn 相当于A * conn = new A{3,4};
    auto conn = make_shared<A>(3, 4);
    manageA.show(conn);
    cout << "end main" << endl;
    return 0;
}