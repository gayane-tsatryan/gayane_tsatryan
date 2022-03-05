#include <iostream>
using namespace std;

int main()
{
    char letter;
    cout << "Input alphabet : ";
    cin >> letter;

    switch (letter) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'Y':
    case 'U': {
        cout << " '" << letter << "'  is  vowel. \n";
        break;
    }
    default: {
        cout << " '" << letter <<  "'  is  consonant. \n";
        break;
    }
    }

    return 0;
}

