#include <iostream>
#include <fstream>
using namespace std;
int length(string text)
{
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        j++;
    }
    return j;
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
    string tempText = "";

    for (int i = 0; i < length(input); i++) {
        if (input[i] != ' ') {
            tempText += input[i];
            if (i == length(input) - 1) {

                ifn.open("right.txt");
                while (!ifn.eof()) {
                    str = " ";
                    ifn >> str;

                    if (length(tempText) == length(str)) {
                        for (int i = 0; i < length(tempText); i++) {
                            if (str[i] == tempText[i]) {
                                count++;
                            }
                        }
                        if (count == length(str) - 1) {
                            fs << " " << str;
                            count = 0;
                            tempText = "";
                        }
                        else {
                            fs << " " << tempText;
                            count = 0;
                            tempText = "";
                        }
                    }
                }
                ifn.close();
            }
        }
        else if (input[i] == ' ') {
            if (length(tempText) == 1) {
                fs << " " << tempText;
                count = 0;
                tempText = "";
            }
            else {

                ifn.open("right.txt");
                while (!ifn.eof()) {
                    str = " ";
                    ifn >> str;
                    if (length(tempText) == length(str)) {
                        for (int i = 0; i < length(tempText); i++) {
                            if (str[i] == tempText[i]) {
                                count++;
                            }
                        }
                        if (count == length(str) - 1) {
                            fs << " " << str;
                            count = 0;
                            tempText = "";
                        }
                        else {
                            fs << " " << tempText;
                            count = 0;
                            tempText = "";
                        }
                    }
                }
                ifn.close();
            }
        }
    }

    return 0;
}
