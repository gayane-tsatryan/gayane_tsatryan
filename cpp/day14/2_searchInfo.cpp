#include <iostream>
#include <fstream>
using namespace std;

struct info {
    string countryName;
    string capital;
    string domain;
    int population;
    int area;
    int gdp;
    int phonecode;
};
enum enum1 {
    Armenia = 374,
    Brazil = 55,
    Chile = 56,
    Russia = 7,
    Georgia = 995,
    Germany = 49,
    France = 33
};
int main(int argc, char* argv[])
{
    enum1 en;
    int earr[7] = { Armenia, Brazil, Chile, Russia, Georgia, Germany, France };
    struct info info1[7];
    ofstream MyFile("filename.txt");
    MyFile << "Armenia Yerevan .am 3300000 29743 1260000\nBrazil Brazil .br 1300000 329743 4520000\nChile Santioago .cl 12000000 479743 230000\nRussia Moscow .ru 23000000 3209743 7000000\nGeorgia Tbilisi .ge 2300000 32743 500000\nGermany Berlin .de 7300000 23743 6580000\nFrance Pariz .fr 8900000 459743 9000000";
    MyFile.close();
    string str = "";
    string sarr[6];
    ifstream mfile("filename.txt");
    int i = 0;
    int temp = 0;
    // string stemp="";
    while (!mfile.eof()) {
        mfile >> str;
        /* for(int j = 0; str[j]!=','; j++)
		  {   
		      stemp+=str[j];
		  }
		  sarr[i] = stemp;
		  stemp = ""; */
        sarr[i] = str;
        i++;
        if (i == 6) {
            info1[temp].countryName = sarr[0];
            info1[temp].capital = sarr[1];
            info1[temp].domain = sarr[2];
            info1[temp].population = stoi(sarr[3]);
            info1[temp].area = stoi(sarr[4]);
            info1[temp].gdp = stoi(sarr[5]);
            info1[temp].phonecode = earr[temp];
            i = 0;
            temp++;
        }
    }

    mfile.close();

    if (argv[1] == "compare") {
        string index1, index2;
        cout << "Input   first country:";
        cin >> index1;
        cout << "Input  second country";
        cin >> index2;
        int x1, x2;
        for (int i = 0; i < 8; i++) {
            if (index1 == info1[i].countryName) {
                x1 = i;
            }

            if (index2 == info1[i].countryName) {
                x2 = i;
            }
        }

        cout << "========================================" << endl;
        cout << "\t\t|" << info1[x1].countryName << "\t|" << info1[x2].countryName << endl;
        cout << "========================================" << endl;
        cout << "Capital"
             << "\t\t|" << info1[x1].capital << "\t|" << info1[x2].capital << endl;
        cout << "Domain"
             << "\t\t|" << info1[x1].domain << "\t\t|" << info1[x2].domain << endl;
        if (info1[x1].population > info1[x2].population) {
            cout << "Population"
                 << "\t|" << info1[x1].population << "\t>" << info1[x2].population << endl;
        }
        else if (info1[x1].population < info1[x2].population) {
            cout << "Population"
                 << "\t|" << info1[x1].population << "\t<" << info1[x2].population << endl;
        }
        else {
            cout << "Population"
                 << "\t|" << info1[x1].population << "\t=" << info1[x2].population << endl;
        }

        if (info1[x1].area > info1[x2].area) {
            cout << "Area"
                 << "\t\t|" << info1[x1].area << "\t\t>" << info1[x2].area << endl;
        }
        else if (info1[x1].area < info1[x2].area) {
            cout << "Area"
                 << "\t\t|" << info1[x1].area << "\t\t<" << info1[x2].area << endl;
        }
        else {
            cout << "Area"
                 << "\t\t|" << info1[x1].area << "\t\t=" << info1[x2].area << endl;
        }

        if (info1[x1].gdp > info1[x2].gdp) {
            cout << "GDP"
                 << "\t\t|" << info1[x1].gdp << "\t>" << info1[x2].gdp << endl;
        }
        else if (info1[x1].gdp < info1[x2].gdp) {
            cout << "GDP"
                 << "\t\t|" << info1[x1].gdp << "\t<" << info1[x2].gdp << endl;
        }
        else {
            cout << "GDP"
                 << "\t\t|" << info1[x1].gdp << "\t=" << info1[x2].gdp << endl;
        }

        cout << "Phone code"
             << "\t|" << info1[x1].phonecode << "\t\t|" << info1[x2].phonecode << endl;
    }

    else if (argv[1] == "search") {
        string input = "";
        string input1 = "";
        cout << "Input search mode (countryName / capital / domain): ";
        cin >> input;
        cout << "input " << input << ":";
        cin >> input1;

        if (input == "capital") {
            for (int i = 0; i < 7; i++) {
                if (info1[i].capital == input1) {
                    cout << "Output:  Country - " << info1[i].countryName << endl;
                    cout << "\t Capital - " << info1[i].capital << endl;
                    cout << "\t Domain - " << info1[i].domain << endl;
                    cout << "\t Population - " << info1[i].population << endl;
                    cout << "\t Area - " << info1[i].area << endl;
                    cout << "\t GDP - " << info1[i].gdp << endl;
                    cout << "\t Phone Code - " << info1[i].phonecode << endl;
                }
            }
        }
        else if (input == "countryName") {
            for (int i = 0; i < 7; i++) {
                if (info1[i].countryName == input1) {
                    cout << "Output:  Country - " << info1[i].countryName << endl;
                    cout << "\t Capital - " << info1[i].capital << endl;
                    cout << "\t Domain - " << info1[i].domain << endl;
                    cout << "\t Population - " << info1[i].population << endl;
                    cout << "\t Area - " << info1[i].area << endl;
                    cout << "\t GDP - " << info1[i].gdp << endl;
                    cout << "\t Phone Code - " << info1[i].phonecode << endl;
                }
            }
        }
        else if (input == "domain") {
            for (int i = 0; i < 7; i++) {
                if (info1[i].domain == input1) {
                    cout << "Output:  Country - " << info1[i].countryName << endl;
                    cout << "\t Capital - " << info1[i].capital << endl;
                    cout << "\t Domain - " << info1[i].domain << endl;
                    cout << "\t Population - " << info1[i].population << endl;
                    cout << "\t Area - " << info1[i].area << endl;
                    cout << "\t GDP - " << info1[i].gdp << endl;
                    cout << "\t Phone Code - " << info1[i].phonecode << endl;
                }
            }
        }
        else {
            cout << "Please Input search mode (countryName / capital / domain): " << endl;
        }
    }
