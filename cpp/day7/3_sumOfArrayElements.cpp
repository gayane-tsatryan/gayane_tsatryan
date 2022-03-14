#include <iostream>
using namespace std;

int sumOfArrayElements(int length) {
  int sum = 0;
  int * parray = new int[length];
  for (int i = 0; i < length; i++) {
    *(parray + i) = rand() % 10 + 1;
  }
  for (int i = 0; i < length; i++) {

    sum = sum + * (parray++);
  }
  return sum;
}
int main() {
  int length;
  cout << "Input the length of array: ";
  cin >> length;
  cout << "Elements  valuea sum is " << sumOfArrayElements(length) << endl;
  return 0;
}
