#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum weekD {
    Mon = 1,
    Tue,
    Wed,
    Thu,
    Fry,
    Sut,
    Sun
};

struct data {
    string dataDate = "";
    string Note = "";
    string command = "";
};

void toStr(string, int*, int*, int*);
int weekDay(int, int, int);
bool isEmpty(string);

int main()
{
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
        string path = "./notes/" + to_string(dd) + "_" + to_string(mm) + "_" + to_string(yy) + ".txt";
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

        cout << "Command: add/exit ";
        cin >> datainput.command;
        if (datainput.command == "add") {
            continue;
        }
        else if (datainput.command == "exit") {
            return 0;
        }
        else {
            cout << "Enter Command: add/exit: ";
            cin >> datainput.command;
        }
    }
    return 0;
}
int weekDay(int y, int m, int d)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
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
