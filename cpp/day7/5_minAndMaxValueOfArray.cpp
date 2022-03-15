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
  for (int i = 0; i < length; i++) {
    if (min > * (parray + i)) {
      min = * (parray + i);
    } else if (max < * (parray + i)) {
      max = * (parray + i);
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
