#include <iostream>

using namespace std;

void sum1(int * a, int * b, int * sum) {
  * sum = * a + * b;
  cout << * a << " + " << * b << " = " << * sum << endl;
}
void sum2(int & a, int & b, int & sum) {
  sum = a + b;
  cout << a << " + " << b << " = " << sum << endl;
}
void sum3(int a, int b, int & sum) {
  sum = a + b;
  cout << a << " + " << b << " = " << sum << endl;
}
void sum4(int a, int * b, int & sum) {
  sum = a + * b;
  cout << a << " + " << * b << " = " << sum << endl;
}
void sum5(int * a, int * b, int & sum) {
  sum = * a + * b;
  cout << * a << " + " << * b << " = " << sum << endl;
}
int main() {
  int number1, number2, sum = 0;
  cout << "Enter the first number: ";
  cin >> number1;
  cout << "Enter the second number: ";
  cin >> number2;
  sum1( & number1, & number2, & sum);
  sum2(number1, number2, sum);
  sum3(number1, number2, sum);
  sum4(number1, & number2, sum);
  sum5( & number1, & number2, sum);
  return 0;
}
