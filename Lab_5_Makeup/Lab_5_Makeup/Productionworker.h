//Specification file for the Production worker class 
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H	

#include "Employee.h"

class ProductionWorker : public Employee
{
protected:
	int shift;
	double hourlyPayRate;
public:
	// Exception class for invalid shift
	class InvalidShift
	{ };
	// Exception class for invalid pay rate
	class InvalidPayRate
	{ };
	ProductionWorker() { shift = 0; hourlyPayRate = 0.0; name = ""; employeeNum = 0; hireDate = ""; } //Constructor #2. Initialize shift, hourlyPayRate, name, employeeNum, hireDate. 
	ProductionWorker(int, double, string name, int employeeNum, string hireDate); //Constructor #3.
	ProductionWorker(string); //Constructor #4
	ProductionWorker(string, int, string); //Constructor #5
	//Mutators
	void setShift(int);
	void setHourlyPayRate(double); 
	//Accesors
	int getShift() const;
	double getHourlyPayRate() const;
};

#endif