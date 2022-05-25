#include <iostream>
using namespace std;
class Adaptee {
public:
    void SpecificRequest()
    {
        cout << "Adaptee.SpecificRequest";
    }
};
class Target {
public:
    virtual void Request() = 0;
};

class Adapter : Target {
    Adaptee* adaptee = new Adaptee();

public:
    void Request() override
    {
        adaptee->SpecificRequest();
    }
};
int main()
{
    Target* target = new Adapter();
    target->Request();
    return 0;
}
