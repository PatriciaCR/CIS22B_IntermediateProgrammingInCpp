//Implementation file for the employee class
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

//"Dynamic binding"
string Employee::setDATA() const
{
	return "Laura";
}
//Constructor
Employee::Employee(string nm, int num, string date)
{
	name = nm;
	employeeNum = num;
	hireDate = date;
}

//setdata assigns a value to name, employeeNum and hireDate
void Employee::setdata(string nm, int num, string date)
{
	name = nm;
	employeeNum = num;
	hireDate = date;
}
//setName assigns a value to the name member
void Employee::setName(string nm)
{
	name = nm;
}

//setEmployeeNum assigns a value to the employeeNum member 
void Employee::setEmployeeNum(int num)
{
	employeeNum = num;
}

//setHireDate assigns a value to the hireDate member
void Employee::setHireDate(string date)
{
	hireDate = date;
}

//getName returns the value in the member variable name
string Employee::getName() const
{
	return name;
}

//getEmployeeNum returns the value in the member variable employeeNum
int Employee::getEmployeeNum() const
{
	return employeeNum;
}

//getHireDate returns the value in the member variable hireDate
string Employee::getHireDate() const
{
	return hireDate;
}