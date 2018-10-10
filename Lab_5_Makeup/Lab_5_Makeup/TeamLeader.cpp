//Implementation file for the Team Leader class
#include "TeamLeader.h"
#include <string>
#include <iostream>
using namespace std;


//The constructor accepts arguments for montlyBonusAmmount, nTrainingHours, nTHoursLeader
TeamLeader::TeamLeader(double mnthlbonam, double trahrs, double trahrslea, int shift, double hourlyRate, string nm, int num, string date) : ProductionWorker(shift, hourlyPayRate, name, employeeNum, hireDate)
{
	monthlyBonusAmount= mnthlbonam;
	nTrainingHours=trahrs;
	nTHoursLeader=trahrslea;
	this->shift = shift;
	hourlyPayRate = hourlyRate;
	name = nm;
	employeeNum = num;
	hireDate = date;

}

//setMonthlyBonusAmount assigns a value to the monthlyBonusAmount member
void TeamLeader::setMonthlyBonusAmount(double mnthlbonam)
{
	monthlyBonusAmount = mnthlbonam;
}

//setNTrainingHours assigns a value to the nTrainingHours member 
void TeamLeader::setNTrainingHours(double trahrs)
{
	if (trahrs >= 8)
		nTrainingHours = trahrs;
	else
		throw IncompleteTraining();
}

//setNTHoursLeader assigns a value to the nTHoursLeader member
void TeamLeader::setNTHoursLeader(double trahrslea)
{
	nTHoursLeader = trahrslea;
}

//getMonthlyBonusAmount returns the value in the member variable monthlyBonusAmount
double TeamLeader::getMonthlyBonusAmount() const
{
	return monthlyBonusAmount;
}

//getNTrainingHours returns the value in the member variable nTrainingHours
double TeamLeader::getNTrainingHours() const
{
	return nTrainingHours;
}

//getNTHoursLeader returns the value in the member variable nTHoursLeader
double TeamLeader::getNTHoursLeader() const
{
	return nTHoursLeader;
}