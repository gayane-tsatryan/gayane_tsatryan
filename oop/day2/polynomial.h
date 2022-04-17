class polynomial {
public:
    int *coeff = NULL;
    int _degree = 0;
    polynomial(int*, int);
    polynomial(); 
    ~polynomial();
    int GetData();
    int Display(int *coeff, int _degree);
    void Add(polynomial P1, polynomial P2);
    void Substract(polynomial P1, polynomial P2);
    void Multiplay(polynomial P1, polynomial P2);
    void MultByNumber(int a, polynomial P);
    
    polynomial operator+(const polynomial&) const;
    polynomial &operator+=(const polynomial&);
    polynomial operator-(const polynomial&) const;
    polynomial &operator-=(const polynomial&);
    polynomial operator*(const polynomial&) const;
    polynomial &operator*=(const polynomial&);
    bool operator==(const polynomial&) const;
    std::ostream &operator<<(std::ostream&, const polynomial&);
    std::istream &operator>>(std::istream&, polynomial&);
};

