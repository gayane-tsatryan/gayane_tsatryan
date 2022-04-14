#include "human.h";
#include "homosapience.h"

class Programmer: public Homosapience
{
	private: string _compSkills;

	public: void HardWork();
	string getCompSkills() const;
	void setCompSkills(string compskills);
};
