#include "human.h";
#include "homosapience.h"

class Programmer: public Homosapience
{
	private: 
		string _compSkills = "";
        	unsigned long _salary = 0;
	public: 
		void HardWork();
		string getCompSkills() const;
		void setCompSkills(string compskills);
		unsigned long getSalary() const;
		void setSalary(unsigned long salary);
		virtual void Work() override;
		virtual void hobby() override;
		Programmer(const HomoSapience& homoSapience, string compSkills, unsigned int salary);
                Programmer(const Programmer&);
                ~Programmer();
};
