#define _CRT_SECURE_NO_WARNINGS

/*****************************************************************************************************************/
/* Spring Quarter. De Anza College. CIS 22B                                                                      */
/*                                                                                                               */
/* Lab 4: This program demonstrates the use of 3 templates. The first one is the Maximum/Minimum function templa-*/
/* te; it calculates the maximum and minimum element between two values inserted by the user. The second is the  */
/* absolute value function template, it calculates the absolute value of an element inserted by the user. Fina-  */
/* lly, the third one is the total template function. It calculates the running total of a serie of elements     */
/* inserted by the user.                                                                                         */
/*                                                                                                               */
/* Name: Patricia Caceres                                                                                        */
/*****************************************************************************************************************/

#include<iostream>
#include<string>
#include"Total.h"
#include"AbsVal.h"
#include"MaxMin.h"
using namespace std;

void MAXMIN();
void ABSVAL();
void TOTAL();

int main()
{
	int choice;

	//Ask the user for a template to try
	do 
	{
		cout << string(81, '=') << endl << endl;
		cout << " Lab 4 : This program demonstrates the use of 3 templates. The first one is the\n\n";
		cout << " Maximum/Minimum function template; it calculates the maximum and minimum element\n\n";
		cout << " between two values inserted by the user.The second is theabsolute value function\n\n";
		cout << " template, it calculates the absoolute value of an element inserted by the user.\n\n"; 
		cout << " Finally, the third one is the total template function. It calculates the running\n\n";
		cout << " total of a serie of elements inserted by the user. \n\n";
		cout << string(81, '=') << endl << endl;
		cout << "  1)Minimum/Maximum Template\n\n";
		cout << "  2)Absolute Value Template\n\n";
		cout << "  3)Total Template\n\n";
		cout << "  4)Exit the program\n\n";

		cout << string(81, '=') << endl << endl;

		int cont = 0;
		do
		{
			if (cont > 0)
			{
				cout << "\n You did not insert a correct value for your choice,try again\n\n";
				cout << string(81, '-') << endl << endl;
			}
			cout << " Please enter the number of your choice: ";
			cin >> choice;
			cont++;
		} while ((choice > 4) || (choice < 1));

		//Redirect the program to the choice the user selected
		switch (choice)
		{
		case 1:
			MAXMIN(); //Maximum/Minimum template function
			break;
		case 2:
			ABSVAL(); //Absolute Value template function
			break;
		case 3:
			TOTAL(); //Total template function
			break;
		}
	} while (choice != 4);

	cout << endl << endl;
	system("pause");
}

void MAXMIN()
{
	system("CLS");
	//Explain the user what this function will do
	cout << string(80, '=')<<endl<<endl;
	cout << "\t\tM A X I M U M / M I N I M U M   T E M P L A T E";
	cout << "\n\n I will ask for two arguments of various data types, and then I will tell you\n\n which element is the biggest and the smallest\n\n";
	cout << string(80, '=')<<endl<<endl;

	//Ask the user for 2 elements of different data types and tell which one is the maximum and the minimum
	int num1, num2;
	cout << " Please insert two integers separated by a space:\n\n ";
	cin >> num1 >> num2;
	cout<<"\n\n The Maximum is: "<<max(num1, num2);
	cout << "\n\n The Minimum is: " << min(num1, num2);

	cout <<endl<<endl<<string(80, '-') << endl << endl;
	string strn1, strn2;
	cout << " Please insert two string separated by a space (Just one word for each string...\n\n I did not use getline :D ) :\n\n ";
	cin >> strn1 >> strn2;
	cout << "\n\n The Maximum is: " << max(strn1, strn2);
	cout << "\n\n The Minimum is: " << min(strn1, strn2);

	cout <<endl<<endl<< string(80, '-') << endl << endl;
	double dob1, dob2;
	cout << " Please insert two doubles separated by a space:\n\n ";
	cin >> dob1 >> dob2;
	cout << "\n\n The Maximum is: " << max(dob1, dob2);
	cout << "\n\n The Minimum is: " << min(dob1, dob2);
	cout << endl << endl << string(80, '-') << endl << endl;
	cout << "Redirecting to the Main Menu\n\n";
	system("pause");
	system("CLS");
}
void ABSVAL()
{
	system("CLS");
	cout << string(80, '=') << endl << endl;
	cout << "\t\t A B S O L U T E   V A L U E   T E M P L A T E";
	cout << "\n\n I will ask for one number of different data types and then I will give you its\n\n absolute value\n\n";
	cout << string(80, '=') << endl << endl;

	//Askthe user for an element of different data types and tell what is the absolute value of that element
	int num1;
	cout << " Please insert an integer:\n\n ";
	cin >> num1;
	cout << "\n\n The Absolute value of "<<num1<<" is : " << abs(num1);
	

	cout << endl << endl << string(80, '-') << endl << endl;
	double dob1;
	cout << " Please insert a double:\n\n ";
	cin >> dob1;
	cout << "\n\n The Absolute value of " << dob1 << " is : " << abs(dob1);
	cout << endl << endl << string(80, '-') << endl << endl;
	cout << "Redirecting to the Main Menu\n\n";
	system("pause");
	system("CLS");
}
void TOTAL() 
{
	system("CLS");
	cout << string(80, '=') << endl << endl;
	cout << "\t\t\tT O T A L   T E M P L A T E\n\n";
	cout << " This template will keep a running total of values that you will insert. I will\n\n first ask for the number of values and data type of the values you want me to";
	cout << "\n\n read and then I will ask you to enter each one of those values. At the end I\n\n will tell you what is the running total.";
	cout <<endl<<endl<< string(80, '=') << endl << endl;

	int num;
	int cont = 0;
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice,try again\n\n";
			cout << string(80, '-') << endl << endl;
		}
		cout << " How many elements you would like to insert? ";
		cin >> num;
		cont++;
	} while (num<0);
	cout <<endl<< string(80, '-') << endl << endl;
	cont = 0;
	int choice;
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice,try again\n\n";
			cout << string(80, '-') << endl << endl;
		}
		cout << " Select the data type of the elements you would like to insert:\n\n ";
		cout << "Enter '1' for string, '2' for integer, or '3 for doubles'\n\n ";
		cin >> choice;
		cont++;
	} while ((choice > 3) || (choice < 1));

	//Ask the user to insert the elements and redirect the program to the choice the user selected
	switch (choice)
	{
	case 1:
	{
			  string read[1024];
			  for (int x = 0; x < num; x++)
			  {
				  cout << "\n Enter element " << x + 1 << " : ";
				  cin >> read[x];
			  }
			  cout <<endl<< string(80, '-');
			  cout<<"\n\n The running total of this elements is: "<< total(read,num);
			  break;
	}
	case 2:
	{
			  int read[1024];
			  for (int x = 0; x < num; x++)
			  {
				  cout << "\n Enter element " << x + 1 << " : ";
				  cin >> read[x];
			  }
			  cout << endl<< string(80, '-');
			  cout << "\n\n The running total of this elements is: " << total(read, num);
			  break;

	}
	case 3:
	{
			  double read[1024];
			  for (int x = 0; x < num; x++)
			  {
				  cout << "\n Enter element " << x + 1 << " : ";
				  cin >> read[x];
			  }
			  cout << endl<< string(80, '-');
			  cout << "\n\n The running total of this elements is: " << total(read, num);
			  break;
	}
	}
	cout << endl << endl << string(80, '=') << endl << endl;
	cout << "Redirecting to the Main Menu\n\n";
	system("pause");
	system("CLS");
}