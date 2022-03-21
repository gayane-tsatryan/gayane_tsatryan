#include<iostream>
using namespace std;

int length(string);
void transformation(string, int, int);
int main()
{
    string word;
    cout << "Enter the word: ";
    cin >> word;
    int size = length(word);
    transformation(word, 0, size);
    return 0;
}
void transformation(string word, int start, int length)
{
    if (start == length)
        cout << word << endl;
    else {
        for (int i = start; i < length; i++) {

            swap(word[start], word[i]);

            transformation(word, start + 1, length);
        }
    }
}

int length(string word)
{
    int n = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        n++;
    }
    return n;
}
