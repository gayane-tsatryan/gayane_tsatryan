#include "homosapience.h";

HomoSapience::HomoSapience(const Human& human, string address, string name, string surname, string fatherName, string mothername, Religion religion, Nationality nationality) : Human(human)
{
	_address = address;
	_name = name;
	_surname = surame;
	_fatherName = fatherName;
	_mothername = motherName;
	_religion = religion;
	_nationality = nationality;

}
HomoSapience::HomoSapience(const Human& human, string address, string name, string surname, string mothername, Religion religion, Nationality nationality) : Human(human)
{
	_address = address;
	_name = name;
	_surname = surame;
	_mothername = motherName;
	_religion = religion;
	_nationality = nationality;

}
HomoSapience::HomoSapience(const Human& human, string address, string name, string surname, Religion religion, Nationality nationality) : Human(human)
{
	_address = address;
	_name = name;
	_surname = surame;
	_religion = religion;
	_nationality = nationality;

}

string HomoSapience::getAddress() const
{
	return _address;
}
void setAddress(string address)
{
	_address = address;
}

string HomoSapience::getName() const
{
	return _name;
}
void HomoSapience::setName(string name)
{
	_name = name;
}

string HomoSapience::getSurname() const
{
	return _surname;
}
void HomoSapience::setSurname(string surname)
{
	_surname = surname;
}

string HomoSapience::getFatherName() const
{
	return _fatherName;
}
void HomoSapience::setFatherName(string fatherName)
{
	_fatherName = fatherName;
}

string HomoSapience::getMotherName() const
{
	return _motherName;
}
void HomoSapience::setMotherName(string motherName)
{
	_motherName = motherName;
}
Nationality HomoSapience::getNationality() const
{
	return _nationality;
}
void HomoSapience::setNationality(Nationality nationality)
{
	if (nationality == arm || nationality == rus || nationality == eng)
	{
		_nationality = nationality;
	}
}

Religion HomoSapience::getReligion() const
{
	return _religion;
}
void HomoSapience::setReligion(Religion religion)
{
	if (religion == Christianity || religion == caballa || religion == islam)
	{
		_religion = religion;
	}
}
