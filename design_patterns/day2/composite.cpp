#include <iostream>
using namespace std;

class Component {
protected:
    string _name = "";

public:
    Component(string name)
    {
        _name = name;
    }

    virtual void Operation() = 0;
    virtual void Add(Component* component) = 0;
    virtual void Remove(Component* component) = 0;
    virtual Component* GetChild(int index) = 0;
};
class Composite : public Component {
    ArrayList nodes = new ArrayList();

public:
    Composite(string name)
    {
        _name = name;
    }

    void Operation() override
    {
        cout << _name << endl;

        for (Component* component : nodes)
            component->Operation();
    }

    void Add(Component* component) override
    {
        nodes.Add(component);
    }

    void Remove(Component* component) override
    {
        nodes.Remove(component);
    }

    Component* GetChild(int index) override
    {
        Component* instance = nodes[index];
        return instance;
    }
};
class Leaf : public Component {
public:
    Leaf(string name)
    {
        _name = name;
    }

    void Operation() override
    {
        cout << _name;
    }

    void Add(Component* component) override
    {
        throw new exception();
    }

    void Remove(Component* component) override
    {
        throw new exception();
    }

    Component* GetChild(int index) override
    {
        throw new exception();
    }
};
int main()
{
    Component* root = new Composite("ROOT");
    Component* branch1 = new Composite("BR1");
    Component* branch2 = new Composite("BR2");
    Component* leaf1 = new Leaf("L1");
    Component* leaf2 = new Leaf("L2");

    root->Add(branch1);
    root->Add(branch2);
    branch1->Add(leaf1);
    branch2->Add(leaf2);

    root->Operation();

    branch2->GetChild(0)->Operation();
    return 0;
}
