
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
void printCar(carInfo);
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
region2:
    string searchn;
    string searchm;
    cout << "For see all cars info Input  SHOW \n Input FILTER for search. " << endl;
    cin >> searchn;
    if (toUpWord(searchn) == toUpWord("show")) {
        for (int i = 0; i < 6; i++) {

            printCar(car_info[i]);
        }
        cout << "For  filter input F\n for finish input EXIT" << endl;
    region3:
        cin >> searchm;
        if (toUpWord(searchm) == toUpWord("f")) {
            goto region1;
        }
        else if (toUpWord(searchm) == toUpWord("exit")) {
            return 0;
        }
        else {
            cout << "For  filter input F\n for finish input EXIT" << endl;
            goto region3;
        }
    }
    else if (toUpWord(searchn) == toUpWord("filter")) {

    region1:
        string choos = "";
        cout << "Input search mode ( 1 or 2 or 7): ";
        cin >> choos;
        if (choos == "7") {

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

                    printCar(car_info[i]);
                }
            }
        }
        else if (choos == "1") {
            string inp;
            cout << "Input parameter for filter:  ";
            cin >> inp;

            bool b = isNumber(inp);
            if (b) {
                int inp1 = stoi(inp);
                for (int i = 0; i < 6; i++) {
                    if (car_info[i].minPrice == inp1 || car_info[i].maxPrice == inp1 || car_info[i].mileage == inp1) {
                        printCar(car_info[i]);
                    }
                }
            }
            else {
                for (int i = 0; i < 6; i++) {
                    if (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) {

                        printCar(car_info[i]);
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
                    printCar(car_info[i]);
                }
            }
        }

        else if (choos == "some") {
            string inp, inp1, inp2;
            cout << "Input 3 parameter" << endl;
            cin >> inp;
            cin >> inp1;
            cin >> inp2;

            for (int i = 0; i < 6; i++) {
                if ((toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2))) {
                    printCar(car_info[i]);
                }
            }
        }
        else if (choos == "2") {
            string inp, inp1;
            cout << "Input 2 parameter" << endl;
            cin >> inp;
            cin >> inp1;
            bool a = false, b = false;
            if (isNumber(inp)) {
                a = true;
            }
            if (isNumber(inp1)) {
                b = true;
            }
            if (a == true && b == false) {
                for (int i = 0; i < 6; i++) {
                    if ((toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp))) {
                        printCar(car_info[i]);
                    }
                }
            }
            else if (a == true && b == true) {
                for (int i = 0; i < 6; i++) {
                    cout << "AAAA";
                    if ((car_info[i].minPrice >= stoi(inp) && (car_info[i].minPrice <= stoi(inp1))) || (car_info[i].maxPrice >= stoi(inp) && car_info[i].maxPrice <= stoi(inp1))) {
                        printCar(car_info[i]);
                    }
                }
            }
        }

        else {
            cout << "Input many or singl" << endl;
            goto region1;
        }
    }
    else {

        cout << "Input SHOW or FILTER";
        goto region2;
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
    cout << "MaxPrice:              " << car_info.maxPrice << endl;
    cout << "Mileage:               " << car_info.mileage << endl;
    cout << "Transmission:          " << car_info.transmission << endl;
    cout << "Color:                 " << car_info.color << endl;
    cout << "-----------------------------------------------------" << endl;
}
