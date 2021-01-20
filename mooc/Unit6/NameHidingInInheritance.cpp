#include <iostream>
#include <string>

using namespace std;

class A {
public:
    A &say() {
        cout << "I am A" << endl;
        return (*this);
    }

    void show(string name) {
        cout << "show A " << name << endl;
    }
};

class B : public A {
public:
    using A::say;
    using A::show;

    B &say(string name) {
        cout << "I am B " << name << endl;
        return (*this);
    }

    void show() {
//        show("name");
        cout << "show B" << endl;
    }
};

int main() {
//    B {}.say("name").say();
    //通过子类调用类A的show方法
    B b{};
    b.A::show("Test with A::show");
    b.show("Test Using A::show");
    static_cast<A>(b).show("Test Cast");

    //
    return 0;
}
