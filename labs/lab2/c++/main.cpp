#include "funcs.h"

using namespace std;


struct Patient {
    char surname[20];
    time_t date;
    time_t time;
};


int main() {
    const string name1 = "FirstFile.bin";
    vector<struct Patient> vec;
    createFile(name1, vec);
    filePrint(name1);
    delMissed(name1, vec);
    filePrint(name1);
    const string name2 = "SecondFile.bin";
    const string name3 = "ThirdFile.bin";
    distribution(name2, name3, vec);
    filePrint(name2);
    filePrint(name3);
}
