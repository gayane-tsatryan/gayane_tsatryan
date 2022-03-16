#include <iostream>
using namespace std;

void maxMinValueOfArray(int length) {
  int max = 0;
  int min = 0;
  int * parray = new int[length];
  for (int i = 0; i < length; i++) {
    *(parray + i) = rand() % 10 + 1;
    cout << " " << * (parray + i);
  }
  cout << endl;
  min = * (parray);
  max = * (parray);
  for (int *ptr = parray; ptr != (parray + length); ptr++) {
    if (min > * ptr) {
      min = * ptr;
    } else if (max < * ptr) {
      max = * ptr;
    }

  }
  cout << "min = " << min << endl << "max = " << max;

}
int main() {
  int length;
  cout << "Input the length of array: ";
  cin >> length;
  maxMinValueOfArray(length);
  return 0;
}
