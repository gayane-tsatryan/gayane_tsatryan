#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string hotelname;
    int starrate;
    int singlRoom;
    int twinRoom;
    int trplRoom;
    int vipRoom;
    bool spa;
    bool souna;
    bool gameRoom;
    bool fitnes;
    bool kidClub;
    bool lobiBar;
    bool laundry;

    cout << " Enter hotel name:  ";
    cin >> hotelname;

region1:
    cout << " Enter star rate:(3/5/7)  ";
    cin >> starrate;
    if (starrate != 3 && starrate != 5 && starrate != 7) {
        goto region1;
    }
    cout << " Enter singlRoom:  ";
    cin >> singlRoom;
    cout << " Enter twinRoom:  ";
    cin >> twinRoom;
    cout << " Enter trplRoom:  ";
    cin >> trplRoom;
    cout << " Enter vipRoom:  ";
    cin >> vipRoom;
    cout << " Enter spa  0/1:  ";
    cin >> spa;
    cout << " Enter souna 0/1:  ";
    cin >> souna;
    cout << " Enter gameRoom 0/1:  ";
    cin >> gameRoom;
    cout << " Enter fitnes  0/1:  ";
    cin >> fitnes;
    cout << " Enter kidClub 0/1:  ";
    cin >> kidClub;
    cout << " Enter lobiBar 0/1:  ";
    cin >> lobiBar;
    cout << " Enter laundry 0/1:  ";
    cin >> laundry;

    string text = hotelname + " " + to_string(starrate) + " " + to_string(singlRoom) + " " + to_string(twinRoom) + " " + to_string(trplRoom) + " "
        + to_string(vipRoom) + " " + to_string(spa) + " " + to_string(souna) + " " + to_string(gameRoom) + " "
        + to_string(fitnes) + " " + to_string(kidClub) + " " + to_string(lobiBar) + " " + to_string(laundry);
    fstream fs;
    string str = "";
    string path = "info.txt";
    fs.open(path, fstream::in | fstream::out | fstream::app);
    fs << text << endl;
    return 0;
}
