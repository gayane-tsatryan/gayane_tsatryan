#include <iostream>
using namespace std;
class polynomial {
    int a[' '], b[' '], c[' '], i, j, m, n, x;

public:
    void get_date();
    void Add();
    void SubSract();
    void display();
};
void polynomial::get_date()
{
    cout << "Enter the first polynomial ";
    cin >> n;
    for (i = 0; i <= n; i++) {
        cout << "Enter the coeficent exp = " << i << endl;
        cin >> a[i];
    }
    cout << "Enter second polynomial" << endl;
    cin >> m;
    for (i = 0; i <= m; i++) {
        cout << "Enter the coeficent exp = " << i << endl;
        cin >> b[i];
    }
}

void polynomial::Add()
{
    if (m == n) {
        for (i = 0; i <= n; i++) {
            c[i] = a[i] + b[i];
        }
    }
    else if (m > n) {
        for (i = 0; i <= m; i++) {
            if (i <= n) {
                c[i] = a[i] + b[i];
            }
            else {
                c[i] = b[i];
            }
        }
    }
    else if (n > m) {
        for (i = 0; i <= n; i++) {
            if (i <= m) {

                c[i] = a[i] + b[i];
            }
            else {
                c[i] = a[i];
            }
        }
    }
}
void polynomial::SubSract()
{
    if (m == n) {
        for (i = 0; i <= n; i++) {
            if (a[i] - b[i] != 0) {
                c[i] = a[i] - b[i];
            }
        }
    }
    else if (m > n) {
        for (i = 0; i <= m; i++) {
            if (i <= n) {
                c[i] = a[i] - b[i];
            }
            else {
                c[i] = b[i];
            }
        }
    }
    else if (n > m) {
        for (i = 0; i <= n; i++) {
            if (i <= m) {

                c[i] = a[i] - b[i];
            }
            else {
                c[i] = a[i];
            }
        }
    }
}

void polynomial::display()
{
    x = i - 1;
    for (j = i - 1; j >= 0; j--) {
        if (j == 0) {
            cout << c[j];
            break;
        }
        cout << c[j] << "x^" << x << "+";
        x--;
    }
}
int main()
{
    polynomial p;
    p.get_date();
    p.Add();
    cout << "Result" << endl;
    p.display();
    p.SubSract();
    cout << "Result" << endl;
    p.display();
    return 0;
}
