#include <iostream>
#include "header.h"
using namespace std;

int main() {

    Vector v1 = create("V1");
    Vector v2 = Vector();
    v1 = v1 * 2;
    Vector diff = v1 - v2;
    diff.setName("V3");
    Vector v3 = Vector(diff);
    cout << v1 << endl << v2 << endl << v3 << " length: " << v3.getLength();
    return 0;
}
