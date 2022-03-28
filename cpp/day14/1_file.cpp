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
    bool b = false;
    int dd = 0, mm = 0, yy = 0;
    string checkinp = "";
    struct data datainput;
    do {
    region1:
        b = false;
        cout << "Enter day: ";
        cin >> datainput.dataDate;
        cout << "Enter Note:";
        cin.ignore();
        toStr(datainput.dataDate, &dd, &mm, &yy);

        if ((mm == 2 && isLeap(yy) && dd > 0 && dd <= 28) || (mm == 2 && !isLeap(yy) && dd > 0 && dd <= 29) || ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && dd > 0 && dd <= 31) || (mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 0 && dd <= 30) {
            getline(cin, datainput.Note);
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

            string path1 = "./notes/tempfile.txt";
            string adding = to_string(dd) + "_" + to_string(mm) + "_" + to_string(yy) + ".txt";
            fstream fs1;
            fs1.open(path1, fstream::in | fstream::out | fstream::app);
            if (!fs1.is_open()) {
                cout << "File  closed";
            }
            else {
                string strf;
                ifstream MyRF("./notes/tempfile.txt");
                while (getline(MyRF, strf)) {
                    if (adding == strf) {
                        b = true;
                    }
                }

                if (b == false) {
                    fs1 << adding + "\n";
                }
            }

            cout << "Command: add/exit ";
            cin >> datainput.command;
        }
        else {
            cout << "Enter normal date!" << endl;
            goto region1;
        }
    } while (datainput.command == "add");

    if (datainput.command == "exit") {

        string myText;
        ifstream MyReadFile("./notes/tempfile.txt");
        while (getline(MyReadFile, myText)) {
            string myText1;
            ifstream MyReadFile1(myText);
            while (getline(MyReadFile1, myText1)) {
                cout << myText1 << endl;
            }
        }

        return 0;
    }
    else {
        cout << "You must input: add/exit: ";
        return 0;
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
    for (int i = 1900; i < year; ++i) {
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
    return (4 + total + day) % 7;
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
