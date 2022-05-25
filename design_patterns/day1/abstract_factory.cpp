#include <iostream>
using namespace std;

class AbstractWater {
public:
    AbstractWater()
    {
    }
};

class CocaColaWater : public AbstractWater {
public:
    CocaColaWater()
    {
    }
};
class PepsiWater : public AbstractWater {
public:
    PepsiWater()
    {
    }
};

class AbstractBottle {
public:
    virtual void Interact(const AbstractWater& water) const = 0;
};
class CocaColaBottle : public AbstractBottle {
public:
    void Interact(const AbstractWater& water) const override
    {
        cout << " interacts with " << &water;
    }
};
class PepsiBottle : public AbstractBottle {
public:
    void Interact(const AbstractWater& water) const override
    {
        cout << " interacts with " << &water;
    }
};
class AbstractFactory {
public:
    virtual AbstractWater* CreateWater() const = 0;
    virtual AbstractBottle* CreateBottle() const = 0;
};

class CocaColaFactory : public AbstractFactory {
public:
    AbstractWater* CreateWater() const override
    {
        return new CocaColaWater();
    }

    AbstractBottle* CreateBottle() const override
    {
        return new CocaColaBottle();
    }
};
class PepsiFactory : public AbstractFactory {
public:
    AbstractWater* CreateWater() const override
    {
        return new PepsiWater();
    }

    AbstractBottle* CreateBottle() const override
    {
        return new PepsiBottle();
    }
};
class Client {
private:
    AbstractWater* water = nullptr;
    AbstractBottle* bottle = nullptr;

public:
    Client(const AbstractFactory& factory)
    {

        water = factory.CreateWater();
        bottle = factory.CreateBottle();
    }

    void Run()
    {
        bottle->Interact(*water);
    }
};
int main()
{
    Client* client;

    client = new Client(CocaColaFactory());
    client->Run();

    client = new Client(PepsiFactory());
    client->Run();
    return 0;
}
