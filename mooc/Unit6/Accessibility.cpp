#include <iostream>

using namespace std;

class Base {
public:
    int i{0};
protected:
    int j{0};
private:
    int k{0};
};

class Pub : public Base {
public:
    void show() {
        // 不能访问父类的私有成员
        i++;
        j++;
    }
};

class Pro : protected Base {
public:
    void show() {
        i++;
        j++;
    }
};

class Pri : private Base {
public:
    void show() {
        i++;
        j++;
    }
};

int main() {
    //通过子类对象访问父类的成员
    Pub pub;
    Pro pro;
    Pri pri;
    //只有pub能访问父类的公有成员
    //protect继承变成了protect成员
    //private继承变成了private成员
    pub.i++;
    return 0;
}
