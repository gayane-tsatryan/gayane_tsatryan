class polynomial {
public:
    int *coeff;
    int _degree = 0;

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
