#include <iostream>
using namespace std;
int main(void)
{
    int x[4], y[4];

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    if ((x[1] - x[0]) * (x[3] - x[2]) + (y[3] - y[2]) * (y[1] - y[0]) == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No." << endl;
    }

    return 0;
}
