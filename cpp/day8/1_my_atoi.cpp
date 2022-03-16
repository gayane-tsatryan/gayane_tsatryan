#include "atoi.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
    int sum1 = 0, sum2 = 0;
    for(int *ptr = argv; ptr != (argv + argc); ptr++)
    {
        sum1 += my_atoi (*ptr);
        sum2 += atoi (*ptr);
    }
    cout << "my_atoi - " << sum1 << endl; 
    cout << "atoi - " << sum2 << endl; 
    return 0;
}
