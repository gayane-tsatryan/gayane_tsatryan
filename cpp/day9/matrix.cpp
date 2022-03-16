#include "matrix.h"
#include <iostream>
using namespace std;

void print_matrix(int** matrix, int width = 5, int height = 5) {
        for (int** ptr = matrix; ptr < matrix + height; ptr++) {
                for (int* ptr1 = *ptr; ptr1 < *ptr + width; ptr1++) {
                        cout << *ptr1 << " ";
                }
                cout << endl;
        }
}

void sort_matrix(int** matrix, int width = 5, int height = 5) {
        int temp;
        for (int** ptr = matrix; ptr < matrix + height; ptr++) {
                for (int* ptr1 = *ptr ; ptr1 < *ptr + width - 1; ptr1++) {
                        for (int* ptr2 = ptr1 + 1; ptr2 < *ptr + width; ptr2++) {
                                if (*ptr2 < *ptr1) {
                                        temp = *ptr2; 
                                        *ptr2 = *ptr1; 
                                        *ptr1 = temp;
                                }
                        }
                }
        }
}

