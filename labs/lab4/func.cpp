#include "header.h"

Vector::Vector(string name, int x, int y) : name(std::move(name)), x(x), y(y), length(getLength()) {}

Vector::Vector() {
    name = "V2";
    x = 5;
    y = 7;
    length = getLength();
}

Vector::Vector(int x, int y) : x(x), y(y) {}

ostream &operator<<(ostream &os, const Vector &vector) {
    os << vector.name << " (" << vector.x << ", " << vector.y << ")";
    return os;
}

Vector Vector::operator-(const Vector &vector) const {
    int vx = x - vector.x;
    int vy = y - vector.y;
    return {vx, vy};
}

Vector Vector::operator*(int multiplier) const {
    int vx = x * multiplier;
    int vy = y * multiplier;
    return {name, vx, vy};
}

double Vector::getLength() const {
    return sqrt((x * x) + (y * y));
}

int Vector::getX() const {
    return x;
}

int Vector::getY() const {
    return y;
}

string Vector::getName() {
    return name;
}

void Vector:: setName(const string &string) {
    name = string;
}

Vector create(const string &name) {
    int x, y;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    return {name, x, y};
}
