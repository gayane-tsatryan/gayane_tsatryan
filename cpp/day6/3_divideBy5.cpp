#include <iostream>
using namespace std;

void matrix();
int main()
{
    matrix();
    return 0;
}
void matrix()
{
    int array[10];
    int temp = 0;
    int elements = 0;
    int j = 2;
    for (int i = 2; i < 1000; i++) {
        elements = i * i + j * j;
        if (elements % 5 == 0) {
            array[temp] = elements;
            cout << array[temp] << " ";
            j++;
            temp++;

            if (temp == 10) {
                break;
            }
        }
    }
    cout << endl;
}

