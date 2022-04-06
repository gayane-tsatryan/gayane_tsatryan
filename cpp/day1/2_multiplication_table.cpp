#include <iostream>

using namespace std;
int main() {
    int number1;
    int result;
    cout << "Enter the number for multiplication table: ";
    cin >> number1;
    int i = 0;
    while (i <= 10) {
      result = number1 * i;
      cout << number1 << " * " << i << " = " << result << "\n";
      i++;
    }
    return 0;
}
