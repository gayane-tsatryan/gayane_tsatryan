#include <iostream>
#include <fstream>
using namespace std;
int l(string a)
{
    int n = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        n++;
    }
    return n;
}
int main()
{
    ofstream of;
    of.open("right.txt");

    of << "hello name pen computer cpp programming language student file  learn english armenian out input open close yes feel good black";
    of.close();

    ifstream ifn;
    ifn.open("right.txt");

    int count = 0;
    string path = "myfile.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!ifn.is_open()) {
        cout << "file is not exist.";
    }
    else {
        if (!fs.is_open()) {
            cout << "file dont open." << endl;
        }
        else {
            string msg;
            cin >> msg;

            string temp = "";
            for (int j = 0; j < l(msg); j++) {

                if (msg[j] != ' ') {
                    temp += msg[j];
                }
                else if (msg[j] == ' ') {
                    string str;
                    while (!ifn.eof()) {
                        str = " ";
                        ifn >> str;

                        if (l(temp) == l(str)) {
                            for (int i = 0; i < l(str); i++) {
                                if (temp[i] == str[i]) {
                                    count++;
                                }
                            }
                            if (count == l(str) - 1) {
                                temp = str;
                            }
                            count = 0;
                        }
                    }
                }
                fs << temp;
                temp = "";
                count = 0;
            }
        }
    }

    ifn.close();
    fs.close();
    return 0;
}
