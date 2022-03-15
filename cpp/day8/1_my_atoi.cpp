#include "atoi.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < argc; i++) {
        sum1 += my_atoi(argv[i]);
    }
    for (int i = 0; i < argc; i++) {
        sum2 += atoi(argv[i]);
    }
    cout << "my_atoi -  " << sum1 << endl << "atoi -   " << sum2 << endl;
    return 0;
}



