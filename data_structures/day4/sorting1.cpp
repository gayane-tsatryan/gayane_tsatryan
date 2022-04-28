#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int arr[10000];
    int copy[10000];
    for (int i = 0; i < 10000; i++) {
        int random = rand() % 10000 + 1;
        arr[i] = random;
        copy[i] = arr[i];
    }
    clock_t start3 = clock();

    int key, j;
    for (int i = 1; i < 10000; i++) {
        key = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < 10000; i++) {
        cout << arr[i] << endl;
    }

    clock_t end3 = clock();
    double finish3 = double(end3 - start3) / CLOCKS_PER_SEC;
    ///////////
    for (int i = 0; i < 10000; i++) {
        arr[i] = copy[i];
    }

    /////bubble/////
    clock_t start = clock();
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000 - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    double finish = double(end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < 10000; i++) {
        arr[i] = copy[i];
    }

    ///////// our insertion/////////////
    clock_t start2 = clock();
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < i; j++) {

            if (arr[j] > arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    clock_t end2 = clock();
    ////////////////end insertion/////////////
    double finish2 = double(end2 - start2) / CLOCKS_PER_SEC;

    clock_t start1 = clock();

    bool swapped = false;
    for (int i = 0; i < 10000; i++) {
        swapped = false;
        for (int j = 0; j < 10000 - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }

    clock_t end1 = clock();

    double finish1 = double(end1 - start1) / CLOCKS_PER_SEC;

    for (int i = 0; i < 10000; i++) {
        arr[i] = copy[i];
    }

    cout << "\nBubble sorting : " << finish << endl;
    cout << "\nBubble sorting swap: " << finish1 << endl;
    cout << "\nInsertion1 sorting : " << finish2 << endl;
    cout << "\nInsertion sorting : " << finish3 << endl;

    return 0;
}
