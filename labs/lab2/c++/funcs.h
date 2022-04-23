#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>
#include <string>

using namespace std;


struct Patient;

bool isNum(string text);

string getSurname();

time_t getDate();

time_t getTime();

Patient getData();

bool isEx(Patient person);

bool isMissed(Patient person);

void createFile(const string &name, vector <Patient> &vec);

void delMissed(const string &name, vector <Patient> &vec);

void distribution(const string &name1, const string &name2, vector <Patient> &vec);

void filePrint(const string &name);

