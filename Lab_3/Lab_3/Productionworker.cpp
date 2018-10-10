//Implementation file for the ProductionWorker class
#include"Productionworker.h"
#include <string>
#include <iostream>
using namespace std;

//Construction Overloads...
ProductionWorker::ProductionWorker(int shift, double hourlyRate, string name, int employeeNum, string hireDate) : Employee(name, employeeNum, hireDate) //Constructor #3
{
	this->shift = shift;
	this->hourlyPayRate = hourlyRate;
}

//The constructor #4 assign the value to name 
ProductionWorker::ProductionWorker(string nm)
{
	name = nm;
	//Initialize employeeNum and  hireDate
	employeeNum = 0;
	hireDate = "";
	shift = 0;
	hourlyPayRate = 0.0;
}

//The constructor #5 accepts arguments for name, employeeNum, hireDate
ProductionWorker::ProductionWorker(string nm, int num, string date)
{
	name = nm;
	employeeNum = num;
	hireDate = date;
	shift = 0;
	hourlyPayRate = 0.0;
}

//setShift assigns an integer value (1 or 2) to the shift member
void ProductionWorker::setShift(int shft)
{
	shift = shft;                                                                     
}

//setHourlyPayRate assigns a value to the hourlyPayRate member
void ProductionWorker:: setHourlyPayRate(double prt)
{
	hourlyPayRate=prt;
}

//getShift returns the value in the shift member
int ProductionWorker::getShift() const
{
	return shift;
}

//getHourlyPayRate returns the value in the hourlyPayRate member
double ProductionWorker::getHourlyPayRate() const
{
	return hourlyPayRate;
}