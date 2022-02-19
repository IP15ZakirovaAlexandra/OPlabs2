#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> ReadConsole();

void InputInFile(vector<string> text, const string &name, fstream &myfile);

void ChangeText(vector<string> &text);

void PrintFileContent(const string& message, const string &name, fstream &myfile);