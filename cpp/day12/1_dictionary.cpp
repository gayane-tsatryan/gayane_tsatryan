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

    of << "hello\nname\npencil\ncomputers\ncpp\nprogramming\nlanguage\nstudent\nfile\nlearn\nenglish\narmenian\nout\ninput\nopen\nclose\nseptember\nfeel\ngood\nblack\nno";
    of.close();

    ifstream ifn;
    string input = "helio i am ITC  studend and i learn C++ frogramming longuage";
    string str = "";

    string path = "myfile.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    int count = 0;
    string t = "";

    for (int i = 0; i < l(input); i++) {
        if (input[i] != ' ') {
            t += input[i];
            if (i == l(input) - 1) {

                ifn.open("right.txt");
                while (!ifn.eof()) {
                    str = " ";
                    ifn >> str;

                    if (l(t) == l(str)) {
                        for (int i = 0; i < l(t); i++) {
                            if (str[i] == t[i]) {
                                count++;
                            }
                        }
                        if (count == l(str) - 1) {
                            fs << " " << str;
                            count = 0;
                            t = "";
                        }
                        else {
                            fs << " " << t;
                            count = 0;
                            t = "";
                        }
                    }
                }
                ifn.close();
            }
        }
        else if (input[i] == ' ') {
            if (l(t) == 1) {
                fs << " " << t;
                count = 0;
                t = "";
            }
            else {

                ifn.open("right.txt");
                while (!ifn.eof()) {
                    str = " ";
                    ifn >> str;
                    if (l(t) == l(str)) {
                        for (int i = 0; i < l(t); i++) {
                            if (str[i] == t[i]) {
                                count++;
                            }
                        }
                        if (count == l(str) - 1) {
                            fs << " " << str;
                            count = 0;
                            t = "";
                        }
                        else {
                            fs << " " << t;
                            count = 0;
                            t = "";
                        }
                    }
                }
                ifn.close();
            }
        }
    }

    return 0;
}
