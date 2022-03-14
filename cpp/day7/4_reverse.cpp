#include <iostream>
using namespace std;

void reverseArray(int length) {
  int temp = 0;
  int * parray = new int[length];
  for (int i = 0; i < length; i++) {
    *(parray + i) = rand() % 10 + 1;
    cout << * (parray + i);
  }
  for (int i = 0; i < length / 2; i++) {
    temp = * (parray + i);
    *(parray + i) = * (parray + length - 1 - i);
    *(parray + length - 1 - i) = temp;

  }
  cout << endl;
  for (int i = 0; i < length; i++) {

    cout << * (parray + i);
  }

}
int main() {
  int length;
  cout << "Input the length of array: ";
  cin >> length;
  reverseArray(length);
  return 0;
}
