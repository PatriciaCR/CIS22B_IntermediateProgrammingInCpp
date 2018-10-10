#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include"MenuItem.h"
#include"Inventory.h"
#include"Report.h"
#include"Cashier.h"
#include"Book.h"
#include <new>       // Needed for bad_alloc
using namespace std;

void SaveChangesF(vector<Book> &,string); //Save the changes in the book inventory file

int main()
{
	vector<Book> books; //Defines a vector of type Book that will hold the characteristics of the books
	vector<Book> cashierbuy;
	//Defines and open an inventory text file for input 
	string filename;
	filename = "C:\\Users\\Patricia\\source\\repos\\CIS22B_IntermediateProgrammingInCpp\\Final_Project\\Final_Project\\InventoryFile.txt";
	fstream bookFile;
	bookFile.open(filename, ios::in);

	if (bookFile)
	{
		//While the loop has not reach the end of file and the counter is less than size.
		for (int cont = 0; bookFile.peek() != EOF; cont++)
		{

			Book book; //Creates a Book object and call the default constructor
			
			//Define variables that will hold the different attributes for a book.
			string isbn, title, author, publisher, dateadd;
			int quantity;
			double wholesale, retail;

			while (getline(bookFile, isbn)) //cin.ignore() was not working...
			if (isbn != "")
			{
				break;
			}
			book.setISBN(isbn);  //Set ISBN

			getline(bookFile, title);
			book.setTitle(title); //Set ISBN

			getline(bookFile, author);
			book.setAuthor(author); //Set Author

			getline(bookFile, publisher);
			book.setPublisher(publisher); //Set Publisher

			getline(bookFile, dateadd); 
			book.setDateadded(dateadd); //Set Date add

			bookFile >> quantity;
			book.setQuantity(quantity); //Set Quantity

			bookFile >> wholesale;
			book.setWholesale(wholesale); //Set Wholesale Value

			bookFile >> retail;
			book.setRetail(retail); //Set Retail Value
			
			try
			{
				books.push_back(book); //Add the book at the end of the vector
			}
			catch (bad_alloc)
			{
				cout << "Insufficient memory...\n";
			}

			//If the loop has reach the end of file break the loop.
			if (bookFile.peek() == EOF)
				break;
		}
	}

	//If the input file does not exists
	else
	{
		cout << "\n\n The input file is not placed in the directory " << filename << ".\n\n Please verify it and then start the program again.\n\n\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	bookFile.close(); //Close the input file.

	MenuItem menuItem; //Creates an object of the base class
	MenuItem *menuitemptr = 0; //Creates base class pointer
	Cashier cashier; //Creates a Cashier object	
	Inventory inventory; //Creates a Inventory object
	Report report; //Creates a Report object
	int choice; //Holds choice for main menu
	int menuchoice;

	do //Repeat until the user wants to exit the program
	{
		menuitemptr = &menuItem; //Points the menuitemptr to the object of type base class
		choice = menuitemptr->displayMenu(); //Call the function DisplayMenu of the base class and store the return value in choice. Late Binding
		switch (choice)
		{
		case 1: //Cashier Menu
			do{
				system("CLS");
				menuitemptr = &cashier; //Points the menuitemptr to the object of type Cashier
				menuchoice = menuitemptr->displayMenu(); //Call the function DisplayMenu of the Cashier class and store the return value in 
				if (menuchoice == 1)
					cashier.addbyTitle(books, cashierbuy);  //Call the cashier member function to add books by Title
				if (menuchoice == 2)
					cashier.addbyISBN(books, cashierbuy);  //Call the cashier member function to add books by ISBN
				if (menuchoice == 3)
					cashier.printreceipt(cashierbuy);  //Call the cashier member function to print the receipt
				SaveChangesF(books, filename); //Call the function that saves the changes on the input file
				system("pause");
				system("CLS");
			} while (menuchoice != 4);
					break;
		case 2: //Inventory Database Menu
			do{
				system("CLS");
				menuitemptr = &inventory; //Points the menuitemptr to the object of type Inventory
				menuchoice = menuitemptr->displayMenu(); //Call the function DisplayMenu of the Inventory class and store the return value in menuchoice
				if (menuchoice == 1)
					inventory.LookUp(books);  //Call the inventory member function to look up a book
				if (menuchoice == 2)
					inventory.Add(books);  //Call the inventory member function to add a book
				if (menuchoice == 3)
					inventory.Edit(books);  //Call the inventory member function to edit a book
				if (menuchoice == 4)
					inventory.Delete(books);  //Call the inventory member function to delete a book
				SaveChangesF(books, filename); //Call the function that saves the changes on the input file
				system("pause");
				system("CLS");
			} while (menuchoice != 5);
			break;
		case 3: //Report Menu
			do{
				system("CLS");
				menuitemptr = &report; //Points the menuitemptr to the object of type Report
				menuchoice = menuitemptr->displayMenu(); //Call the function DisplayMenu of the Report class and store the return value in menuchoice
				if (menuchoice == 1)
					report.InventoryListing(books);   //Call the report member function to display the Inventory Listing
				if (menuchoice == 2)
					report.InventoryWholesale(books);   //Call the report member function to display the Inventory by Wholesale Value
				if (menuchoice == 3)
					report.InventoryRetail(books);   //Call the report member function to display the Inventory by Retail Value
				if (menuchoice == 4)
					report.ListingQuantity(books);    //Call the report member function to display the Listing of the Inventory by quantity
				if (menuchoice == 5)
					report.ListingCost(books);    //Call the report member function to display the Listing of the Inventory by cost
				if (menuchoice == 6)
					report.ListingAge(books);    //Call the report member function to display the Listing of the Inventory by date added		
				system("pause");
				system("CLS");
			} while (menuchoice != 7);
			break;
		}
	} while (choice != 4);

	return 0;
}

void SaveChangesF(vector<Book> &books, string flnm)
{
	fstream bookFile;
	//Open the inventory file for output and insert the new inventory of books.
	bookFile.open(flnm, ios::out, ios::trunc);

	for (int x = 0; x < books.size(); x++)
	{
		bookFile << books[x].getISBN() << endl;
		bookFile << books[x].gettitle() << endl;
		bookFile << books[x].getauthor() << endl;
		bookFile << books[x].getpublisher() << endl;
		bookFile << books[x].getdateadded() << endl;
		bookFile << books[x].getquantity() << endl;
		bookFile << books[x].getwholesale() << endl;
		bookFile << books[x].getretail();
		if(x != books.size()-1)
			bookFile << endl;
	}
	bookFile.close(); //Close the output file.
}