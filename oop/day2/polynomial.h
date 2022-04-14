class polynomial {
public:
    int *coeff, degree;

    int GetData();
    int Display(int *coeff, int degree);
    void Add(polynomial P1, polynomial P2);
    void Substract(polynomial P1, polynomial P2);
    void Multiply(polynomial P1, polynomial P2);
    void MultByNumber(int a);
};
