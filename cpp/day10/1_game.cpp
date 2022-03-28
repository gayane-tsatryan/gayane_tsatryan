#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char to_upper(char);
int l(string);
string toUpWord(string);
int main()
{
    int z = rand() % 3 + 1;
    string user = "";
    char temp = ' ';
    string str = " ";
    int choose;
    string bararan[] = { "Erevan", "Nayrobi", "ijevan", "ninve", "Krym", "Vanacor", "NewYork" };
    int l1 = 2 * (sizeof(bararan) / sizeof(bararan[0]));
    string addarr[l1];
    cout << l1;
    cout << "who is first?\n 1. for user- \n 2. for computer- ";
    cin >> choose;
    bool b = false;

    str = bararan[z];
    int j = 0;
    if (choose == 1) {

        cout << bararan[z] << endl;
        while (true) {
            addarr[j] = str;
            j++;
        region1:
            cin >> user;

            for (int k = 0; k <= l1; k++) {
                if (toUpWord(user) == toUpWord(addarr[k])) {
                    cout << "This wore alredy use:";
                    goto region1;
                }
            }

            temp = user[0];

            if (to_upper(temp) == to_upper(str[l(str) - 1])) {
                addarr[j] = user;
                for (int i = 0; i < sizeof(bararan) / sizeof(bararan[0]); i++) {

                    if (to_upper(user[l(user) - 1]) == to_upper(bararan[i][0])) {

                        for (int k = 0; k <= l1; k++) {
                            if (toUpWord(user) == toUpWord(addarr[k])) {
                                b = true;
                                break;
                            }
                        }
                        if (b == true) {
                            b = false;

                            continue;
                        }
                        else {
                            cout << "--->>" << bararan[i] << endl;
                            str = bararan[i];
                            b = false;

                            j++;
                            break;
                        }
                    }

                    /*if (i == 5 && r==1 && r!=2) {
                        cout << "Finish you are winner";
                    }*/
                }
            }
            else {

                cout << "Word must start in " << str[l(str) - 1];
                goto region1;
                return 0;
            }
        }
    }
    else if (choose == 2) {
        while (true) {
        //cin.ignore();
        region2:
            //getline(cin, user);
            cin >> user;

            for (int k = 0; k <= l1; k++) {
                if (toUpWord(user) == toUpWord(addarr[k])) {
                    cout << "This wore alredy use:";
                    goto region2;
                }
            }
            addarr[j] = user;
            temp = user[l(user) - 1];

            for (int i = 0; i < sizeof(bararan) / sizeof(bararan[0]); i++) {

                if (to_upper(temp) == to_upper(bararan[i][0])) {

                    ///////
                    for (int k = 0; k <= l1; k++) {
                        if (toUpWord(bararan[i]) == toUpWord(addarr[k])) {
                            b = true;
                            break;
                        }
                    }
                    if (b == true) {
                        b = false;

                        continue;
                    }
                    else {
                        cout << "--->>" << bararan[i] << endl;
                        str = bararan[i];
                        b = false;

                        j++;
                        addarr[j] = str;
                        j++;
                        break;
                    }
                    ////////
                    cout << "--->>" << bararan[i] << endl;

                    str = bararan[i];
                    break;
                }
            }
        }
    }

    return 0;
}

int l(string a)
{
    int k = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        k++;
    }
    return k;
}

char to_upper(char a)
{
    if (a >= 'a' && a <= 'z') {
        return a - 32;
    }
    return a;
}

string toUpWord(string a)
{
    string b = "";
    for (int i = 0; a[i] != '\0'; i++) {
        b += to_upper(a[i]);
    }
    return b;
}

