#include <iostream>

using namespace std;

class Date {
private:
    int year{2021}, month{1}, day{1};
public:
    friend void print(const Date &d);

    // Kid 类可以访问 Date类的私有成员
    friend class Kid;
};

class Kid {
private:
    Date date;
public:
    Kid() {
        cout << "I was born in " << date.year << endl;
    }
};

void print(const Date &d) {
    // 可以访问Date类的私有成员
    cout << d.year << "/" << d.month << "/" << d.day << endl;
}

int main() {
    Kid{};
    print(Date{});
    return 0;
}
