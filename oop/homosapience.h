
#include "human.h"

enum Nationality
{
	arm, rus, eng
};
enum Religion
{
	Christianity,
	caballa,
	islam
};
class HomoSapience: public Human
{
	private: string _address;
	string _name;
	string _surname;
	string _fatherName;
	string _motherName;
	Nationality _nationality;
	Religion _religion;

	public: string getAddress() const;
	void setAddress(string address);

	string getName() const;
	void setName(string name);

	string getSurname() const;
	void setSurname(string surname);

	string getFatherName() const;
	void setFatherName(string fatherName);

	string getMotherName() const;
	void setMotherName(string motherName);

	Nationality getNationality() const;
	void setNationality(Nationality nationality);

	Religion getReligion() const;
	void setReligion(Religion religion);

	void Party();
	virtual void Work();
	virtual void hobby();
	void Dance();
	void GoToGym();
	public:
	HomoSapience(string address, string name, string surname, string fatherName, string mothername, Religion religion, Nationality nationality);
	HomoSapience(string address, string name, string surname, string fatherName, Religion religion, Nationality nationality);
	HomoSapience(string address, string name, string surname, string mothername, Religion religion, Nationality nationality);
	HomoSapience(string address, string name, string surname, Religion religion, Nationality nationality);
        HomoSapience();
	~HomoSapience();
};
