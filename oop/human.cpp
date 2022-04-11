#include "human.h"
#include <iostream>
using namespace std;

Human::Think()
{
    cout << "Think";
}
Human::Walk()
{
    cout << "Wakl";
}
Human::Breath()
{
    cout << "Breath";
}
Human::Eat(Food _food)
{
    cout << "I eat " << _food;
}
Human::Drink(Drink _drink)
{
    cout << "I drink " << _drink;
}
Human::Digestion()
{
    cout << "Digestion";
}

Human::Human(string _birthDay, int _eyeColor, int _hairColor, Gender _gender, Human _father, Human _mother)
{
    _birthDay = _birthDay;
    _eyeColor = _eyeColor;
    _hairColor = _hairColor;
    _gender = _gender;
    _father = _father;
    _mother = _mother;
}
