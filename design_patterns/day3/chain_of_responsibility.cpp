#include <iostream>
using namespace std;

class Handler {
public:
    Handler* Successor = NULL;
    virtual void HandleRequest(int request) = 0;
};
class ConcreteHandler1 : public Handler {
public:
    void HandleRequest(int request) override
    {
        if (request == 1)
            cout << "One";
        else if (Successor != NULL)
            Successor->HandleRequest(request);
    }
};
class ConcreteHandler2 : public Handler {
public:
    void HandleRequest(int request) override
    {
        if (request == 2)
            cout << "Two";
        else if (Successor != NULL)
            Successor->HandleRequest(request);
    }
};
class ConcreteHandler3 : public Handler {
public:
    void HandleRequest(int request) override
    {
        if (request == 3) {
            cout << "Three";
        }
        else if (Successor != NULL) {
            Successor->HandleRequest(request);
        }
    }
};
int main()
{
    Handler* instance1 = new ConcreteHandler1();
    Handler* instance2 = new ConcreteHandler2();
    Handler* instance3 = new ConcreteHandler3();

    instance1->Successor = instance2;
    instance2->Successor = instance3;
    instance1->HandleRequest(1);
    instance1->HandleRequest(2);
    instance3->HandleRequest(3);

    return 0;
}
