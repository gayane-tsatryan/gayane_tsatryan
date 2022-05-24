#include <iostream>
using namespace std;

class AbstractWater {
};

class CocaColaWater : AbstractWater {
public:
    CocaColaWater()
    {
    }
};
class PepsiWater : AbstractWater {
public:
    PepsiWater()
    {
    }
};

class AbstractBottle {
public:
    virtual void Interact(AbstractWater& water) const = 0;
};
class CocaColaBottle : AbstractBottle {
public:
    void Interact(AbstractWater& water) const override
    {
        cout << " interacts with " << &water;
    }
};
class PepsiBottle : AbstractBottle {
public:
    void Interact(AbstractWater& water) const override
    {
        cout << " interacts with " << &water;
    }
};
class AbstractFactory {
public:
    virtual AbstractWater* CreateWater() const = 0;
    virtual AbstractBottle* CreateBottle() const = 0;
};

class CocaColaFactory : AbstractFactory {
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
class PepsiFactory : AbstractFactory {
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
    AbstractWater* water;
    AbstractBottle* bottle;

public:
    Client(AbstractFactory& factory)
    {

        water = factory.CreateWater();
        bottle = factory.CreateBottle();
    }

    void Run()
    {

        bottle->Interact(*water);
    }
    int main()
    {
        Client* client;

        client = new Client(new CocaColaFactory());
        client->Run();

        client = new Client(new PepsiFactory());
        client->Run();
        return 0;
    }
