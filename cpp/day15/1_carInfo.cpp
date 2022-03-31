#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct carInfo {
    string make;
    string driveType;
    int minPrice;
    int age;
    int mileage;
    string transmission;
    string color;
};
void printCar(carInfo);
bool isNumber(string);
char to_upper(char);

string toUpWord(string);
int main()
{
    int len = 24;
    struct carInfo car_info[len];
    int z = 0;
    string str = "";
    string sarr[7];
    ifstream mfile("cars.txt");
    int i = 0;
    int temp = 0;
    while (!mfile.eof()) {
        mfile >> str;
        sarr[i] = str;
        i++;
        if (i == 7) {
            car_info[temp].make = sarr[0];
            car_info[temp].driveType = sarr[1];
            car_info[temp].minPrice = stoi(sarr[2]);
            car_info[temp].age = stoi(sarr[3]);
            car_info[temp].mileage = stoi(sarr[4]);
            car_info[temp].transmission = sarr[5];
            car_info[temp].color = sarr[6];
            i = 0;
            temp++;
        }
    }

    mfile.close();
region1:
    string searchn;
    cout << "For see all cars info Input - SHOW \nFor search input - FILTER" << endl;
    cin >> searchn;
    if (toUpWord(searchn) == toUpWord("show")) {
        for (int i = 0; i < len; i++) {

            printCar(car_info[i]);
        }
    }
    else if (toUpWord(searchn) == toUpWord("filter")) {

        string input1 = "";
        string input2 = "";
        string input3 = "";
        string input4 = "";
        string input5 = "";
        string input6 = "";
        string input7 = "";
        string max = "";
        cout << "Enter filter for car info." << endl;

        cout << "Make: " << endl;
        cin >> input1;

        cout << "DriveType: " << endl;
        cin >> input2;

        cout << "MinPrice: " << endl;
        cin >> input3;

        cout << "MaxPrice: " << endl;
        cin >> max;

        cout << "Age: " << endl;
        cin >> input4;

        cout << "Mileage: " << endl;
        cin >> input5;

        cout << "Transmission: " << endl;
        cin >> input6;

        cout << "Color: " << endl;
        cin >> input7;

        int input33 = 0;
        int input44 = 0;
        int input55 = 0;
        if (isNumber(input3)) {
            input33 = stoi(input3);
        }
        if (isNumber(input4)) {
            input44 = stoi(input4);
        }
        if (isNumber(input5)) {
            input55 = stoi(input5);
        }
        int maxx = 0;
        if (isNumber(max)) {
            maxx = stoi(max);
        }

        string v = "-";
        for (int i = 0; i < len; i++) {
            if (input3 != v && maxx > input33) {
                if (toUpWord(car_info[i].make) != toUpWord(input1) && input1 != v) {
                    continue;
                }
                if (toUpWord(car_info[i].driveType) != toUpWord(input2) && input2 != v) {
                    continue;
                }
                if ((car_info[i].minPrice < input33 || car_info[i].minPrice > maxx) && input3 != v) {
                    continue;
                }
                if (car_info[i].age != input44 && input4 != v) {
                    continue;
                }
                if (car_info[i].mileage != input55 && input5 != v) {
                    continue;
                }
                if (toUpWord(car_info[i].transmission) != toUpWord(input6) && input6 != v) {
                    continue;
                }
                if (toUpWord(car_info[i].color) != toUpWord(input7) && input7 != v) {
                    continue;
                }

                printCar(car_info[i]);
            }
            else {

                if (toUpWord(car_info[i].make) != toUpWord(input1) && input1 != v) {
                    continue;
                }
                if (toUpWord(car_info[i].driveType) != toUpWord(input2) && input2 != v) {
                    continue;
                }
                if (car_info[i].minPrice > input33 && input3 != v) {
                    continue;
                }
                if (car_info[i].age != input44 && input4 != v) {
                    continue;
                }
                if (car_info[i].mileage != input55 && input5 != v) {
                    continue;
                }
                if (toUpWord(car_info[i].transmission) != toUpWord(input6) && input6 != v) {
                    continue;
                }
                if (toUpWord(car_info[i].color) != toUpWord(input7) && input7 != v) {
                    continue;
                }

                printCar(car_info[i]);
            }
        }
    }
    else {
        goto region1;
    }
    return 0;
}
bool isNumber(string s)
{
    for (char c : s) {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
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

void printCar(carInfo car_info)
{
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Make:                  " << car_info.make << endl;
    cout << "DriveType:             " << car_info.driveType << endl;
    cout << "MinPrice:              " << car_info.minPrice << endl;
    cout << "Age:                   " << car_info.age << endl;
    cout << "Mileage:               " << car_info.mileage << endl;
    cout << "Transmission:          " << car_info.transmission << endl;
    cout << "Color:                 " << car_info.color << endl;
    cout << "-----------------------------------------------------" << endl;
}
