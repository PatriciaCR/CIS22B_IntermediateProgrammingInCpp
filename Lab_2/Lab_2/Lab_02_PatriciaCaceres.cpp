/****************************************************************************************************************/
/* CIS 22B. Spring Quarter 2015.                                                                                */
/*                                                                                                              */
/* Lab 2: This program will imitate some of the functions of C-string. It will first show the user a menu and   */
/* ask her/him which of the functions would he/she like to test, then it will call the function that the user   */
/* selected and it will print the result. After that the user will return to the menu in case he/she would      */
/* like to test another function.                                                                               */
/*                                                                                                              */
/* Name: Patricia Caceres.                                                                                      */
/****************************************************************************************************************/

#include <stdlib.h> //Clear Output.
#include<string>
#include<iostream>
using namespace std;


//Function prototypes
int stringLength(char* str);												//String Length Function
char* stringNCopy(char* destination, char* source, int num);				//String Copy Function
char* stringAdd(char* destination, char* source);							//Function that concatenate strings
int stringCompare(char* str1, char* str2);									//Function that compare two strings

int main()

{
	//INSTRUCTIONS FOR THE USER	
	cout << string(71, '=') << endl << endl;
	cout << "\t\t\tI N S T R U C T I O N S\n\n";
	cout << "Hi, This program uses original versions (written by the programmer) of\n";
	cout << "some functions available for C-string. I will show you a menu and ask\n";
	cout << "you which of the functions you would like to test, there are 4 func-\n";
	cout << "tions for you to choose from. The first one is stringLength, which\n";
	cout << "calculates the length of a string; the second one is stringNCopy,\n";
	cout << "which copy characters from a string; the third one is stringAdd which\n";
	cout << "concatenate strings; and the last one is stringCompare, which comp\n";
	cout << "ares two strings.In case you decide not to test any function, you can\n";
	cout << "choose option 5 that will EXIT THE PROGRAM. After you insert your deci-\n";
	cout << "sion, I will take you to the function you wanted and I will print the\n";
	cout << "results on the screen. Finally, I will take you back to the menu again\n";
	cout << "in case you would like to test another function\n";

	string decision = "Yes";

	while (decision == "Yes") //While the choice of the user is yes, display the menu of functions
	{

		int choice;
		//MENU
		cout << string(71, '=') << endl << endl;
		cout << "\t\tWhich function you would like to test?\n\n";
		cout << " 1) stringLength\n";
		cout << " 2) stringNCopy\n";
		cout << " 3) stringAdd\n";
		cout << " 4) stringCompare\n";
		cout << " 5) EXIT THE PROGRAM\n\n";
		cout << string(71, '-') << endl;

		int cont = 0;

		do
		{
			if (cont > 0)
			{
				cout << "\n\nYou did not insert a correct choice, Please try again\n\n";
				cout << string(71, '-') << endl;
			}
			cout << "Enter the number of the function of your choice and press <Enter>:\n\n";
			cin >> choice;
			cont++;

		} while ((choice >= 6) || (choice <= 0));

		//Declares a character array of 200 elements and a pointer to a char which points to the array.
		char* str;
		char words[200];
		str = words;

		//Declares a character array of 200 elements and a pointer to a char which points to the array.
		char* cpy;
		char cpystr[200];
		cpy = cpystr;

		
		switch (choice)
		{

		case 1: //stringLength
			system("CLS");
			int size;
			cout << string(71, '=') << endl << endl;
			cout << "\t\tS T R I N G L E N G T H F U N C T I O N \n\n";
			cout << string(71, '=') << endl << endl;
			cout << "Please insert a string:\n\n";
			cin.clear();
			cin.ignore();
			cin.getline(str, 200, '\n');
			size = stringLength(str); //Call function that will returns the length of a string.
			cout << endl << "The size of the string is: " << size << endl << endl;
			break;

		case 2: //stringNCopy
			system("CLS");
			int num;
			cout << string(71, '=') << endl << endl;
			cout << "\t\tS T R I N G N C O P Y F U N C T I O N \n\n";
			cout << string(71, '=') << endl << endl;
			cout << "Please write the string you want me to copy:\n\n";
			cin.clear();
			cin.ignore();
			cin.getline(str, 200, '\n');
			cout << "\n\nNow insert the number of elements that you want me to copy from this\nstring:\n\n";
			cin >> num;
			cpy = stringNCopy(cpy, str, num); //Call the function that will copy characters from string.
			cout << "\nThis is the copied string: " << cpy << endl;
			break;

		case 3: //stringAdd
			system("CLS");
			cout << string(71, '=') << endl << endl;
			cout << "\t\tS T R I N G A D D F U N C T I O N \n\n";
			cout << string(71, '=') << endl << endl;
			cout << "Please insert the first string:\n\n";
			cin.clear();
			cin.ignore();
			cin.getline(cpy, 200, '\n');
			cout << "\n\nNow insert the string you want me to append at the end of the first\nstring:\n\n";
			cin.clear();
			cin.getline(str, 200, '\n');
			cpy = stringAdd(cpy, str);//Call the function that concatenate strings.
			cout << "\nThe concatenated resulting string is: " << cpy << endl;
			break;

		case 4: //stringCompare
			system("CLS");
			int comp;
			cout << string(71, '=') << endl << endl;
			cout << "\t\tS T R I N G N C O M P A R E F U N C T I O N \n\n";
			cout << string(71, '=') << endl << endl;
			cout << "Please insert the first string to be compared:\n\n";
			cin.clear();
			cin.ignore();
			cin.getline(cpy, 200, '\n');
			cout << "\n\nNow insert the second string to be compared:\n\n";
			cin.clear();
			cin.getline(str, 200, '\n');
			comp = stringCompare(cpy, str); // Call the function that compare two strings. 
			cout << endl << endl;
			if (comp > 0)
				cout << cpy << " is greater than " << str<<endl<<endl;
			else if (comp < 0)
				cout << str << "is greater than " << cpy<<endl<<endl;
			else
				cout << "The two strings are the same\n\n";
			break;

		case 5: //Exit the program
			cout << "\nEnd of Program.\n\n";
			cout << endl << endl;
			system("pause");
			return(0);
		}
		

		cont = 0;
		do
		{
			if (cont > 0)
				cout << "\n\nYou did not insert a correct choice, Please try again\n\n";
			cout << string(71, '-') << endl;
			cout << "Would you like me to display the menu again to test another function?\n";
			cout << "Insert 'Yes' or 'No'\n\n";
			cin >> decision;
			cont++;
		} while ((decision != "Yes") && (decision != "No"));
		
		if (decision == "Yes")
			system("CLS");

	}

	cout << endl << endl;
	system("pause");
	return(0);

}

//STRINGLENGTH FUNCTION
int stringLength(char* str)
{
	char* pc = str;
	int count = 0;
	while (*pc != '\0') //while contents of pt1 not equal to null: increase counter and the pointer
	{
		count++;
		pc++;
	}
	return count;//Return the counter(Number of characters of the string)
}


//STRINGNCOPY FUNCTION
char* stringNCopy(char* destination, char* source, int num)
{
	char* hc = source; //address of first character of source
	int i = 0;
	bool zeros = false;

	//While the counter is less than the number of elements to copy from the string and the content of hc is not equal to null:
	for (i = 0; (i < num) && (*(hc + i) != '\0'); i++) 
	{
		*(destination + i) = *(hc + i); //Copy one element from the source to the destination.
		if (*(hc + i + 1) == '\0' && i < num - 1) //If the value of the next element is equal to null and the counter is less than the number of elements to copy from the string
		{
			for (int x = i + 1; x < num - 1; x++) //destination will be padded with zeros until a total of num characters have been written to it.
				*(destination + x) = '0';
			destination[num - 1] = '\0'; //last element set to null
			zeros = true; 
			break;
		}
	}

	if (!zeros) //last element set to null
		destination[i] = '\0';

	return destination; //return destination (copy of the string)
}

//STRINGADD FUNCTION 
char* stringAdd(char* destination, char* source)

{
	int i = 0, j = 0;
	while (*(destination + i) != '\0') //Find the end of the string
		i++;

	//Copy source
	while (*(source + j) != '\0')  
	{
		*(destination + i) = *(source + j); 
		j++;
		i++;
	}

	*(destination + i) = '\0'; //Null character added at the end of the string
	return destination; //Return destination (Concatenatenation of strings)
}


//STRINGCOMPARE FUNCTION
int stringCompare(char* str1, char* str2)

{
	char* pt1 = str1; //address of first character of str1
	char* pt2 = str2; //address of first character of str2

	while (*pt1 != '\0')    //while contents of pt1 not equal to null:
	{
		if (*pt2 == '\0')   //if contents of pt2 equal to null, pt1 is greater than pt2
			return  1;	
		if (*pt2 > *pt1)    //if contents of pt2 greater than contents of pt1, pt2 is greater than pt1
			return -1;		
		if (*pt1 > *pt2)    // if contents of p1 greater than contents of pt2, pt1 is greater than pt2
			return  1;		

		pt1++;
		pt2++;
	}

	if (*pt2 != '\0') // if contents of p2 not equal to null, pt2 is greater than pt1
		return -1; 

	return 0; //the contents of both strings are equal
}
