
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace  std;

struct hotelInfo
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
};
bool stob(string);
int size();
string printStars(hotelInfo);
bool isBig(string, string);
void toStr(string a, int*, int*, int*);
int main()
{
    struct hotelInfo hif[4];
    string sarr[13];
    ifstream ifs("info.txt");
    string str = "";
    int index1 = 0, index2 = 0;
    while (!ifs.eof()) {
        ifs >> str;
        sarr[index1] = str;
        index1++;
        if (index1 == 13) {
            hif[index2].hotelname = sarr[0];
            hif[index2].starrate = stoi(sarr[1]);
            hif[index2].singlRoom = stoi(sarr[2]);
            hif[index2].twinRoom = stoi(sarr[3]);
            hif[index2].trplRoom = stoi(sarr[4]);
            hif[index2].vipRoom = stoi(sarr[5]);
            hif[index2].spa = stob(sarr[6]);
            hif[index2].souna = stob(sarr[7]);
            hif[index2].gameRoom = stob(sarr[8]);
            hif[index2].fitnes = stob(sarr[9]);
            hif[index2].kidClub = stob(sarr[10]);
            hif[index2].lobiBar = stob(sarr[11]);
            hif[index2].laundry = stob(sarr[12]);
            index1 = 0;
            index2++;
        }
    }
    ifs.close();
    string choose = "";
user:
    cout << "Iput your mod: ";
    getline(cin, choose);
    if (choose == "user") {
        cout << "             Wellcome          " << endl;
        cout << "|===========Hotel List==========|" << endl;
        for (int i = 0; i < size(); i++) {
            cout << "\t" << hif[i].hotelname << " Hotel\t|  " << printStars(hif[i]) << endl;
            cout << "|-------------------------------|" << endl;
        }
    }
    else {
        cout << "Mode not found" << endl;
        goto user;
    }
    string input_hotel;
choose:
    cout << "\n"
         << "Input your favorite hotel name: ";
    cin >> input_hotel;
    cout << endl;
    for (int i = 0; i < size(); i++) {
        if (hif[i].hotelname == input_hotel) {
            cout << "\t" << hif[i].hotelname << " Hotel " << printStars(hif[i]) << endl;
            cout << "_______________________________" << endl;
            if (hif[i].singlRoom > 0) {
                cout << "   SGL  | " << hif[i].singlRoom << " | 45000 AMD" << endl;
                cout << "_______________________________" << endl;
            }
            if (hif[i].twinRoom > 0) {
                cout << "   TWN  | " << hif[i].twinRoom << "| 65000 AMD" << endl;
                cout << "_______________________________" << endl;
            }
            if (hif[i].trplRoom > 0) {
                cout << "   TRPL | " << hif[i].trplRoom << " | 80000 AMD" << endl;
                cout << "_______________________________" << endl;
            }
            if (hif[i].vipRoom > 0) {
                cout << "   VIP  | " << hif[i].vipRoom << " | 90000 AMD" << endl;
                cout << "_______________________________" << endl;
            }
            cout << endl;
            string ans = "";
        tryA:
            cout << "Do You want to book a room?(yes/no) ";
            cin >> ans;
            if (ans == "yes") {
                //to be continued
                cout << "Yess";
            }
            else if (ans == "no") {
                goto choose;
            }
            else {
                goto tryA;
            }
        }
        else {
            goto choose;
        }
    }

    return 0;
}
string printStars(hotelInfo c)
{
    string str = "";
    int star = c.starrate;
    for (int i = 0; i < star; i++) {
        str += "*";
    }
    return str;
}
int size()
{
    int count = 0;
    string line;
    ifstream ifs("info.txt");
    while (getline(ifs, line)) {
        ++count;
    }
    ifs.close();
    return count;
}
bool stob(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    istringstream is(str);
    bool b;
    is >> std::boolalpha >> b;
    return b;
}
void toStr(string a, int* x, int* y, int* z)
{
    string d = "";
    string dd = "";
    string mm = "";
    string yy = "";
    int c = 0;
    bool b = false;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != '/') {
            d += a[i];
            c++;
        }
        else if ((c == 1 || c == 2) && a[i] == '/' && b == false) {

            if (d[0] == '0') {
                dd = d[1];
                d = "";
                b = true;
            }
            else {
                dd = d;
                d = "";
                b = true;
            }
        }
        else if ((c >= 2 && c <= 4) && a[i] == '/' && b == true) {
            if (d[0] == '0') {
                mm = d[1];
                d = "";
            }
            else {
                mm = d;
                d = "";
            }
        }
    }
    yy = d;
    *x = stoi(dd);
    *y = stoi(mm);
    *z = stoi(yy);
}

bool isBig(string date1, string date2)
{

    int d = 0;
    int m = 0;
    int y = 0;
    int dd = 0;
    int mm = 0;
    int yy = 0;
    toStr(date1, &d, &m, &y);
    toStr(date2, &dd, &mm, &yy);

    if (y > yy || (y == yy && m > mm) || (y == yy && m == mm && d >= dd)) {
        return true;
    }
    else {
        return false;
    }
}


