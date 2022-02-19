#include "../headers/Funcs.h"

vector<string> ReadConsole() {
    vector<string> text;
    string line;
    int key = 35;
    while (int(line[0]) != key) {
        getline(cin, line);
        text.push_back(line);
    }
    text.pop_back();
    return text;
}

void InputInFile(vector<string> text, const string &name, fstream &myfile) {
    myfile.open(name, ios::app | ios:: ate);
    if(myfile.is_open()) {
        for (int i = 0; i < text.size(); i++) {
            myfile << text[i] << endl;
        }
    }
    myfile.close();
}

void ChangeText(vector<string> &text) {
    for (int i = 0; i <  text.size(); i++) {
        for (int j = i + 1; j < text.size(); j++) {
            if (text[i].size() > text[j].size()) {
                string temp = text[i];
                text[i] = text[j];
                text[j] = temp;
            }
        }
    }
    for (int i = 0; i < text.size(); i++) {
        text[i] += " " + to_string(text[i].size());
    }
}

void PrintFileContent(const string& message, const string &name, fstream &myfile) {
    myfile.open(name, ios::in);
    string line;
    cout << message << endl;
    while (getline(myfile, line)) {
        cout << line << endl;
    }
    myfile.close();
}


