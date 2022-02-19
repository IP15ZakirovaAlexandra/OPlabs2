#include <iostream>
#include "../headers/Funcs.h"

using namespace std;

int main() {
    cout << "PRINT # ON A NEW LINE AND PRESS THE ENTER KEY TO COMPLETE INPUT\nEnter your text:" << endl;
    vector<string> text = ReadConsole();
    string firstName = "C:\\Users\\Legion\\CLionProjects\\2SemOPlab1\\FirstFile.txt";
    fstream FirstFile;
    InputInFile(text, firstName, FirstFile);
    PrintFileContent("The FirstFile.txt contains next sentence/s: ", firstName, FirstFile);
    ChangeText(text);
    string secondName = "C:\\Users\\Legion\\CLionProjects\\2SemOPlab1\\SecondFile.txt";
    fstream SecondFile;
    InputInFile(text, secondName, SecondFile);
    PrintFileContent("The SecondFile.txt contains next sentence/s: ", secondName, SecondFile);
    return 0;
}
