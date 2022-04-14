#include "polynomial.h"

int polynomial::GetData()
{
    int i = 0;
    cout << "Enter Degree Of Polynomial:";
    cin >> _degree;
    coeff = new int[_degree + 1];
    for (i = _degree; i >= 0; i--) {
        cout << "Enter coefficient of x^" << i << ":";
        cin >> coeff[i];
    }

    return 0;
}
int polynomial::Display(int* coeff, int _degree)
{
    int i = 0;
    int j = 0;
    bool _temp = false;
    for (i = _degree; i >= 0; i--) {
        if (coeff[i] != 0) {
            _temp = true;
            cout << coeff[i] << "x^" << i;
            if ((i - 1) != -1)
                cout << "+";
        }
    }
    if (_temp == false) {
        cout << "0";
    }
    cout << "\n";
    return 0;
}

void polynomial::Add(polynomial P1, polynomial P2)
{
    int _max = 0;
    int i = 0;
    _max = (P1._degree > P2._degree) ? P1._degree : P2._degree;
    int* addition = new int[_max + 1];
    if (P1._degree == P2._degree) {
        for (i = P1._degree; i >= 0; i--)
            addition[i] = P1.coeff[i] + P2.coeff[i];
    }

    if (P1._degree > P2._degree) {
        for (i = P1._degree; i > P2._degree; i--)
            addition[i] = P1.coeff[i];
        for (i = P2._degree; i >= 0; i--)
            addition[i] = P1.coeff[i] + P2.coeff[i];
    }

    if (P1._degree < P2._degree) {
        for (i = P2._degree; i > P1._degree; i--)
            addition[i] = P2.coeff[i];
        for (i = P1._degree; i >= 0; i--)
            addition[i] = P1.coeff[i] + P2.coeff[i];
    }
    Display(addition, _max);
}
void polynomial::Substract(polynomial P1, polynomial P2)
{
    int _max = 0;
    int i = 0;
    _max = (P1._degree > P2._degree) ? P1._degree : P2._degree;
    int* sub = new int[_max + 1];
    if (P1._degree == P2._degree) {
        for (i = P1._degree; i >= 0; i--)
            sub[i] = P1.coeff[i] - P2.coeff[i];
    }

    if (P1._degree > P2._degree) {
        for (i = P1._degree; i > P2._degree; i--)
            sub[i] = P1.coeff[i];
        for (i = P2._degree; i >= 0; i--)
            sub[i] = P1.coeff[i] - P2.coeff[i];
    }

    if (P1._degree < P2._degree) {
        for (i = P2._degree; i > P1._degree; i--)
            sub[i] = -P2.coeff[i];
        for (i = P1._degree; i >= 0; i--)
            sub[i] = P1.coeff[i] - P2.coeff[i];
    }

    Display(sub, _max);
}
void polynomial::Multiplay(polynomial P1, polynomial P2)
{
    int i = 0;
    int j = 0; 
    int _max = 0;
    _max = P1._degree + P2._degree;
    int* mul = new int[_max + 1];

    for (i = P1._degree; i >= 0; i--)
        for (j = P2._degree; j >= 0; j--)
            mul[i + j] += P1.coeff[i] * P2.coeff[j];
    Display(mul, _max);
}
void polynomial::MultByNumber(int _number, polynomial P1)
{
    int i = 0;
    int j = 0; 
    int _max = 0;
    _max = P1._degree;
    int* mul = new int[_max + 1];

    for (i = P1._degree; i >= 0; i--){
            mul[i] += P1.coeff[i] * _number;
    }
    Display(mul, _max);
}
