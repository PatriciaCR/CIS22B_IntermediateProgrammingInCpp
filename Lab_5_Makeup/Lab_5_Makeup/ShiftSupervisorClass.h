//Specification file for the Shift Supervisor Class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H	
#include <string>

using namespace std;

//Shift Supervisor class declaration 
class ShiftSupervisor
{
private:
	double annualSalary;
	double annualProductionBonus;
public:
	//Mutators
	Employee(string, int, int); //Constructor
	void setName(string);
	void setEmployeeNum(int);
	void setHireDate(int);
	//Accesors
	string getName() const;
	int getEmployeeNum() const;
	int getHireDate() const;
};

#endif
