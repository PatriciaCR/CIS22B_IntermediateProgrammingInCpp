//Specification file for the Team Leader Class
#ifndef TEAMLEADER_H
#define TEAMLEADER_H	
#include <string>
#include "ProductionWorker.h"
using namespace std;

//Shift Supervisor class declaration 
class TeamLeader : public ProductionWorker
{
private:
	double monthlyBonusAmount;
	double nTrainingHours;
	double nTHoursLeader;
public:
	// Exception class for incomplete training
	class IncompleteTraining
	{ };
	//Mutators
	TeamLeader() { monthlyBonusAmount = 0.0; nTrainingHours = 0.0;nTHoursLeader=0.0; shift = 0; hourlyPayRate = 0.0; name = ""; employeeNum = 0; hireDate = ""; } //Default constructor
	TeamLeader (double, double, double, int shift, double hourlyRate, string name, int employeeNum, string hireDate); //Constructor
	void setMonthlyBonusAmount(double);
	void setNTrainingHours(double);
	void setNTHoursLeader(double);
	//Accesors
	double getMonthlyBonusAmount() const;
	double getNTrainingHours() const;
	double getNTHoursLeader() const;
};

#endif
