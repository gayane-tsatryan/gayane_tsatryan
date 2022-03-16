#include "atoi.h"
#include <iostream>
using namespace std;
int my_atoi(char* a)
{
    int result = 0;
    for (int i = a[0] == '-' ? 1 : 0; a[i] != '\0'; i++) {
        if (a[i] >= 48 && a[i] <= 57) {
            result = result * 10 + a[i] - '0';
        }
        else {
            result = 0;
        }
    }

    return a[0] == '-' ? -result : result;
}
