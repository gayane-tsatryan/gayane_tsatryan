#include "matrix.h"
#include <iostream>
using namespace std;

void print_matrix(int** matrix, int width = 5, int height = 5)
{
    for (int** ptr = matrix; ptr < matrix + height; ptr++) {
        for (int* ptr1 = *ptr; ptr1 < *ptr + width; ptr1++) {
            cout << *ptr1 << " ";
        }
        cout << endl;
    }
}

void sort_matrix(int** matrix, int width = 5, int height = 5)
{
    int temp;
    for (int** ptr = matrix; ptr < matrix + height; ptr++) {
        for (int* ptr1 = *ptr; ptr1 < *ptr + width - 1; ptr1++) {
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
void sort(int p, int* ptr)
{
    int i, j, temp1;

    for (i = 0; i < p; i++) {

        for (j = i + 1; j < p; j++) {

            if (*(ptr + j) < *(ptr + i)) {

                temp1 = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp1;
            }
        }
    }
}

void sortMinToMax(int** matrix, int width = 10, int height = 10)
{
    int s = width * height;
    int temp[s];
    int* ptemp = temp;

    for (int** ptr = matrix; ptr < matrix + height; ptr++) {
        for (int* ptr1 = *ptr; ptr1 < *ptr + width; ptr1++) {

            *(ptemp++) = *ptr1;
        }
    }

    int* ptr2 = temp;
    int n = s;
    int l = 0;
    sort(n, ptr2);
    for (int** ptr = matrix; ptr < matrix + height; ptr++) {
        for (int* ptr1 = *ptr; ptr1 < *ptr + width; ptr1++) {
            *ptr1 = temp[l];
            l++;
        }
        cout << endl;
    }
}
