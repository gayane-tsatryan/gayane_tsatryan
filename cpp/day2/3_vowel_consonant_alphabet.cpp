#include <iostream>
using namespace std;

int main()
{
    char letter;
    cout << "Input alphabet : ";
    cin >> letter;
    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) {
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
        case 'U':
            cout << " '" << letter << "'  is  vowel. \n";
            break;
        default:
            cout << " '" << letter << "'  is  consonant. \n";
            break;
        }
    }
    else {
        cout << "Error!  Enter letter: \n";
    }
    return 0;
}
