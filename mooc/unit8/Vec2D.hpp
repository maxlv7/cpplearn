//
// Created by itsuy on 2021/1/26.
//

#ifndef CPPLEARN_VEC2D_HPP
#define CPPLEARN_VEC2D_HPP

#include <string>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

class Vec2D {
private:
    double x_;
    double y_;
public:
    Vec2D() = default;

    Vec2D(double x, double y) : x_(x), y_(y) {

    };
public:
    //重载流操作输入符
    //重载为成员函数
    ostream &operator<<(ostream &os) {
        os << "类成员<<" << endl;
        return os;
    }

    friend ostream &operator<<(ostream &os, Vec2D &vec2D) {
        os << "(" << vec2D.x_ << "," << vec2D.y_ << ")" << endl;
        return os;
    }

public:
    //重载一元的运算符(-)
    //作为对象成员的一元运算符无参数
    Vec2D operator-() const {
        return Vec2D(-this->x_, -this->y_);
    }

    //前置++
    Vec2D &operator++() {
        x_ += 1;
        y_ += 1;
        return *this;
    }

    //后置++
    Vec2D operator++(int dummy) {
        Vec2D temp{*this};
        x_ += 1;
        y_ += 1;
        return temp;
    }

    //重载二元的运算符(+,-,*,/)
    Vec2D operator+(Vec2D &vec2D) const {
        return this->add(vec2D);
    }

    Vec2D operator+(double other) const {
        return Vec2D(this->x_ + other, this->y_ + other);
    }

    Vec2D operator-(Vec2D &vec2D) const {
        return Vec2D(this->x_ - vec2D.x_, this->y_ - vec2D.y_);
    }

    // 重载二元的复合运算符(+=,-=,*=,/=)
    Vec2D &operator+=(const Vec2D &other) {
        this->x_ += other.x_;
        this->y_ += other.y_;
        return *this;
    }

    // 这里需要访问Vec2D类的私有成员函数
    friend Vec2D operator+(double other, Vec2D &vec2D) {
        auto x = vec2D.x_ + other;
        auto y = vec2D.y_ + other;
        return Vec2D(x, y);
    }

public:
    Vec2D add(Vec2D &vec2D) const {
        auto x = this->x_ + vec2D.x_;
        auto y = this->y_ + vec2D.y_;
        return Vec2D(x, y);
    };

    Vec2D add(double other) const {
        return Vec2D(this->x_ + other, this->y_ + other);
    };

    double at(int i) const {
        if (i == 0) {
            return x_;
        } else if (i == 1) {
            return y_;
        } else {
            throw out_of_range("at() only accept 1 or 2 as parameter...");
        }
    };

    int compareTo(Vec2D &vec2D) const {
        auto m1 = this->magnitude();
        auto m2 = vec2D.magnitude();
        if (abs(m1 - m2) < 1e10) {
            return 0;
        } else {
            return (m1 > m2 ? 1 : -1);
        }
    };

    Vec2D &decrease() {
        x_--;
        y_--;
        return *this;
    };

    double direction() const {
        return atan(y_ / x_);
    };

    double dot(Vec2D &vec2D) const {
        auto x = this->x_ * vec2D.x_;
        auto y = this->y_ * vec2D.y_;
        return x + y;
    };

    int equals(Vec2D &vec2D) const {
        return 0;
    };

    Vec2D &increase() {
        x_++;
        y_++;
        return *this;
    };

    double magnitude() const {
        return sqrt(x_ * x_ + y_ * y_);
    };

    Vec2D multiply(double other) const {
        auto x = this->x_ * other;
        auto y = this->y_ * other;
        return Vec2D(x, y);
    };

    Vec2D negative() const {
        return Vec2D(-x_, -y_);
    };

    Vec2D subtract(Vec2D &vec2D) {
        auto x = this->x_ - vec2D.x_;
        auto y = this->y_ - vec2D.y_;
        return Vec2D(x, y);
    };

    Vec2D subtract(double val) {
        auto x = this->x_ - val;
        auto y = this->y_ - val;
        return Vec2D(x, y);
    };

    string toString() const {
        string string1;
        string1.append("Vec2D: ");
        string1.append("(");
        string1.append(::to_string(this->x_));
        string1.append(",");
        string1.append(::to_string(this->y_));
        string1.append(")");
        return string1;
    };

};


#endif //CPPLEARN_VEC2D_HPP
