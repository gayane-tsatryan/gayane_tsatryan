#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
  int x;
  cout << "Enter number: \n";
  cin >> x;
  system("clear");
  int y;
  cout << "Enter number: \n";

  do {
    cin >> y;
    if (y < x) {
      cout << "Enter the larg number: \n";
    } else if (y > x) {
      cout << "Enter the small number: \n";
    }

  } while (y != x);
  cout << "You are winner!!! \n";

  return 0;
}
