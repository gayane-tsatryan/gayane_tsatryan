#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    cout << "Enter the number for multiplication table: ";
    cin >> a;
    int i = 0;
    while (i <= 10) {
      b = a * i;
      cout << a << " * " << i << " = " << b << "\n";
      i++;
    }
    return 0;
}


