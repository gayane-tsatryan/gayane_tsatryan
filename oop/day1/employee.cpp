#include "employee.h"

employee::employee(const homosapience& homosapience, string idNum, string depart, string pos, int yrsWrkd)
    : homosapience(homosapience)
{
    _idNumber = idNum;
    _department = depart;
    _position = pos;
    _yearsWorked = yrsWrkd;
}
employee::employee(const homosapience& homosapience, string idNum)
    : homosapience(homosapience)
{
    _idNumber = idNum;
    _department = " ";
    _position = " ";
    _yearsWorked = 0;
}

void employee::setIdnumber(string idNum)
{
    _idNumber = idNum;
}
void employee::setDepartment(string depart)
{
    _department = depart;
}
void employee::setPos(string pos)
{
    _position = pos;
}
void employee::setYEARS(int yrsWrkd)
{

    if (yrsWrkd < 0) {
        cout << "Can not set number smaller 0!" << endl;
    }
    else
        _yearsWorked = yrsWrkd;
}

string const employee::getID()
{
    return _idNumber;
}
string const employee::getDPT()
{
    return _department;
}
string const employee::getPOS()
{
    return _position;
}
int const employee::getYEARS()
{
    return _yearsWorked;
}
