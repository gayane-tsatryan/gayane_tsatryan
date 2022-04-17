#include <vector>
#include <string>
#include <iostream>
using namespace std;

class polynomial
{
public:
    char var = 'x^';
    const _degree;
    polynomial();
    polynomial(const poly&, const char variable);
    polynomial(const poly&);
    polynomial(const vector<int>&);
    polynomial &operator=(const poly&);
    void add(const polynomial&);
    polynomial plus(const polynomial&) const;
    polynomial operator+(const polynomial&) const;
    polynomial &operator+=(const polynomial&);
    void subtract(const polynomial&);
    polynomial minus(const polynomial&) const;
    polynomial operator-(const polynomial&) const;
    polynomial &operator-=(const polynomial&);
    void multiply(const polynomial&);
    polynomial times(const polynomial&) const;
    polynomial operator*(const polynomial&) const;
    polynomial &operator*=(const polynomial&);
    bool operator==(const polynomial&) const;
    void print(ostream&) const;
    void print(ostream&, const char variable) const;

private:
    vector<int> coeff;
};

polynomial add(const polynomial&, const polynomial&);
polynomial subtract(const polynomial&, const polynomial&);
polynomial multiply(const polynomial&, const polynomial&);

std::ostream &operator<<(ostream&, const polynomial&);
std::istream &operator>>(istream&, polynomial&);


/*class polynomial {
public:
    int *coeff;
    int _degree = 0;
    polynomial(); 
    ~ polynomial();
    int GetData();
    int Display(int *coeff, int _degree);
    void Add(polynomial P1, polynomial P2);
    void Substract(polynomial P1, polynomial P2);
    void Multiplay(polynomial P1, polynomial P2);
    void MultByNumber(int a, polynomial P);
    
    polynomial Plus(const polynomial&) const;
    polynomial operator+(const polynomial&) const;
    polynomial &operator+=(const polynomial&);
    polynomial Minus(const polynomial&) const;
    polynomial operator-(const polynomial&) const;
    polynomial &operator-=(const polynomial&);
    polynomial Mult(const polynomial&) const;
    polynomial operator*(const polynomial&) const;
    polynomial &operator*=(const polynomial&);
    bool operator==(const polynomial&) const;
    std::ostream &operator<<(std::ostream&, const polynomial&);
    std::istream &operator>>(std::istream&, polynomial&);
};
*/
