#include <iostream>
#include <string>
using namespace std;

int CountOccurrences(string str, string w)
{
    int count = 0;
    int strLen = str.length();
    int wordLen = w.length();
    int j;
    for (int i = 0; i <= strLen; i++) {
        for (j = 0; j < wordLen; j++) {
            if (str[i + j] != w[j]) {
                break;
            }
        }
        if (j == wordLen) {
            count++;
        }
    }
    return count;
}

string firstLetterWord(string str)
{
    string result = "";
    bool v = true;
    for (int i = 0; i < str.length(); i++) {

        if (str[i] == ' ')
            v = true;

        else if (str[i] != ' ' && v == true) {
            result.push_back(str[i]);
            v = false;
        }
    }

    return result;
}

char lastLetterWord(string str)
{
    int s = str.length() - 1;
    return str[s];
}

void game(string player)
{
    string compplayer = "tirana yerevan canberra manama vienna brussels belmopan lauanda london bogota praia havana nicosia ottawa gitega copenhagen nicosia paris helsinki budapesht newdelhi";
    string repeatword = "";
    char pl = lastLetterWord(player);
    //cout << pl << endl;
    string hp = firstLetterWord(compplayer);
    //cout << hp << hp.length() << endl;
    for (int i = 0; i < hp.length(); i++) {
        if (pl == hp[i]) {
            for (int i = 0; i < compplayer.length(); i++) {
                string stanumEnkBar = "";
                if (compplayer[i] == pl) {
                    for (int j = i; compplayer[j] != ' '; j++) {
                        stanumEnkBar = stanumEnkBar + compplayer[j];
                    }
                    int temp = CountOccurrences(repeatword, stanumEnkBar);
                    if (temp == 0) {
                        cout << stanumEnkBar;
                        repeatword = repeatword + stanumEnkBar;
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        else {
            cout << "I can't play"<< endl;
            break;
        }    
    }
}

int main()
{
    while (true) {
        cout << "Enter EXIT for end:" << endl;
        string player;
        cout << "Enter the word: ";
        getline(cin, player);
        game(player);
        if (player == "EXIT") {
            break;
        }
    }

    return 0;
}
