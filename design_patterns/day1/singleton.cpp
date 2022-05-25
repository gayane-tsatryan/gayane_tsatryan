#include <iostream>
using namespace std;
class Singleton {
    static Singleton* uniqueInstance;
    string singletonData = "";
    Singleton()
    {
    }

public:
    static Singleton* getInstance()
    {
        if (uniqueInstance == NULL)
            uniqueInstance = new Singleton();

        return uniqueInstance;
    }
    void SingletonOperation(string data)
    {
        singletonData = data;
    }

    string GetSingletonData()
    {
        return singletonData;
    }
};
Singleton* Singleton::uniqueInstance = nullptr;
int main()
{
    Singleton* instance1 = Singleton::getInstance();
    // instance1=Singleton.Instance();
    instance1->SingletonOperation("Data");
    string singletonData = instance1->GetSingletonData();
    cout << singletonData;
    return 0;
}
