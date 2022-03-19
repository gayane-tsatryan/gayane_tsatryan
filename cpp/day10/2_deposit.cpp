
#include <iostream>
#include <ctime>
using namespace std;

void vark(int, double, int, int);
int main(int argc, char* argv[])
{
    time_t now = time(0);
    string day, month1, year;
    string cur_date;

    int im, id, iy;

    char* date_time = ctime(&now);

    string s = date_time;

    cout << s << endl;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((i > 3 && i < 11) || (i > s.length() - 6)) {

            if (s[i] == ' ') {
                s[i] = '/';
            }
            cur_date += s[i];
        }
    }
    for (int i = 0; cur_date[i] != '\0'; i++) {
        if (i >= 0 && i < 3) {
            month1 += cur_date[i];
        }
        else if (i > 3 && i < 6) {
            day += cur_date[i];
        }
        else if (cur_date[i] != '/') {
            year += cur_date[i];
        }
    }

    string arraymonth[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    for (int i = 0; i < 12; i++) {
        if (month1 == arraymonth[i]) {
            im = i + 1;
        }
    }

    int mm = im;
    int dd = stoi(day);
    int yy = stoi(year);

    int many = atoi(argv[1]);
    char* end;
    double tokos = strtod(argv[2], &end);
    int month = atoi(argv[3]);
    vark(many, tokos, month, yy);
    return 0;
}

void vark(int many, double tokos, int month, int yy)
{
    double permonth = 0;
    string arraymonth[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    double total = 0;
    int monthP = 1;
    cout << "=========================================================" << endl;
    cout << " Main many\t   Sum\t\t  Month\t\tYear" << endl;
    cout << "=========================================================";

    cout << endl;
    for (int i = 1; i <= month; i++) {
        permonth = ((many / 100.0) * tokos) / 12;

        if (i % 12 == 1) {
            yy++;
            monthP = 1;
        }

        if (arraymonth[monthP] == "May" || arraymonth[monthP] == "June" || arraymonth[monthP] == "July") {
            cout << "| " << many << "\t | " << permonth << "\t | " << arraymonth[monthP] << "\t\t | " << yy - 1 << endl;
        }
        else {
            cout << "| " << many << "\t | " << permonth << "\t | " << arraymonth[monthP] << "\t | " << yy - 1 << endl;
        }
        many = many + permonth;
        monthP++;
    }
}
