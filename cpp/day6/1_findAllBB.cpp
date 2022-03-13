#include <iostream>
using namespace std;

string subString(string, int, int);
int length(string);
int printCountString(string, string);

int main()
{
    string string1 = "fhfghdfBB dfgjdjBB ddfd  dgdlfgjdsoBBB ddfddBBB";
    string string2 = "BB";
    cout << printCountString(string1, string2) << endl;
    return 0;
}

string subString(string a, int index, int length)
{
    string b = "";
    for (int j = 0; j < length; j++) {
        b = b + a[index + j];
    }

    return b;
}

int length(string a)
{
    int l = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        l++;
    }
    return l;
}
int printCountString(string string1, string string2)
{

    int j = 0;
    for (int i = 0; i < length(string1); i++) {

        if (subString(string1, i, length(string2)) == string2) {
            j++;
        }
    }
    return j;
}

