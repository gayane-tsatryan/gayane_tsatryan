#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "employee.h"
enum ProgrammerType {
    FRONTEND DEVELOPER,
    BACKEND DEVELOPER,
    FULLSTACK DEVELOPER,
    DATABASE ENGINNER,
    DATA SCIENTIST,
    .NET DEVELOPER,
    PHP DEVELOPER,
    }
enum ProgrammerLevel {
    LEARNER,
    JUNIOR,
    MIDDLE,
    SENIOR
}
class Programmer: public employee
{
	private: 
          string _company = "";
		      string _compSkills = "";
        	unsigned int _salary = 0U;
          unsigned int _bonus = 0U;
          ProgrammerType  _programmerType = NULL;
          ProgrammerLevel _programerLevel = NULL;

    Company _company;
	public: 
		void HardWork();
		string getCompSkills() const;
		void setCompSkills(string compskills);
		unsigned long getSalary() const;
		void setSalary(unsigned long salary);
		virtual void Work() override;
		virtual void hobby() override;
		Programmer(const employee& employee, string compSkills, unsigned int salary, unsigned int bonus, ProgrammerType programmerType, ProgrammerLevel programmerLevel, string company);
    Programmer(const Programmer&);
    ~Programmer();
};
#endif
