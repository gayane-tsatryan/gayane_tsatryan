#include <iostream>
using namespace std;

void multipleTable(int multiplNumber)
{
    int result;
    int i = 0;
    while (i <= 10) {
        result = multiplNumber * i;
        cout << multiplNumber << " * " << i << " = " << result << "\n";
        i++;
    }
}
int main()
{
    int multiplNumber;
    cout << "Enter the number for multiplication table: ";
    cin >> multiplNumber;
    multipleTable(multiplNumber);
    return 0;
}
