#include <iostream>
using namespace std;

string polindrom(string);
char to_upper(char);
int length(string);
int main()

{
    string a;
    cout << "Input : ";
    cin >> a;

    cout << "Output: " << polindrom(a) << endl;
    return 0;
}

char to_upper(char a)
{
    if (a >= 'a' && a <= 'z') {
        return a - 32;
    }
    return a;
}

int length(string a)
{
    int n = 0;
    for (int j = 0; a[j] != '\0'; j++) {
        n++;
    }
    return n;
}

string polindrom(string a)
{

    for (int i = 0; i < length(a) / 2; i++) {
        if (to_upper(a[i]) != to_upper(a[length(a) - 1 - i])) {
            return "false";
        }
    }
    return "true";
}

