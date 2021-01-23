#include <iostream>

using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base" << endl;
    }

    //表明这是一个纯虚函数
    virtual void say() = 0;
};

class Pub : public Base {
public:
    void say() override {
        cout << "Pub say" << endl;
    }

    void show() override {
        cout << "Pub show" << endl;
    }

};

int main() {
    //通过子类对象访问父类的成员
    Pub pub;
    pub.show();
    pub.say();
    return 0;
}
