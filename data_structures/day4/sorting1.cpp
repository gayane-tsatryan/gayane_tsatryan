#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int arr[10000];
    int copy[10000];
    for (int i = 0; i < 10000; i++) {
        int _random = rand() % 10000 + 1;
        arr[i] = _random;
        copy[i] = arr[i];
    }
    
    clock_t _start = clock();
    int _key;
    int j = 0;
    for (int i = 1; i < 10000; i++) {
        _key = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > _key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = _key;
    }
    clock_t _end = clock();
    double _finish = double(_end - _start) / CLOCKS_PER_SEC;

    for (int i = 0; i < 10000; i++) {
        arr[i] = copy[i];
    }
   
    clock_t _start1 = clock();
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000 - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                int _temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = _temp;
            }
        }
    }
    clock_t _end1 = clock();
    double _finish1 = double(_end1 - _start1) / CLOCKS_PER_SEC;
    
    for (int i = 0; i < 10000; i++) {
        arr[i] = copy[i];
    }
    
    clock_t _start2 = clock();
    bool _swapped = false;
    for (int i = 0; i < 10000; i++) {
        _swapped = false;
        for (int j = 0; j < 10000 - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                int _temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = _temp;
                _swapped = true;
            }
        }
        if (_swapped == false) {
            break;
        }
    }
    clock_t _end2 = clock();
    double _finish2 = double(_end2 - _start2) / CLOCKS_PER_SEC;

   /*  for (int i = 0; i < 10000; i++)
    {
        cout << arr[i] << endl;
    }
    */

    cout << "\nBubble sorting : " << _finish1 << endl;
    cout << "\nBubble sorting swap: " << _finish2 << endl;
    cout << "\nInsertion sorting : " << _finish << endl;

    return 0;
}
