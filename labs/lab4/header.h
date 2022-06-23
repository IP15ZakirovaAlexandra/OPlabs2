#pragma once
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

class Vector {

private:
    string name = "V3";
    int x;
    int y;
    double length = getLength();

public:
    Vector(string name, int x, int y);
    Vector();
    Vector(int x, int y);
    friend ostream &operator<<(ostream &os, const Vector &vector);
    Vector operator-(const Vector &vector) const;
    Vector operator*(int) const;
    double getLength() const;
    int getX() const;
    int getY() const;
    string getName();
    void setName(const string &string);
};

Vector create(const string &name);
