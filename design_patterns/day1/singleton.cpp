#include <iostream>
using namespace std;
class Singleton {
    static Singleton* uniqueInstance;
    string singletonData = "";
    Singleton()
    {
    }

public:
    static Singleton* Instance()
    {
        if (uniqueInstance == NULL)
            uniqueInstance = new Singleton();

        return uniqueInstance;
    }

public:
    void SingletonOperation()
    {
        singletonData = "SingletonData";
    }

    string GetSingletonData()
    {
        return singletonData;
    }
};

int main()
{
    Singleton* instance1;
    instance1->Instance();
    instance1->SingletonOperation();
    string singletonData = instance1->GetSingletonData();
    cout << singletonData;
    return 0;
}
