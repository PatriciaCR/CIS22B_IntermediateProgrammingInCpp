/*******************************************************************************************************/
/*
CIS 22B, Spring Quarter 2015.

Lab 1: This program will read the contents of a file inserted by the user into an array of just words,
ignoring single character words. Then it will sort the contents of the array in ascending order and
finally it will ask the user for words to search.

Name: Patricia Caceres.
*/
/*******************************************************************************************************/



/********************************************************************************************************************************************/
/*
                                                    L A B   1   :   P S E U D O C O D E

1. Ask the user for output file path
2. Open output file - check file opened successfully to continue
3. Ask the user for input file path
4. Open input file - check file opened successfully to continue
5. While the loop has not reach the end of file and the counter is less than size.
Read one word of the file.
If the loop has reach the end of file break the loop.
If the length of the word is 0 (could happen just in the first iteration), the file is empty.
If the word length is equal to 1(just one character) continue the loop, else insert the word in the vector and increment the counter.

6. Call the function ascending order to sort the array of words.
function will sort the array using a selection sort algorithm and a recursive function
7. Asks the user to insert the word he/she wants to look for
Read what the user inserted
Call the function Search which will look for the word inside the vector using a binary search and a recursive function
Show in the screen and in the output file the result.
Loop till user wants to quit

*/
/********************************************************************************************************************************************/



#include<iomanip>
#include <string>
#include<iostream>
#include<vector> 
#include<fstream>
using namespace std;

void AscendingOrder(vector<string> & words, int SIZE); //Define a void function that will sort the contain of the vector of words in ascending order.
int Search(vector<string> WORDS, string value, int last, int first = 0);//Define a void function that will search in the vector of words a word that the user will insert.

int main()
{
	string locinput, locoutput;  //Declare as strings the location+name of the input and output file.

	//Explain the user what the program will do
	cout << string(100, '-') << endl << endl;
	cout << "Hi! This program will read the contents of an input file into an array of just words, ignoring\n";
	cout << "single characters.Then it will sort the contents of the array in ascending order and finally it\nwill ask you for words to search.\n\n";
	cout << string(100, '-') << endl << endl;
	
	//Defines an input file 
	ifstream infile;
	//Defines an output file
	ofstream outfile;
	
	int cont1 = 0;
	
	do
	{
		if (cont1>0)
			cout << "\nError opening the file. Make sure to create the file then try again.\n\n";
		
		//Ask the user for the location+name of the input and input file.
		cout << "Please insert the location+name where the input file is located:\n";
		cin >> locinput;
		cont1++;
		//open the input file.
		infile.open(locinput);
	} while (!infile);


	cont1 = 0;
	
	
	do
	{
		if (cont1>0)
			cout << "\nError opening the file. Make sure to create the file then try again.\n\n";

		//Ask the user for the location+name of the output and output file.
		cout << "\n\nNow please insert the location+name of the output file:\n";
		cin >> locoutput;
		cout << endl;
		cont1++;
		outfile.open(locoutput);
	} while (!outfile);



	int size = 1024; //Defines a integer called size that will be used as the max value for the vector 
	vector<string> words; //Defines a vector of strings that will hold the words read from the file.
	
	//This will hold each word that is going to be read from the file.
	string word;

		//While the loop has not reach the end of file and the counter is less than size.
		for (int cont = 0; infile.peek() != EOF&&cont < size;)
		{
			infile >> word; //Read one word of the file.

			//If the loop has reach the end of file break the loop.
			if (infile.peek() == EOF)
				break;
			//If the length of the word is 0 (could happen just in the first iteration), the file is empty.
			if (word.length() == 0)
			{
				cout << "The input file that you choose is empty. Please run the program again and this time make sure to have some words in the file.";
				exit(0);
			}

			//If the word length is equal to 1(just one character) continue the loop, else insert the word in the vector and increment the counter.
			if (word.length() == 1)
				continue;
			else
			{
				words.push_back(word);
				cont++;
			}
		}

	infile.close(); //Close the input file.

	AscendingOrder(words, words.size()); //Call the function ascending order to sort the array of words.

	//Print the sort array on the output file. 
	outfile << string(100, '=') << endl<<endl;
	outfile << "\t\t***A R R A Y   S O R T E D   I N   A S C E N D I N G   O R D E R***\n\n";
	outfile << string(100, '=') << endl << endl;
	outfile << "Position\tWord" << string(37, ' ') << "Position\tWord\n";
	
	int rounded;
	rounded = words.size() / 2;
	if (words.size() % 2 != 0)
		rounded = (words.size() / 2) + 1;

	
	for (int x = 0, y = rounded; x < rounded && y < words.size(); x++, y++)
	{
		
		outfile << "   " << x << ")\t\t" << left << setw(43) << words[x] << y << ")\t\t" << words[y] << endl;

		if (x == rounded -2)
		{
			x = rounded -1;
			outfile << "   " << x << ")\t\t"  << left << setw(43) << words[x];
		}
	}
	outfile << endl << string(100, '=') << endl << endl;


	string value; //Define as string the variable value that will be used to storage the word the user wants to look for.

	cout << string(100, '-') << endl;
	/*Asks the user to insert the word he/she wants to look for, reads what the user inserted, calls the function Search which will
	look for the word inside the vector and then show in the screen and in the output file the result*/
	cout << "Please insert the word you want me to look for:\n\n";
	cin >> value;

	//Copy for the file 
	outfile << "\nPlease insert the word you want me to look for:\n\n";
	outfile << value;

	if (Search(words, value, words.size() - 1) >= 0)
	{
		cout << "\nThe word " << words[Search(words, value, words.size() - 1)] << " is in the position " << Search(words, value, words.size() - 1);
		cout << endl;

		//Output for the file
		outfile << "\n\nThe word " << words[Search(words, value, words.size() - 1)] << " is in the position " << Search(words, value, words.size() - 1) << endl;
	}
	else
	{
		cout << "\n\nSorry! I could not find the word you wanted me to look for :(\n";
		outfile << "\n\nSorry! I could not find the word you wanted me to look for :(\n"; //Copy for the file 
	}


	string choice = "Yes"; //Defines a string value called choice as Yes. This variable will storage the choice of the user of wether he/she wants to continue or not

	while (choice == "Yes") //While the choice is Yes proceed to the loop, else continue the program
	{

		do
		{
			if ((choice != "Yes") && (choice != "No")) //If the loop has been repeated more than once display this message
			{
				cout << "\nYou did not insert a correct choice, Please try again\n";
				outfile << "\nYou did not insert a correct choice, Please try again\n";
			}
			//Asks the user if he/she wants to insert another word, read the choice.
			cout << "\nDo you want me to look for another word?. Type 'Yes' or 'No'\n\n";
			cin >> choice;
			cout << endl;
			
			//Copy for the file 
			outfile << "\nDo you want me to look for another word?. Type 'Yes' or 'No'\n\n";
			outfile<< choice;
			outfile<< endl;
		} while ((choice != "Yes") && (choice != "No")); //Repeat the loop if the user did not insert correct values for the variable choice


		if (choice == "Yes") // If choice is Yes, let the user insert a word to look for and search for it in the vector

		{
			/*Asks the user to insert the word he/she wants to look for, reads what the user inserted, calls the function Search which will
			look for the word inside the vector and then show in the screen and in the output file the result*/
			cout << string(100, '-') << endl;
			cout << "\nPlease insert the word you want me to look for:\n\n";
			cin >> value;

			//Copy for the file 
			outfile << string(100, '-') << endl;
			outfile << "\nPlease insert the word you want me to look for:\n\n";
			outfile << value;

			if (Search(words, value, words.size() - 1) >= 0)
			{
				cout << "\n\nThe word " << words[Search(words, value, words.size() - 1)] << " is in the position " << Search(words, value, words.size() - 1);
				cout << endl;

				//Output for the file
				outfile << "\n\nThe word " << words[Search(words, value, words.size() - 1)] << " is in the position " << Search(words, value, words.size() - 1) << endl;
			}
			else
			{
				cout << "\n\nSorry! I could not find " << value << " on the array of words :(\n";
				//Copy for the file 
				outfile << "\n\nSorry! I could not find " << value << " on the array of words :(\n";
			}
		}
	}
	outfile.close(); //Close the output file.
	cout << endl << endl;
	system("pause");
	return 0;
}

void AscendingOrder(vector<string> & wrds, int size) //Function that sorts the vector in ascending order using a selection sort algorithm and a recursive function
{
		int maxIndex = 0;
		string temp;
		int index = 0;

		for (index = maxIndex; index < size; index++) //Goes through the vector and look for the smallest element 
		{
			if (wrds[index] > wrds[maxIndex]) //Compares every element of the array with the element in the position maxIndex
				maxIndex = index; //If it is greater maxIndex will take the value of the position of the element	
		}

		//Swap the element in the last position of the vector with the smallest element of the vector.
		temp = wrds[size - 1];
		wrds[size - 1] = wrds[maxIndex];
		wrds[maxIndex] = temp;

		if (size > 1) //If the size of the vector is more than 1, call this function again 
		{
			AscendingOrder(wrds, --size);
		}
}

int Search(vector<string> WORDS, string value, int last, int first) //Function that search the word that the user inserted using a Binary Search algorithm and a recursive function
{
	int middle = (last + first) / 2; // Middle position

	if (WORDS[middle] == value) // If value is found at the middle position is equal to the word the user inserted then return middle;
		return middle;

	//If the number found in the middle position is greater than the word inserted by the user then last=middle-1, else last will stay the same
	last = WORDS[middle] > value ? middle - 1 : last;
	//If the number found in the middle position is less or equal than the value inserted by the user then last=middle+1, else first will stay the same
	first = WORDS[middle] <= value ? middle + 1 : first;

	//if first is not less or equal to last return -1 else call the function again
	return !(first <= last) ? -1 : Search(WORDS, value, last, first);
}