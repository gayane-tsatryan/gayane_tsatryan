
#include "employee.h"
enum FarmerType { planta,
    pets,
    animals };
class farmer : public employee {
private:
    FarmerType _farmerType = planta;
    string _ranchoAddress = "";
    int _animalsCount = 0;
    int _areGreenHouse = 0;
    int _petsCount = 0;

public:
    FarmerType getFarmerType();
    string getRanchoAddress();
    int getAnimalsCount();
    int getAreaGreenHouse();
    int getPetsCount();
    void setFarmerType();
    void setRanchoAddress();
    void setAnimalsCount();
    void setAreaGreenHouse();
    void setPetsCount();
    farmer(FarmerType farmerType, string ranchoAddress, int animalsCount, int areGreenHouse, int petsCount);
    farmer(FarmerType farmerType, string ranchoAddress, int animalsCount, int areGreenHouse);
    farmer(FarmerType farmerType, string ranchoAddress, int animalsCount, int petsCount);
    farmer(FarmerType farmerType, string ranchoAddress, int areGreenHouse, int petsCount);
    farmer(FarmerType farmerType, string ranchoAddress, int petsCount);
    farmer(FarmerType farmerType, string ranchoAddress, int areGreenHouse);
    farmer(FarmerType farmerType, string ranchoAddress, int animalsCount);
    ~farmer();
};
