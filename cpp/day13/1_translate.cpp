#include <iostream>
#include <fstream>
using namespace std;

int length(string);
void translate(string);
int main()
{
    string source, fileName;
    cout << "Choose the language\n\t 1 -> hy - en \n\t 2 -> en - hy" << endl;
    cin >> source;
    if (source == "1") {
        fileName = "hy-en.txt";
    }
    else if (source == "2") {
        fileName = "en-hy.txt";
    }
    else {
        cout << "Input 1 or 2";
        return 0;
    }
    translate(fileName);
    return 0;
}

void translate(string fileName)
{
    ifstream ifn;
    string input;
    cout << "Enter the word: ";
    cin.ignore();
    getline(cin, input);
    string str = "";
    int count = 0;
    string path = "translater.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    int len_of = 0;
    ifstream ifn1(fileName);
    while (!ifn1.eof()) {
        string str = " ";
        ifn1 >> str;
        len_of++;
    }

    string s_array[len_of];
    int il = length(input);
    string inputarray[il];
    int k = 0;
    string arr = "";
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') {
            arr += input[i];
        }
        else if (input[i] == ' ') {
            inputarray[k] = arr;
            k++;
            arr = "";
        }
    }
    inputarray[k] = arr;
    if (!fs.is_open()) {
        cout << "File  closed";
    }
    else {
        int j = 0;
        for (int z = 0; z < il; z++) {
            ifn.open(fileName);
            while (!ifn.eof()) {
                str = " ";
                ifn >> str;
                s_array[j] = str;
                j++;
            }
            for (int i = 0; i < len_of; i++) {
                if (inputarray[z] == s_array[i]) {
                    fs << s_array[i + 2] << " ";
                }
            }
        }
    }
}
int length(string text)
{
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            j++;
        }
    }
    return j + 1;
}
