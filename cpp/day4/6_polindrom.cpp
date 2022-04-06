#include <iostream>
using namespace std;

string polindrom(string);
char to_upper(char);
int length(string);
int main()

{
    string word;
    cout << "Input : ";
    cin >> word;

    cout << "Output: " << polindrom(word) << endl;
    return 0;
}

char to_upper(char letter)
{
    if (letter >= 'a' && letter <= 'z') {
        return letter - 32;
    }
    return letter;
}

int length(string word)
{
    int i = 0;
    for (int j = 0; word[j] != '\0'; j++) {
        i++;
    }
    return i;
}

string polindrom(string word)
{
    int lengthWord = length(word);
    for (int i = 0; i < lengthWord / 2; i++) {
        if (to_upper(word[i]) != to_upper(word[lengthWord - 1 - i])) {
            return "false";
        }
    }
    return "true";
}

