#include "funcs.h"

using namespace std;



struct Patient {
    char surname[20];
    time_t date;
    time_t time;
};

bool isNum(string text) {
    for (char i: text) {
        if (isdigit(i)) {
            return true;
        }
    }
    return false;
}

string getSurname() {
    string surname;
    cout << "Enter the surname of patient\n";
    cin >> surname;
    while (isNum(surname) || surname.size() > 20) {
        cout << "Please, do not enter any numbers in surname.Also it should be less than 20 symbols.\nTry again:    ";
        cin >> surname;
    }
    return surname;
}

time_t getDate() {
    tm tmRef = {0, 0, 0, 0, 0, 0};
    cout << "Enter the date of previous appointment\n(USE FORMAT 18.02.2011)\n ";
    cin >> get_time(&tmRef, "%d.%m.%Y");
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Failed:(\nTry again: ";
        cin >> get_time(&tmRef, "%d.%m.%Y");
    }
    return mktime(&tmRef);
}

time_t getTime() {
    time_t t = time(0);
    tm tmRef = {0, 0, 0, localtime(&t)->tm_mday, localtime(&t)->tm_mon, localtime(&t)->tm_year};
    cout << "Enter the time of appointment\n(USE FORMAT 17:30)\n";
    cin >> get_time(&tmRef, "%H:%M");
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Failed:(\nTry again: ";
        cin >> get_time(&tmRef, "%H:%M");
    }
    return mktime(&tmRef);
}

Patient getData() {
    Patient person;
    strcpy(person.surname, getSurname().c_str());
    person.date = getDate();
    person.time = getTime();
    return person;
}

bool isEx(Patient person) {
    time_t t1 = person.date;
    time_t t2 = time(NULL);
    double a = difftime(t2, t1);
    if (a > 864000) {
        return false;
    }
    return true;
}

bool isMissed(Patient person) {
    time_t t1 = person.time;
    time_t t2 = time(NULL);
    double a = difftime(t2, t1);
    if (a < 0) {
        return false;
    }
    return true;
}

void createFile(const string &name, vector <Patient> &vec) {
    ofstream file;
    string answer;
    file.open(name, ios::binary);
    while (file.is_open()) {
        cout << "Would you like to add a patient? Please, enter 'yes' or 'no':\n";
        cin >> answer;
        while (answer != "yes" && answer != "no") {
            cout << "PLEASE, enter 'yes' or 'no':\n";
            cin >> answer;
        }
        if (answer == "yes") {
            Patient human = getData();
            vec.push_back(human);
            file.write((char *) &human, sizeof(Patient));
        } else file.close();
    }
    if (vec.empty()) {
        cout << "\nI can't complete the task because of you.";
        exit(0);
    }
}

void delMissed(const string &name, vector <Patient> &vec) {
    cout << "DELETING records about those patients whose time has already passed...\n";
    ofstream file;
    file.open(name, ios::binary);
    if (!file.is_open()) {
        cout << "Error while opening file => i can't overwrite the file :( ";
        exit(EXIT_FAILURE);
    } else {
        for (vector<Patient>::iterator i = vec.begin(); i != vec.end(); ++i) {
            if (!isMissed(i.operator*())) {
                file.write((char *) &i.operator*(), sizeof(Patient));
            }
        }
    }
    file.close();
    vector<struct Patient> newVec;
    newVec.reserve(vec.size());
    for (auto i = 0; i < vec.size(); ++i) {
        if (!isMissed(vec[i])) {
            newVec.emplace_back(std::move(vec[i]));
        }
    }
    vec.swap(newVec);
    cout << "Done!\n ";
}

void distribution(const string &name1, const string &name2, vector <Patient> &vec) {
    if (vec.empty()) {
        cout << "\nNo more patients. I can't complete the task because of you.";
        exit(0);
    }
    cout << "I will distribute patients into two new files...\n";
    ofstream f1;
    f1.open(name1, ios::binary);
    if (!f1.is_open()) {
        cout << "Error opening second file :(";
        exit(EXIT_FAILURE);
    } else {
        for (vector<Patient>::iterator i = vec.begin(); i != vec.end(); ++i) {
            if (isEx(i.operator*())) {
                f1.write((char *) &i.operator*(), sizeof(Patient));
            }
        }
        f1.close();
    }
    ofstream f2;
    f2.open(name2, ios::binary);
    if (!f2.is_open()) {
        cout << "Error opening third file :(";
        exit(EXIT_FAILURE);
    }
    for (vector<Patient>::iterator i = vec.begin(); i != vec.end(); ++i) {
        if (!isEx(i.operator*())) {
            f2.write((char *) &i.operator*(), sizeof(Patient));
        }
    }
    f2.close();
    cout << "Done!";
}

void filePrint(const string &name) {
    cout << "\n" << setw(20) << name << " contains:\n";
    Patient person{};
    ifstream file(name, ios::binary);
    while (file.read((char *) &person, sizeof(Patient))) {
        string surname(person.surname);

        time_t dt = person.date;
        struct tm *dateinfo;
        time(&dt);
        dateinfo = localtime(&dt);
        string date = asctime(dateinfo);

        time_t tm = person.time;
        struct tm *timeinfo;
        time(&tm);
        timeinfo = localtime(&tm);
        string time = asctime(timeinfo);

        cout << "Surname: " << surname << "\n" << "Last appointment date: " << date << "Time of sppaintment: " << time
             << "\n";
    }
    file.close();
}

