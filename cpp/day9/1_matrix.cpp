#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int height, width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;
    int** matrix = new int*[height];
    for (int** ptr = matrix; ptr < matrix + height; ptr++) {
        *ptr = new int[width];
        for (int* ptr1 = *ptr; ptr1 < *ptr + width; ptr1++) {
            *ptr1 = rand() % 9 + 1;
        }
    }
    print_matrix(matrix, width, height);
    cout << endl;
    sort_matrix(matrix, width, height);
    cout << endl;
    print_matrix(matrix, width, height);
    cout << endl;
    sortMinToMax(matrix, width, height);
    print_matrix(matrix, width, height);
    cout << endl;
    return 0;
}
