#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
  int number1;
  cout << "Enter the first number: \n";
  cin >> number1;
  system("clear");
  int number2;
  cout << "Enter the second number: \n";

  do {
    cin >> number2;
    if (number2 < number1) {
      cout << "Enter the larg number: \n";
    } else if (number2 > number1) {
      cout << "Enter the small number: \n";
    }

  } while (number2 != number1);
  cout << "You are winner!!! \n";

  return 0;
}
