#include <string>
#include <iostream>
#include "homosapience.h"
using namespace std;

class employee : public homosapience {
private:
    string _idNumber = "";
    string _department = "";
    string _position = "";
    int _yearsWorked = 0;

public:
    employee(const homosapience& homosapience, string idNum, string depart, string pos, int yrsWrkd);
    employee(const homosapience& homosapience, string idNum);
    employee();
    ~employee();

    void setIdnumber(string idNum);
    void setDepartment(string depart);
    void setPos(string pos);
    void setYEARS(int yrsWrkd);
    string const getID();
    string const getDPT();
    string const getPOS();
    int const getYEARS();
};
