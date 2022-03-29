#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct carInfo {
    string make;
    string driveType;
    int minPrice;
    int maxPrice;
    int mileage;
    string transmission;
    string color;
};

bool isNumber(string);
char to_upper(char);

string toUpWord(string);
int main()
{
    ofstream carInfoFile("cars.txt");
    carInfoFile << "Nissan FrontWheelDrive 20000 33000 600000 automatic red\nNiva FrontWheelDrive 10000 13000 990000 automatic white\nVolkswagen FrontWheelDrive 120000 14000 300000 automatic blue\nBrabus FrontWheelDrive 38000 40000 800000 automatic yellow\nEraz FrontWheelDrive 90000 98000 500000 manual black\nMersedes FrontWheelDrive 60000 65000 100000 automatic gray";
    carInfoFile.close();
    struct carInfo car_info[6];

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
            car_info[temp].maxPrice = stoi(sarr[3]);
            car_info[temp].mileage = stoi(sarr[4]);
            car_info[temp].transmission = sarr[5];
            car_info[temp].color = sarr[6];
            i = 0;
            temp++;
        }
    }

    mfile.close();
region1:
    string choos = "";
    cout << "Input search mode (many or singl or full): ";
    cin >> choos;
    if (choos == "full") {

        string input1 = "";
        string input2 = "";
        string input3 = "";
        string input4 = "";
        string input5 = "";
        string input6 = "";
        string input7 = "";

        cout << "Enter filter for car info." << endl;

        cout << "Make: " << endl;
        cin >> input1;

        cout << "DriveType: " << endl;
        cin >> input2;

        cout << "MinPrice: " << endl;
        cin >> input3;

        cout << "MaxPrice: " << endl;
        cin >> input4;

        cout << "Mileage: " << endl;
        cin >> input5;

        cout << "Transmission: " << endl;
        cin >> input6;

        cout << "Color: " << endl;
        cin >> input7;
        int input33 = stoi(input3);
        int input44 = stoi(input4);
        int input55 = stoi(input5);

        for (int i = 0; i < 6; i++) {
            if (toUpWord(car_info[i].make) == toUpWord(input1) && toUpWord(car_info[i].driveType) == toUpWord(input2) && car_info[i].minPrice == input33 && car_info[i].maxPrice == input44 && car_info[i].mileage == input55 && toUpWord(car_info[i].transmission) == toUpWord(input6) && toUpWord(car_info[i].color) == toUpWord(input7)) {
                cout << "Make:                  " << car_info[i].make << endl;
                cout << "DriveType:             " << car_info[i].driveType << endl;
                cout << "MinPrice:              " << car_info[i].minPrice << endl;
                cout << "MaxPrice:              " << car_info[i].maxPrice << endl;
                cout << "Mileage:               " << car_info[i].mileage << endl;
                cout << "Transmission:          " << car_info[i].transmission << endl;
                cout << "Color:                 " << car_info[i].color << endl;
            }
        }
    }
    else if (choos == "singl") {
        string inp;
        cout << "Input parameter for filter:  ";
        cin >> inp;

        bool b = isNumber(inp);
        if (b) {
            int inp1 = stoi(inp);
            for (int i = 0; i < 6; i++) {
                if (car_info[i].minPrice == inp1 || car_info[i].maxPrice == inp1 || car_info[i].mileage == inp1) {
                    cout << endl;
                    cout << "Make:                  " << car_info[i].make << endl;
                    cout << "DriveType:             " << car_info[i].driveType << endl;
                    cout << "MinPrice:              " << car_info[i].minPrice << endl;
                    cout << "MaxPrice:              " << car_info[i].maxPrice << endl;
                    cout << "Mileage:               " << car_info[i].mileage << endl;
                    cout << "Transmission:          " << car_info[i].transmission << endl;
                    cout << "Color:                 " << car_info[i].color << endl;
                }
            }
        }
        else {
            for (int i = 0; i < 6; i++) {
                if (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) {
                    cout << endl;
                    cout << "Make:                  " << car_info[i].make << endl;
                    cout << "DriveType:             " << car_info[i].driveType << endl;
                    cout << "MinPrice:              " << car_info[i].minPrice << endl;
                    cout << "MaxPrice:              " << car_info[i].maxPrice << endl;
                    cout << "Mileage:               " << car_info[i].mileage << endl;
                    cout << "Transmission:          " << car_info[i].transmission << endl;
                    cout << "Color:                 " << car_info[i].color << endl;
                }
            }
        }
    }
    else if (choos == "many") {
        string input1 = "";
        string input2 = "";
        string input6 = "";
        string input7 = "";

        cout << "Enter filter for car info. Make,Drivetype,Transmission,Color" << endl;

        cout << "Make: " << endl;
        cin >> input1;

        cout << "DriveType: " << endl;
        cin >> input2;

        cout << "Transmission: " << endl;
        cin >> input6;

        cout << "Color: " << endl;
        cin >> input7;

        for (int i = 0; i < 6; i++) {
            if (toUpWord(car_info[i].make) == toUpWord(input1) && toUpWord(car_info[i].driveType) == toUpWord(input2) && toUpWord(car_info[i].transmission) == toUpWord(input6) && toUpWord(car_info[i].color) == toUpWord(input7)) {
                cout << "Make:                  " << car_info[i].make << endl;
                cout << "DriveType:             " << car_info[i].driveType << endl;
                cout << "MinPrice:              " << car_info[i].minPrice << endl;
                cout << "MaxPrice:              " << car_info[i].maxPrice << endl;
                cout << "Mileage:               " << car_info[i].mileage << endl;
                cout << "Transmission:          " << car_info[i].transmission << endl;
                cout << "Color:                 " << car_info[i].color << endl;
            }
        }
    }
    else {
        cout << "Input many or singl" << endl;
        goto region1;
    }

    for (int i = 0; i < 6; i++) {

        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Make:                  " << car_info[i].make << endl;
        cout << "DriveType:             " << car_info[i].driveType << endl;
        cout << "MinPrice:              " << car_info[i].minPrice << endl;
        cout << "MaxPrice:              " << car_info[i].maxPrice << endl;
        cout << "Mileage:               " << car_info[i].mileage << endl;
        cout << "Transmission:          " << car_info[i].transmission << endl;
        cout << "Color:                 " << car_info[i].color << endl;
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
