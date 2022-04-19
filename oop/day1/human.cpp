#include "human.h"
#include <iostream>
using namespace std;
Human::Human(string birthDay, int eyeColor, int hairColor, Gender gender, Human father, Human mother, int healthLevel, int mentalHealth)
{
	_birthDay = birthDay;
	_eyeColor = eyeColor;
	_hairColor = hairColor;
	_gender = gender;
	_father = father;
	_mother = mother;
	_healthLevel = healthLevel;
	_mentalHealth = mentalHealth;
	_badHealth = 0;
}
Human::Human(string birthDay, int eyeColor, int hairColor, Gender gender, Human father, int healthLevel, int mentalHealth)
{
	_birthDay = birthDay;
	_eyeColor = eyeColor;
	_hairColor = hairColor;
	_gender = gender;
	_father = father;
	_healthLevel = healthLevel;
	_mentalHealth = mentalHealth;
	_badHealth = 0;
}

Human::Human(string birthDay, int eyeColor, int hairColor, Gender gender, int healthLevel, int mentalHealth)
{
	_birthDay = birthDay;
	_eyeColor = eyeColor;
	_hairColor = hairColor;
	_gender = gender;
	_healthLevel = healthLevel;
	_mentalHealth = mentalHealth;
	_badHealth = 0;
}

Date *Human::getBirthDay() const
{
	return _birthDay;
}
void Human::setBirthDate(Date *birthDay)
{
	_birthDay = birthDay;
}

void Human::setEyeColor(EyeColor eyeColor)
{
	if (eyeColor == green || eyeColor == blue || eyeColor == black || eyeColor == gray || eyeColor == brown)
	{
		_eyeColor = eyeColor;
	}
}
EyeColor Human::getEyeColor() const
{
	return _eyeColor;
}

void Human::setHairColor(HairColor hairColor)
{
	if (hairColor == black || hairColor == brown)
	{
		_hairColor = hairColor;
	}
}

HairColor Human::getHairColor() const
{
	return _hairColor;
}
Gender Human::getGender() const
{
	return _gender;
}

void setGender(Gender gender)
{
	if (gender == male || gender == female)
	{
		_gender = gender;
	}
}

Human Human::getFather() const
{
	return _father;
}

Human Human::getMother() const
{
	return _mother;
}
int getHealthLevel() const
{
	return _healthLevel;
}
void setHealthLevel(int healthLevel)
{
	if (healthLevel >= 0 && healthLevel <= 100)
	{
		_healthLevel = healthLevel;
	}
}

int getMentalHealth() const
{
	return _mentalHealth;
}
void setMentalHealth(int mentalHealth)
{
	if (mentalHealth >= 0 && mentalHealth <= 100)
	{
		_mentalHealth = mentalHealth;
	}
}
int getBadHealth() const
{
	return _badHealth;
}
void setBadHealth(int badHealth)
{
	if (badHealth >= 0 && badHealth < 50)
	{
		_badHealth = badHealth;
	}
}

int getHungry() const
{
	return _hungry;
}
void setHungry(int hungry)
{
	if (hungry >= 0 && hungry < 200)
	{
		_hungry = hungry;
	}
}
int getThirsty() const
{
	return _thirsty;
}

void setThirsty(int thirsty)
{
	if (thirsty >= 0 && thirsty < 200)
	{
		_thirsty = thirsty;
	}
}

Human::Eat(Food _food)
{
	if (food == vegetable || food == fruits)
	{
		setMentalHealth(_mentalHealth++);
		setHealthLevel(_healthLevel++);
	}
	else
	{
		setMentalHealth(_mentalHealth--);
		setHealthLevel(_healthLevel--);
		setBadHealth(getMentalHealth() + getHealthLevel());
		if (getBadHealth() == 0)
		{
			cout << "Die";
		}
	}
}

Human::Drink(Drink drink)
{
	if (drink == milk || drink == water || drink == juice)
	{
		setMentalHealth(_mentalHealth++);
		setHealthLevel(_healthLevel++);
	}
	else
	{
		setMentalHealth(_mentalHealth--);
		setHealthLevel(_healthLevel--);
		setBadHealth(getMentalHealth() + getHealthLevel());
		if (getBadHealth() == 0)
		{
			cout << "Die";
		}
	}
}
Human::Think()
{
	int _tempHungry = getHungry();
	setHungry(--_temp);
	int _tempThirsty = getThirsty();
	setThirsty(--_tempThirsty);
}
Human::Walk()
{
	int _tempHungry = getHungry();
	setHungry(--_temp);
	if (_temp < 10)
	{
		eat();
	}
	int _tempThirsty = getThirsty();
	setThirsty(--_tempThirsty);
}
Human::Breath()
{
	Human human1;
}

Human::Digest()
{
	cout << "Digestion";
}
