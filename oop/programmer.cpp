#include "human.h";
#include "homosapience.h";
#include "employee.h"
Programmer::Programmer(const employee &employee, string compSkills, unsigned int salary): employee(employee)
{
	_compSkills = compSkills;
	_salary = salary;
}

string programmer::getCompSkills() const
{
	return _compSkills;
}
void programmer::setCompSkills(string compskills)
{
	_compSkills = compskills;
}
unsigned long programmer::getSalary() const
{
	return _salary;
}
void programmer::setSalary(unsigned long salary)
{
	_salary = salary;
}
Programmer::HardWork()
{
	int _getSalary = getSalary();
	setSalary(++_getSalary);
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
	if (getHungry() <= 120)
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
Programmer::Hobby()
{
	cout << "Play guitar!";

}
