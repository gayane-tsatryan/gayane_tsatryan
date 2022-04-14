#include "human.h";
#include "homosapience.h";

Programmer :: HardWork()
{
   cout << "HardWork";
}
Programmer::Party()
{
    eat(sweat);
    drink(juice);
}
Programmer::Work() 
{
        int _health = getHealthLevel();
		setHealthLevel(--_health);
		setBadHealth(getMentalHealth() + getHealthLevel());
		if (getBadHealth() == 0)
		{
			cout << "Die";
		}
        if (getHungry()<=120)
        {
        eat(fruits);
        }
            
}
Programmer::Dance()
{
    int _health = getHealthLevel();
    int _mental = getMentalHealth();
    setHealtLevel(++_health);
    setMentalHealth(++_mental);
    eat(vegetable);
    drink(water);
    
}
Programmer::GoToGym()
{
    
    int _health = getHealthLevel();
    int _mental = getMentalHealth();
    setHealtLevel(++_health);
    setMentalHealth(++_mental);
    eat(vegetable);
    drink(water);
}

