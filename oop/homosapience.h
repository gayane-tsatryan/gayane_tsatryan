#include "human.h";
enum Nationality { arm, rus, eng };
enum Religion { Christianity,
    caballa,
    islam };
class HomoSapience : public Human {
private:
    string _address;
    string _name;
    string _surname;
    string _fatherName;
    string _motherName;
    Nationality _nationality;
    Religion _religion;

public:
    void Party();
    void Work();
    void Dance();
    void GoToGym();
    HomoSapience();
};
