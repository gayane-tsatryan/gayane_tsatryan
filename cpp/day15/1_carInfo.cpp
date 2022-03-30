#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct carInfo
{
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
	int len = 24;
	struct carInfo car_info[len];
	int z = 0;
	string str = "";
	string sarr[7];
	ifstream mfile("cars.txt");
	int i = 0;
	int temp = 0;
	while (!mfile.eof())
	{
		mfile >> str;
		sarr[i] = str;
		i++;
		if (i == 7)
		{
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
	cout << "For see all cars info Input - SHOW \nFor search input - FILTER" << endl;
	cin >> searchn;
	if (toUpWord(searchn) == toUpWord("show"))
	{
		for (int i = 0; i < len; i++)
		{

			printCar(car_info[i]);
		}
		cout << "For  filter input - F\nFor finish input - EXIT" << endl;
		region3:
			cin >> searchm;
		if (toUpWord(searchm) == toUpWord("f"))
		{
			goto region1;
		}
		else if (toUpWord(searchm) == toUpWord("exit"))
		{
			return 0;
		}
		else
		{
			cout << "For  filter input - F\nFor finish input - EXIT" << endl;
			goto region3;
		}
	}
	else if (toUpWord(searchn) == toUpWord("filter"))
	{

		region1: string choos = "";
		cout << "Input search mode (1 or 2 or 3 or 4 or 5 or 6 or 7): ";
		cin >> choos;
		if (choos == "7")
		{

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

			for (int i = 0; i < len; i++)
			{
				if (toUpWord(car_info[i].make) == toUpWord(input1) && toUpWord(car_info[i].driveType) == toUpWord(input2) && car_info[i].minPrice == input33 && car_info[i].maxPrice == input44 && car_info[i].mileage == input55 && toUpWord(car_info[i].transmission) == toUpWord(input6) && toUpWord(car_info[i].color) == toUpWord(input7))
				{

					printCar(car_info[i]);
				}
			}
		}
		else if (choos == "1")
		{
			region10: string inp;
			cout << "Input parameter for filter:  ";
			cin >> inp;

			bool b = isNumber(inp);
			if (b)
			{
				int inp1 = stoi(inp);
				for (int i = 0; i < len; i++)
				{
					if (car_info[i].minPrice == inp1 || car_info[i].maxPrice == inp1 || car_info[i].mileage == inp1)
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region10;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else
			{
				for (int i = 0; i < len; i++)
				{
					if (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp))
					{

						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region10;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else if (choos == "2")
		{
			region4: string inp,
			inp1;
			cout << "Input 2 parameter" << endl;
			cin >> inp;
			cin >> inp1;
			bool a = false,
			b = false;
			if (isNumber(inp))
			{
				a = true;
			}
			if (isNumber(inp1))
			{
				b = true;
			}
			if (a == true && b == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region4;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else if (a == true && b == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].minPrice >= stoi(inp) && (car_info[i].minPrice <= stoi(inp1))) || (car_info[i].maxPrice >= stoi(inp) && car_info[i].maxPrice <= stoi(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region4;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else if (a == false && b == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region4;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region4;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else if (choos == "3")
		{
			region5: string inp, inp1, inp2;
			cout << "Input 3 parameter" << endl;
			cin >> inp;
			cin >> inp1;
			cin >> inp2;
			bool a = false,
			b = false,
			c = false;
			if (isNumber(inp))
			{
				a = true;
			}
			if (isNumber(inp1))
			{
				b = true;
			}
			if (isNumber(inp2))
			{
				c = true;
			}
			if (a == true && b == false && c == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == true && b == true && c == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == true && b == true && c == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == false && b == false && c == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == false && b == true && c == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == false && b == true && c == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == true && b == false && c == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region5;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else if (choos == "4")
		{
			region6: string inp, inp1, inp2, inp3;
			cout << "Input 4 parameter" << endl;
			cin >> inp;
			cin >> inp1;
			cin >> inp2;
			cin >> inp3;
			bool a = false,
			b = false,
			c = false,
			d = false;
			if (isNumber(inp))
			{
				a = true;
			}
			if (isNumber(inp1))
			{
				b = true;
			}
			if (isNumber(inp2))
			{
				c = true;
			}
			if (isNumber(inp3))
			{
				d = true;
			}
			if (a == true && b == false && c == false && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}

			if (a == true && b == false && c == false && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}

			if (a == true && b == true && c == false && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == true && b == true && c == false && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp3)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == true && b == true && c == true && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}

			if (a == true && b == false && c == true && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp3)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}

			if (a == false && b == true && c == true && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == false && b == false && c == true && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}

			if (a == false && b == true && c == false && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == false && b == true && c == false && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}

			if (a == false && b == true && c == true && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)) && (car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			if (a == true && b == false && c == true && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (car_info[i].mileage <= stoi(inp) || car_info[i].minPrice <= stoi(inp) || car_info[i].maxPrice <= stoi(inp)) && (car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else if (a == false && b == false && c == false && d == true)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp3) || car_info[i].minPrice <= stoi(inp3) || car_info[i].maxPrice <= stoi(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else if (a == false && b == false && c == true && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp2) || car_info[i].minPrice <= stoi(inp2) || car_info[i].maxPrice <= stoi(inp2)) && (toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else if (a == false && b == true && c == false && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((car_info[i].mileage <= stoi(inp1) || car_info[i].minPrice <= stoi(inp1) || car_info[i].maxPrice <= stoi(inp1)) && (toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else if (a == false && b == false && c == false && d == false)
			{
				for (int i = 0; i < len; i++)
				{
					if ((toUpWord(car_info[i].make) == toUpWord(inp1) || toUpWord(car_info[i].driveType) == toUpWord(inp1) || toUpWord(car_info[i].transmission) == toUpWord(inp1) || toUpWord(car_info[i].color) == toUpWord(inp1)) && (toUpWord(car_info[i].make) == toUpWord(inp3) || toUpWord(car_info[i].driveType) == toUpWord(inp3) || toUpWord(car_info[i].transmission) == toUpWord(inp3) || toUpWord(car_info[i].color) == toUpWord(inp3)) && (toUpWord(car_info[i].make) == toUpWord(inp) || toUpWord(car_info[i].driveType) == toUpWord(inp) || toUpWord(car_info[i].transmission) == toUpWord(inp) || toUpWord(car_info[i].color) == toUpWord(inp)) && (toUpWord(car_info[i].make) == toUpWord(inp2) || toUpWord(car_info[i].driveType) == toUpWord(inp2) || toUpWord(car_info[i].transmission) == toUpWord(inp2) || toUpWord(car_info[i].color) == toUpWord(inp2)))
					{
						printCar(car_info[i]);
						z++;
					}
				}
				if (z == 0)
				{
					string sr;
					cout << "Not found!" << endl;
					cout << "For continue input - I\nFor exit input some button" << endl;
					cin >> sr;
					if (toUpWord(sr) == toUpWord("i"))
					{
						goto region6;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
		}

		if (choos == "5")
		{
			region7: string input1;
			string input3;
			string input4;
			string input5;
			string input7;

			cout << "Enter filter for car info." << endl;

			cout << "Make: " << endl;
			cin >> input1;

			cout << "MinPrice: " << endl;
			cin >> input3;

			cout << "MaxPrice: " << endl;
			cin >> input4;

			cout << "Mileage: " << endl;
			cin >> input5;

			cout << "Color: " << endl;
			cin >> input7;
			int input33 = stoi(input3);
			int input44 = stoi(input4);
			int input55 = stoi(input5);

			for (int i = 0; i < len; i++)
			{
				if (toUpWord(car_info[i].make) == toUpWord(input1) && car_info[i].minPrice <= input33 && car_info[i].maxPrice <= input44 && car_info[i].mileage == input55 && toUpWord(car_info[i].color) == toUpWord(input7))
				{

					printCar(car_info[i]);
					z++;
				}
			}
			if (z == 0)
			{
				string sr;
				cout << "Not found!" << endl;
				cout << "For continue input - I\nFor exit input some button" << endl;
				cin >> sr;
				if (toUpWord(sr) == toUpWord("i"))
				{
					goto region7;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}

		if (choos == "6")
		{
			region8: string input1;
			string input3;
			string input4;
			string input5;
			string input6;
			string input7;

			cout << "Enter filter for car info." << endl;

			cout << "Make: " << endl;
			cin >> input1;

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

			for (int i = 0; i < len; i++)
			{
				if (toUpWord(car_info[i].make) == toUpWord(input1) && car_info[i].minPrice <= input33 && car_info[i].maxPrice <= input44 && car_info[i].mileage <= input55 && toUpWord(car_info[i].transmission) == toUpWord(input6) && toUpWord(car_info[i].color) == toUpWord(input7))
				{

					printCar(car_info[i]);
				}
			}

			if (z == 0)
			{
				string sr;
				cout << "Not found!" << endl;
				cout << "For continue input - I\nFor exit input some button" << endl;
				cin >> sr;
				if (toUpWord(sr) == toUpWord("i"))
				{
					goto region8;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			cout << "Input search mode (1 or 2 or 3 or 4 or 5 or 6 or 7): " << endl;
			goto region1;
		}
	}
	else
	{

		goto region2;
	}

	return 0;
}
bool isNumber(string s)
{
	for (char c: s)
	{
		if (isdigit(c) == 0)
			return false;
	}
	return true;
}
char to_upper(char a)
{
	if (a >= 'a' && a <= 'z')
	{
		return a - 32;
	}
	return a;
}
string toUpWord(string a)
{
	string b = "";
	for (int i = 0; a[i] != '\0'; i++)
	{
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
