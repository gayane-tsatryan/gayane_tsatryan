#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    long int second;

    cout << "Input:   ";

    cin >> second;

    time_t dt = second;
    string date = ctime(&dt);
    string mm = "";
    string day = "";
    string time = "";
    string yy = "";
    for (int i = 0; date[i] != '\0'; i++) {
        if (i > 3 && i < 7) {
            mm += date[i];
        }
        else if (i > 7 && i < 10) {
            day += date[i];
        }
        else if (i > 10 && i < 16) {
            time += date[i];
        }
        else if (i > 19 && date[i] != '\0') {
            yy += date[i];
        }
    }

    string d = mm + " " + day + " " + time + " " + yy;
    cout << "Output: " << d << endl;

    return 0;
}
