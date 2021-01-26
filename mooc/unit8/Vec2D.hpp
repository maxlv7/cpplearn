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
