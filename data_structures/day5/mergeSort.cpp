#include <iostream>
using namespace std;

void mergeSort(int*);
void merge(int*, int, int, int);
void merge_sort(int*, int, int);

int main()
{
    int arr[] = { 5, 4, 7, 3, 6, 5, 1, 2 };
    mergeSort(arr);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i];
    }
    cout << sizeof(arr) / sizeof(arr[0]);
}

void merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high) {

        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, c[sizeof(arr) / sizeof(arr[0])];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}
void mergeSort(int* array)
{
    int length = sizeof(array) / sizeof(array[0]);
    merge_sort(array, 0, length - 1);
};
