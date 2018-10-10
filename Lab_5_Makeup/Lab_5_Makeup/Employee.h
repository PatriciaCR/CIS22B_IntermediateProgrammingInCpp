//Specification file for the Employee class 
#ifndef EMPLOYEE_H
#define EMPLOYEE_H	
#include <string>

using namespace std;

//Employee class declaration 
class Employee
{
protected:
	string name;
	int employeeNum;
	string hireDate;
public:
	//Mutators
	Employee(){ name = ""; employeeNum = 0; hireDate = ""; } //Constructor #1. Initialize name, employeeNum, hireDate. 
	Employee(string, int, string); // Another constructor

	// Exception class for invalid employee number
	class InvalidEmployeeNumber
	{ };
	void setName(string);
	void setEmployeeNum(int);
	void setHireDate(string);
	void setdata(string, int, string); //Static Binding
	virtual string setDATA() const; //Dynamic binding

	//Accesors
	string getName() const;
	int getEmployeeNum() const;
	string getHireDate() const;
};

#endif
