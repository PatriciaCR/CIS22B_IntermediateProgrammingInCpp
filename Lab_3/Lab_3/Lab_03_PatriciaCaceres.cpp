/*****************************************************************************************/
/*  DeAnza College. Spring quarter, 2015                                                 */
/*  Lab 3:                                                                               */
/*                                                                                       */
/*  Name: Patricia Caceres                                                               */
/*****************************************************************************************/


/*****************************************************************************************/
/*
    P S E U D O C O D E (If I write anything else it would be extremely repetitive :)  )

1) Create 5 objects and call their default constructors. 3 of type ProductionWorker, 1 
   ShiftSupervisor and 1 TeamLeader to showconstruction overriding and static binding. 
2) Ask the user for information about the employees
3) Use the information inserted by the user to set the values of the different member 
   variables of the objects
4) Return and display the information of the objects.
*/
/*****************************************************************************************/


#include<iostream>
#include<string>
#include "Employee.h" //EMPLOYEE CLASS
#include"Productionworker.h" //PRODUCTIONWORKER CLASS
#include"TeamLeader.h" //TEAM LEADER CLASS	
#include "ShiftSupervisor.h" //SHIFTSUPERVISOR CLASS	
using namespace std;

int main()
{
	string NAME;
	int EMPLOYEENUM;
	string HIREDATE;
	cout << string(66, '=')<<endl<<endl;
	cout << "This program will ask you a lot of unnecesary stuff about some\n";
	cout << "employees and then it will display them.It uses classes and also\n";
	cout << "tries to use construction overload, static binding, and dinamic\n";
	cout << "binding :)\n\n";
	cout << string(66, '=')<<endl<<endl;

	ProductionWorker person; //Create a ProductionWorker object and call the default constructor
	
	//Create an ProductionWorker object and call constructor #4
	ProductionWorker person2("Sarah Thomas");

	//Create an ProductionWorker object and call constructor #5
	ProductionWorker person3("Christina Mason", 785422, "09/07/2012");
	
	ShiftSupervisor person5; //Create a ShiftSupervisor object and call the default constructor

	//Dinamic binding
	Employee* person6 = new ShiftSupervisor;

	TeamLeader person4; //Create a TeamLeader object and call the default constructor


	//Ask the user for the name,employeeNumber and hireDate
	cout << "Please insert the employee name:\n";
	getline(cin, NAME);

	cout << "\n\nPlease insert the number of employee of " << NAME << endl;
	cin >> EMPLOYEENUM;

	cout << "\n\nPlease insert the hire date of the employee ";
	cout << "in this format:\nMM/DD/YYYY. Example: for January 1, 2014 you will write 01/01/2014\n";
	cin >> HIREDATE;

	person.setName(NAME); //Set the name for the ProductionWorker object
	person.setEmployeeNum(EMPLOYEENUM); //Set the employee number for the ProductionWorker object
	person.setHireDate(HIREDATE); //Set the hire date for the ProductionWorker object


	//Ask the user for the shift that the employee works
	int SHIFT;
	double HRLPAYRT;
	int n = 0;
	do
	{
		if (n > 0)
			cout << "You did not insert a correct value for shift.\nPlease try again:\n\n";
		cout << "\nEnter shifth that the employee works: Insert '1' for the day shift\nand 2 for the night shift\n";
		cin >> SHIFT;
		n++;
	} while (SHIFT != 1 && SHIFT != 2); //Validate the shift
	cout << "\nPlease insert the hourly pay rate of the employee\n";
	cin >> HRLPAYRT;
	cout << endl;

	person.setShift(SHIFT);// Set the shift for the ProductionWorker object
	person.setHourlyPayRate(HRLPAYRT); //Set the hourlyPayRate for the ProductionWorker object


	double ANSAL, ANPODBO; //Declares annual salary and annual production bonus

	//Ask the usr for the annual salary and the annuall production bonus
	cout << "\nPlease insert the annual salary of the shift supervisor\n";
	cin >> ANSAL;
	cout << "\nPlease insert the annual production bonus that the shift supervisor\nhas earned\n";
	cin >> ANPODBO;
	person5.setdata(NAME, EMPLOYEENUM, HIREDATE); //Static binding 
	person5.setannualSalary(ANSAL); //Set annualSalary for the shiftSupervisor object
	person5.setannualProductionBonus(ANPODBO);//Set annualProductionBonus for the shiftSupervisor object

	
	
	double MTHBOAM, TRH, NTRH;
	cout << "\nPlease insert the monthly bonus amount for the team leader\n";
	cin >> MTHBOAM;
	cout << "\nPlease insert the required number of training hours that the\nteam leaderhas to attend\n";
	cin >> TRH;
	cout << "\nPlease insert the number of training hours the leader attended\n";
	cin >> NTRH;
	cout << endl;
	person4.setName(NAME); //Set the name for the TeamLeader object
	person4.setEmployeeNum(EMPLOYEENUM); //Set the employee number for the TeamLeader object
	person4.setHireDate(HIREDATE); //Set the hire date for the TeamLeader object
	person4.setShift(SHIFT); //Set the shift for the TeamLeader object
	person4.setHourlyPayRate(HRLPAYRT);//Set the hourlyPayRate for the TeamLeader object
	person4.setMonthlyBonusAmount(MTHBOAM); //Set the monthlyBonusAmount for the TeamLeader object
	person4.setNTHoursLeader(TRH); //Set the nTrainingHours required for the TeamLeader object
	person4.setNTrainingHours(NTRH); //Set the NtrainingHours attended for the TeamLeader object


	//Production worker objects
	cout << string(66, '=');
	cout << "\nProduction worker objects... \n\n";

	//Display the data for person 
	cout << "\nName of the employee: " << person.getName();
	cout << "\nNumber of employee: " << person.getEmployeeNum();
	cout << "\nHire date: " << person.getHireDate();
	cout << "\nShift: " << person.getShift();
	cout << "\nHourly pay rate: "<<person.getHourlyPayRate()<<endl;
	cout << string(66, '-');

	//Display the data for person 2
	cout << "\n\nName of the employee: " << person2.getName();
	cout << "\nNumber of employee: " << person2.getEmployeeNum();
	cout << "\nHire date: " << person2.getHireDate();
	cout << "\nShift: " << person2.getShift();
	cout << "\nHourly pay rate: " << person2.getHourlyPayRate() << endl;
	cout << string(66, '-');

	//Display the data for person 3
	cout << "\n\nName of the employee: " << person3.getName();
	cout << "\nNumber of employee: " << person3.getEmployeeNum();
	cout << "\nHire date: " << person3.getHireDate();
	cout << "\nShift: " << person3.getShift();
	cout << "\nHourly pay rate: " << person3.getHourlyPayRate() << endl<<endl<<endl;
	
	
	//Shift supervisor objects
	cout << string(66, '=');
	cout << "\nShift Supervisor object\n";
	//Static binding
	cout << "\n\nUsing static binding\n";
	cout << "\n\nName of the employee: " << person5.getName();
	cout << "\nNumber of employee: " << person5.getEmployeeNum();
	cout << "\nHire date: " << person5.getHireDate();
	cout << "\nAnnual Salary: " << person5.getAnnualSalary();
	cout << "\nAnnual Production Bonus: " << person5.getAnnualProductionBonus() << endl<<endl<<endl;
	cout << string(66, '-')<<endl;

	//"Dynamic binding"
	cout << "Using dynamic binding\n";
	cout << "\n\nName of the employee: " << person6->setDATA();


	//Team leader objects 
	cout <<endl <<string(66, '=');
	cout << "\nTeam Leader object\n\n";
	cout << "\nName of the employee: " << person4.getName();
	cout << "\nNumber of employee: " << person4.getEmployeeNum();
	cout << "\nHire date: " << person4.getHireDate();
	cout << "\nShift: " << person4.getShift();
	cout << "\nHourly pay rate: " << person4.getHourlyPayRate();
	cout << "\nMonthly Bonus Amount: " << person4.getMonthlyBonusAmount();
	cout << "\nRequired training hours: "<<person4.getNTHoursLeader();
	cout << "\nNumber of training hours attended: " << person4.getNTHoursLeader();

	cout << endl << endl;
	system("pause");
	return 0;
}


