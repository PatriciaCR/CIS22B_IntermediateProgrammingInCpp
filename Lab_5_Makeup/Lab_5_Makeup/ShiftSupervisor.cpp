//Implementation file for the Shift Supervisor class
#include "ShiftSupervisor.h"
#include <string>
#include <iostream>
using namespace std;


//"Dynamic binding"
string ShiftSupervisor::setDATA() const
{
	return "Gabriel";
}
//Static binding
void ShiftSupervisor::setdata(string nm, int num, string hire)
{
	nm = "Patricia Caceres";
	num = 20225420;
	hire = "09/06/2014";
	Employee::setdata(nm, num, hire);
}

//The constructor accepts arguments for annualSalary, annualProductionBonus
ShiftSupervisor::ShiftSupervisor(double annsal, double annprdbo, string name, int employeeNum, string hireDate) :Employee(name, employeeNum, hireDate)
{
	annualSalary = annsal;
	annualProductionBonus = annprdbo;
}

//setAnnualSalary assigns a value to the annualSalary member
void ShiftSupervisor::setannualSalary(double annsal)
{
	annualSalary =annsal;
}

//setAnnualProductionBonus assigns a value to the annuallProductionBonus member 
void ShiftSupervisor::setannualProductionBonus(double annprodbo)
{
	annualProductionBonus = annprodbo;
}

//getAnnualSalary returns the value in the member variable annualSalary
double ShiftSupervisor::getAnnualSalary() const
{
	return annualSalary;
}

//getAnnualProductionBonus returns the value in the member variable annualProductionBonus
double ShiftSupervisor::getAnnualProductionBonus() const
{
	return annualProductionBonus;
}