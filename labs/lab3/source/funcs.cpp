#include "../headers/funcs.h"

Straight::Straight(const int &i, const int &j, const int &k, const int &number) {
    a = i;
    b = j;
    c = k;
    num = number;
    str = to_string(a) + "x + " + to_string(b) + "y + " + to_string(c) + " = 0";
}

vector<Straight> CreateLines(vector<Straight> vec) {
    int num = 1;
    for (int i = -3; i < 4; i++) {
        if (i == 0) continue;
        for (int j = -3; j < 4; j++) {
            if (j == 0) continue;
            for (int k = -3; k < 4; k++) {
                vec.push_back(*new Straight(i, j, k, num));
                num++;
            }
        }
    }
    return vec;
}

void printVec(const vector<Straight> &vec) {
    cout << "I create next lines:\n";
    for (auto &i: vec) {
        int num = i.getNum();
        string str = i.getStr();
        cout << setw(5) << num << " line is: " << str << ";\n";
    }
}

void findCrossing(const vector<Straight> &vec) {
    int x, y;
    vector<int> numbers;
    cout << "I need you to enter the coordinates of a point\n";
    cout << " Enter x coordinate: \n";
    cin >> x;
    cout << " Enter y coordinate: \n";
    cin >> y;
    bool found = false;
    for (const auto &line: vec) {
        int a = line.getA();
        int b = line.getB();
        int c = line.getC();
        int left = a * x + b * y + c;
        if (left == 0) {
            found = true;
            int num = line.getNum();
            string str = line.getStr();
            cout << "Your point (" << x << ";" << y
                 << ") belongs to the line #" << num
                 << "   " << str << ";\n";
            numbers.push_back(num);
        }
    }
    if (found) {
        cout << "Numbers of lines to which your point belongs:\n";
        for (auto &num: numbers) {
            cout << num << "  ";
        }
    } else { cout << "Intersections not found."; }
}
