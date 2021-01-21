#include <iostream>

using namespace std;

class Base {
public:
    virtual void show() {
        cout << "i am base" << endl;
    }
};

class A : public Base {
public:
    void show() override {
        cout << "i am A" << endl;
    }
};

class B : public Base {
public:
    void show() override {
        cout << "i am B" << endl;
    }
};

void print(Base *p) {
    p->show();
}

int main() {

    A a;
    B b;
    //指针形式
    print(&a);
    print(&b);
    //引用形式
    Base &r1 = a;
    Base &r2 = b;
    r1.show();
    r2.show();
    return 0;
}
