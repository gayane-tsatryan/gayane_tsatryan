#include "employee.h"
public:
FarmerType farmer::getFarmerType()
{
    return _farmerType;
}
string farmer::getRanchoAddress()
{
    returnt _ranchoAddress;
}
int farmer::getAnimalsCount()
{
    return _animalsCount;
}
int farmer::getAreaGreenHouse()
{
    return _areGreenHouse;
}
int farmer::getPetsCount()
{
    return _petsCount;
}
void farmer::setFarmerType(FarmerType farmerType)
{
    if (farmerType == planta || farmerType == pets || farmerType == animals) {
        _farmerType = farmerType;
    }
}
void farmer::setRanchoAddress(string ranchoAddress)
{
    _ranchoAddress = ranchoAddress;
}
void farmer::setAnimalsCount(int animalsCount)
{
    if (animalsCount >= 0) {
        _animalsCount = animalsCount;
    }
}
void farmer::setAreaGreenHouse(int areaGreenHouse)
{
    if (areaGreenHouse >= 0) {
        _areaGreenHouse = areaGreenHouse;
    }
}
void farmer::setPetsCount(int petsCount)
{
    if (petsCount >= 0) {
        _petsCount = petsCount;
    }
}
farmer::farmer(const employee& employee, FarmerType farmerType, string ranchoAddress, int animalsCount, int areGreenHouse, int petsCount)
    : employee(employee)
{
    FarmerType _farmerType = farmerType;
    string _ranchoAddress = ranchoAddress;
    int _animalsCount = animalsCount;
    int _areGreenHouse = areGreenHouse;
    int _petsCount = petsCount;
}
farmer::farmer(const employee& employee, FarmerType farmerType, string ranchoAddress, int animalsCount, int areGreenHouse)
    : employee(employee)
{
    FarmerType _farmerType = farmerType;
    string _ranchoAddress = ranchoAddress;
    int _animalsCount = animalsCount;
    int _areGreenHouse = areGreenHouse;
}
farmer::farmer(const employee& employee, FarmerType farmerType, string ranchoAddress, int animalsCount, int petsCount)
    : employee(employee)
{
    FarmerType _farmerType = farmerType;
    string _ranchoAddress = ranchoAddress;
    int _animalsCount = animalsCount;
    int _petsCount = petsCount;
}
farmer::farmer(const employee& employee, FarmerType farmerType, string ranchoAddress, int areGreenHouse, int petsCount)
    : employee(employee)
{
    FarmerType _farmerType = farmerType;
    string _ranchoAddress = ranchoAddress;
    int _areGreenHouse = areGreenHouse;
    int _petsCount = petsCount;
}
farmer::farmer(const employee& employee, FarmerType farmerType, string ranchoAddress, int petsCount)
    : employee(employee)
{
    FarmerType _farmerType = farmerType;
    string _ranchoAddress = ranchoAddress;
    int _petsCount = petsCount;
}
farmer::farmer(const employee& employee, FarmerType farmerType, string ranchoAddress, int areGreenHouse)
    : employee(employee)
{
    FarmerType _farmerType = farmerType;
    string _ranchoAddress = ranchoAddress;
    int _areGreenHouse = areGreenHouse;
}
farmer::farmer(const employee& employee, FarmerType farmerType, string ranchoAddress, int animalsCount)
    : employee(employee)
{
    FarmerType _farmerType = farmerType;
    string _ranchoAddress = ranchoAddress;
    int _animalsCount = animalsCount;
}
