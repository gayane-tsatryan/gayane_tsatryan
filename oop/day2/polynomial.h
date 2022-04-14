class polynomial {
public:
    int *coeff;
    int _degree = 0;

    int GetData();
    int Display(int *coeff, int _degree);
    void Add(polynomial P1, polynomial P2);
    void Substract(polynomial P1, polynomial P2);
    void Multiply(polynomial P1, polynomial P2);
    void MultByNumber(int a);
};
