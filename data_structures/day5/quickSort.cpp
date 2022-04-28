#include <iostream>
using namespace std;

void swap(int*, int, int);
int partition(int*, int, int, int);
void quickSort(int*, int, int);
void quickSorting(int*);

int main()
{
    int arr[] = { 4, 7, 2, 5, 8 };

    quickSorting(arr);
    cout << "The sorted array is: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
}
void swap(int* arr, int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int* arr, int low, int high, int pivot)
{
    int i = low;
    int j = low;
    while (i <= high) {
        if (arr[i] > pivot) {
            i++;
        }
        else {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSort(int* arr, int low, int high)
{
    if (low < high) {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

void quickSorting(int* arr)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
}
