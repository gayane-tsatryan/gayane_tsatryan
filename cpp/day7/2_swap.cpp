#include <iostream>
using namespace std;

void swap(int * number1, int * number2) {
  int temp = * number1;
  * number1 = * number2;
  * number2 = temp;

}
int main() {
  int number1 = 8, number2 = 45;
  cout << "Enter the number1: ";
  cin >> number1;
  cout << "Enter the number2: ";
  cin >> number2;
  cout << "number1 = " << number1 << "  number2 = " << number2 << endl;

  swap(number1, number2);
  cout << "number1 = " << number1 << "  number2 = " << number2 << endl;
  return 0;
}
