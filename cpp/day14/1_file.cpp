#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum weekD {
    Sun = 0,
    Mon,
    Tue,
    Wed,
    Thu,
    Fry,
    Sut
};

struct data {
    string dataDate = "";
    string Note = "";
    string command = "";
};

void toStr(string, int*, int*, int*);
int weekDay(int, int, int);
bool isLeap(int year);
bool isEmpty(string);

int main()
{
    ofstream MyF("tempfile.txt");
    int dd = 0, mm = 0, yy = 0;
    string checkinp = "";
    struct data datainput;
    while (true) {
        cout << "Enter day: ";
        cin >> datainput.dataDate;
        cout << "Enter Note:";
        cin.ignore();
        getline(cin, datainput.Note);
        toStr(datainput.dataDate, &dd, &mm, &yy);
        string dayname = "";
        int wday1 = weekDay(yy, mm, dd);
        weekD wday = (weekD)wday1;
        switch (wday) {
        case Mon: {
            dayname = "Monday";
            break;
        }
        case Tue: {
            dayname = "Tuesday";
            break;
        }
        case Wed: {
            dayname = "Wednesday";
            break;
        }
        case Thu: {
            dayname = "Thusday";
            break;
        }
        case Fry: {
            dayname = "Friday";
            break;
        }
        case Sut: {
            dayname = "Suturday";
            break;
        }
        case Sun: {
            dayname = "Sunday";
            break;
        }
        }
        //adding file part
        string path = to_string(dd) + "_" + to_string(mm) + "_" + to_string(yy) + ".txt";
        fstream fs;
        fs.open(path, fstream::in | fstream::out | fstream::app);
        if (!fs.is_open()) {
            cout << "File  closed";
        }
        else {

            if (isEmpty(path)) {
                fs << dayname << "\t" << datainput.dataDate << "\t" << datainput.Note << "\n";
            }
            else {
                fs << "\t\t\t\t\t" << datainput.Note << "\n";
            }
        }
        checkinp = datainput.dataDate + " " + datainput.Note + "\n";
        MyF << checkinp;
        cout << "Command: add/exit ";
        cin >> datainput.command;
        if (datainput.command == "add") {
            continue;
        }
        else if (datainput.command == "exit") {
            string myText = "";
            ifstream MyR("tempfile.txt");

            while (getline(MyR, myText)) {

                cout << myText;
            }

            MyR.close();
            return 0;
        }
        else {
            cout << "Enter Command: add/exit: ";
            cin >> datainput.command;
        }
    }
    return 0;
}
bool isLeap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
int weekDay(int day, int month, int year)
{
    int total = 0;
    for (int i = 1970; i < year; ++i) {
        if (isLeap(i)) {
            total += 366;
        }
        else {
            total += 365;
        }
    }
    for (int i = 1; i < month; ++i) {
        switch (i) {
        case 1:
            total += 31;
            break;
        case 2:
            total += (isLeap(year) ? 29 : 28);
            break;
        case 3:
            total += 31;
            break;
        case 4:
            total += 30;
            break;
        case 5:
            total += 31;
            break;
        case 6:
            total += 30;
            break;
        case 7:
            total += 31;
            break;
        case 8:
            total += 31;
            break;
        case 9:
            total += 30;
            break;
        case 10:
            total += 31;
            break;
        case 11:
            total += 30;
            break;
        }
    }
    return (4 + total + day - 1) % 7;
}

void toStr(string a, int* x, int* y, int* z)
{
    string d = "";
    string dd = "";
    string mm = "";
    string yy = "";
    int c = 0;
    bool b = false;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != '/') {
            d += a[i];
            c++;
        }
        else if ((c == 1 || c == 2) && a[i] == '/' && b == false) {

            if (d[0] == '0') {
                dd = d[1];
                d = "";
                b = true;
            }
            else {
                dd = d;
                d = "";
                b = true;
            }
        }
        else if ((c >= 2 && c <= 4) && a[i] == '/' && b == true) {
            if (d[0] == '0') {
                mm = d[1];
                d = "";
            }
            else {
                mm = d;
                d = "";
            }
        }
    }
    yy = d;
    *x = stoi(dd);
    *y = stoi(mm);
    *z = stoi(yy);
}

bool isEmpty(string path)
{
    fstream fs;
    string str = "";

    fs.open(path, fstream::in | fstream::out | fstream::app);
    while (!fs.eof()) {
        fs >> str;
    }
    if (str == "") {
        return true;
    }
    else {

        return false;
    }
}
