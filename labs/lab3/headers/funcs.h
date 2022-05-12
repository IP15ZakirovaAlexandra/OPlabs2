#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Straight {
    int a;
    int b;
    int c;
    string str;
    int num;
public:
    int getA() const { return a; }
    int getB() const { return b; }
    int getC() const { return c; }
    string getStr() const { return str; }
    int getNum() const { return num; }

    Straight(const int &i, const int &j, const int &k, const int &number);
};

vector<Straight> CreateLines(vector<Straight> vec);

void printVec(const vector<Straight> &vec);

void findCrossing(const vector<Straight> &vec);

