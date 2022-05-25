#include <iostream>
using namespace std;

class Component {
public:
    virtual void Operation() = 0;
};
class ConcreteComponentA : public Component {
public:
    void Operation() override
    {
        cout << "ConcreteComponentA.Operation()";
    }
};
class ConcreteComponentB : public Component {
public:
    void Operation() override
    {
        cout << "ConcreteComponentB.Operation()";
    }
};
class ConcreteDecorator : public Component {
public:
    Component* Component;

    void AddedBehavior()
    {
        cout << "AddedBehavior";
    }

    void Operation() override
    {
        if (Component != NULL)
            Component->Operation();

        AddedBehavior();
    }
};

int main()
{

    ConcreteDecorator* decorator = new ConcreteDecorator();

    Component* component = new ConcreteComponentA();
    decorator->Component = component;
    decorator->Operation();

    cout << "\n---------------------------------" << endl;

    component = new ConcreteComponentB();
    decorator->Component = component;
    decorator->Operation();

    return 0;
}
