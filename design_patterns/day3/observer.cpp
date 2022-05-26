#include <iostream>
#include <vector>
using namespace std;
class Magazine {
public:
    string Title;
    string Content;
};
class AbstractSubscriber {
public:
    virtual void Deliver() = 0;
};
class AbstractPublisher {
private:
    vector<AbstractSubscriber*> subscriberList;

public:
    void AddToClientList(AbstractSubscriber* abstractSubscriber)
    {
        subscriberList.push_back(abstractSubscriber);
    }

    void DeleteFromClientList(AbstractSubscriber* abstractSubscriber)
    {
        for (int i = 0; i < subscriberList.size(); i++) {
            if (subscriberList[i] == abstractSubscriber) {
                subscriberList.erase(subscriberList.begin() + i);
            }
        }
    }

    void SendMagazineToClient()
    {
        for (int i = 0; i < subscriberList.size(); i++) {
            subscriberList[i].Deliver();
        }
    }
};

class MicrosoftPress : AbstractPublisher {
public:
    Magazine* Magazine;
};
class Subscriber : public AbstractSubscriber {
private:
    string name;
    Magazine* magazine;
    MicrosoftPress* publisher;

public:
    Subscriber(MicrosoftPress* publisher, string name)
    {
        this->publisher = publisher;
        this->name = name;
    }

    void Deliver() override
    {
        magazine = publisher->Magazine;
        cout << "Подписчик " << name << " получил журнал: " << magazine->Title << "  со статьей : \n" << magazine->Content;
    }
};

int main()
{
    // Издатель.
    MicrosoftPress* publisher = new MicrosoftPress();

    // Подписчики.
    Subscriber* subscriber1 = new Subscriber(publisher, "Ivan");
    Subscriber* subscriber2 = new Subscriber(publisher, "Anton");
    Subscriber* subscriber3 = new Subscriber(publisher, "Alex");
    Subscriber* subscriber4 = new Subscriber(publisher, "Serg");
    Subscriber* subscriber5 = new Subscriber(publisher, "Igor");

    //-------------- 1-й выпуск журнала ----------------

    // Добавление подписчиков.
    publisher->AddToClientList(subscriber1);
    publisher->AddToClientList(subscriber2);
    publisher->AddToClientList(subscriber3);
    publisher->AddToClientList(subscriber4);

    Magazine* magazine = new Magazine();
    magazine->Title = "msdn";
    magazine->Content = "ASP.NET: Устранение проблем в приложениях с помощью журналов IIS  ... ";

    publisher->Magazine = magazine;
    publisher->SendMagazineToClient();

    //-------------- 2-й выпуск журнала ----------------

    // Добавление нового подписчика.
    publisher->AddToClientList(subscriber5);
    // Удаление существующего подписчика.
    publisher->DeleteFromClientList(subscriber2);

    magazine = new Magazine();
    magazine->Title = "msdn";
    magazine->Content = "SQL Server: Модульное тестирование кубов OLAP в SQL Server с помощью C# ...";

    publisher->Magazine = magazine;
    publisher->SendMagazineToClient();

    return 0;
}
