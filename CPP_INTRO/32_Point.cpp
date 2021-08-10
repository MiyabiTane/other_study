#include <iostream>
using namespace std;
#include "32_Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

Point Point::operator+(const Point &p) {  // +演算子のオーバーロード
    Point ans(this->x + p.x, this->y + p.y);
    return ans;
}

Point Point::operator-(const Point &p) {  // -演算子のオーバーロード
    Point ans(this->x - p.x, this->y - p.y);
    return ans;
}

bool Point::operator==(const Point &p) {  // ==演算子のオーバーロード
    return this->x == p.x && this->y == p.y;
}

bool Point::operator!=(const Point &p) {  // !=演算子のオーバーロード
    return !(*this==p);  // *this: このインスタンス
}

// istramはcinオブジェクトのデータ型
istream &operator>>(istream &is, Point &p) {  // >>演算子のオーバーロード
    is >> p.x >> p.y;
    return is;
}

// ostramはcoutオブジェクトのデータ型
ostream &operator<<(ostream &os, const Point &p) {  // <<演算子のオーバーロード
    os << "x = " << p.x << ", y = " << p.y;
    return os;
}
