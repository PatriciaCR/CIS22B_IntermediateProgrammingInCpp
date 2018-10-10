//Specification file for the Shift Supervisor Class
#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H	
#include <string>
#include "Employee.h"
using namespace std;

//Shift Supervisor class declaration 
class ShiftSupervisor :public Employee
{
private:
	double annualSalary;
	double annualProductionBonus;
public:
	//Mutators
	ShiftSupervisor(){ annualSalary = 0.0; annualProductionBonus = 0.0; name = ""; employeeNum = 0; hireDate = ""; }; //Default constructor
	ShiftSupervisor(double, double, string name, int employeeNum, string hireDate); //Constructor
	void setannualSalary(double);
	void setannualProductionBonus(double);
	void setdata(string, int, string); //Static binding
	string setDATA() const override; //Dynamic binding
	//Accesors
	double getAnnualSalary() const;
	double getAnnualProductionBonus() const;
};

#endif
