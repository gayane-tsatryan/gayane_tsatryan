#include <iostream>
#include <string>
using namespace std;

int length(string);
bool isNumber(string);

int main(int argc, char* argv[])
{
    string inputnumber;
    string index1s, index2s;
    int index1, index2;
    cout << "Input number: ";
    cin >> inputnumber;

    if (isNumber(inputnumber)) {
        cout << "input position to swap: ";
        cin >> index1s;
        cin >> index2s;
        char temp = ' ';
        int arrlength = length(inputnumber);
        if (isNumber(index1s) && isNumber(index2s)) {
            int index1 = stoi(index1s);
            int index2 = stoi(index2s);
            if ((index1 >= 1 && index1 <= arrlength) && (index2 >= 1 && index2 <= arrlength)) {
                temp = inputnumber[index1 - 1];
                inputnumber[index1 - 1] = inputnumber[index2 - 1];
                inputnumber[index2 - 1] = temp;
                cout << inputnumber << endl;
            }
            else {
                cout << "IndexOutOfRangeException!" << endl;
            }
        }
        else {
            cout << "Enter the number for swaping!" << endl;
        }
    }

    else {
        cout << "Enter the number!" << endl;
    }
    return 0;
}

int length(string a)
{
    int n = 0;

    for (int i = 0; a[i] != '\0'; i++) {
        n++;
    }
    return n;
}
bool isNumber(string inputnumber)
{

    string a = "";
    int j = 0;
    int k = length(inputnumber);
    for (int i = 0; inputnumber[i] != '\0'; i++) {

        if (inputnumber[i] >= 48 && inputnumber[i] <= 57) {
            a += inputnumber[i];
            j++;
        }
    }
    if (j == k) {
        int temp1 = stoi(inputnumber);
        return 1;
    }
    else {
        return 0;
    }
}
