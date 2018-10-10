#define _CRT_SECURE_NO_WARNINGS

// Implementation file for the Cashier class.
#include"Cashier.h"
#include<vector>
#include<time.h>		// Used to calculate the date


int Cashier::displayMenu()//Display the Cashier Menu and get the choice of the user
{
	int choice, cont = 0;

	cout << string(60, '=') << endl << endl;
	cout << "\t\t  Serendipity booksellers\n\n\t\t\t Cashier\n\n";
	cout << string(60, '=') << endl << endl;
	cout << "  1)Add Books by Title\n\n";
	cout << "  2)Add Books by ISBN\n\n";
	cout << "  3)Print Receipt\n\n";
	cout << "  4)Return to Main Menu\n\n";
	cout << string(60, '-') << endl << endl;

	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice,try again\n\n";
			cout << string(60, '-') << endl << endl;
		}
		cout << " Please enter the number of your choice: ";
		cin >> choice;
		cont++;
	} while ((choice > 4) || (choice < 1));
	cout << "\n\n You selected item " << choice << endl << endl;

	return choice;
}


void Cashier::addbyISBN(vector<Book> &books, vector<Book> &cashierbuy) //Add a book to buy by ISBN
{
	system("pause");
	system("CLS");

	cout << string(90, '=') << endl << endl;
	cout << "\t\t\t* * *  A D D   B Y   I S B N  * * *\n\n";
	cout << string(90, '=') << endl << endl;

	//Ask the user for the ISBN of the book
	cout << "\n Please enter the ISBN of the book you want to look for: ";
	string isbn;
	int position;
	cin >> isbn;
	MenuItem::Sort(books, books.size(), "isbn"); //Call the member function of the base class that sorts the vector of books respect the ISBN
	position = MenuItem::SearchISBN(books, isbn, books.size() - 1, 0); // //Call the member function of the base class that search the ISBN the user inserted

	if (position != -1) //If the book was found display the information of the book
	{
		cout << endl << string(90, '-') << endl << endl;
		cout << "\t\t    I N F O R M A T I O N   O F   T H E   B O O K\n\n\n";
		cout << books[position];
		cout << endl << endl;
		cout << string(90, '=') << endl << endl;
	

	//Ask the user if he/she would like the buy the book that was found
	string choice;
	int cont = 0;
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
			cout << string(90, '-') << endl;
		}
		cout << "\n Is this the book you want to buy?. Enter 'Yes' or 'No':\n\n ";
		cin >> choice;
		cont++;
	} while ((choice != "Yes") && (choice != "No"));

	//If the user wants to buy the book that was found, ask the amount of books he/she will buy
	if (choice == "Yes")
	{
		int choice;
		int cont = 0;
		do
		{
			if (cont > 0)
			{
				cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
				cout << string(90, '-') << endl;
			}
			cout << "\n How many books of this title would you like to buy?: \n\n ";
			cin >> choice;

			//if there are not enough books tell the user and get a new value for the quantity
				while (choice > (books[position].getquantity()))
				{

					cout << "\n There are not enough books of this title. We have " << books[position].getquantity() << " available.\n\n";
					cout << string(90, '-') << endl;
					cout << " Please select a new quantity\n\n ";
					cin >> choice;
				}
			cont++;
		} while (choice < 0); //Quantity cannot be negative or 0

		Book buy; //Define an instance of the Book class that will set all the attributes
		buy.setISBN(books[position].getISBN()); 
		buy.setTitle(books[position].gettitle());
		buy.setAuthor(books[position].getauthor());
		buy.setPublisher(books[position].getpublisher());
		buy.setDateadded(books[position].getdateadded());
		books[position].setQuantity(books[position].getquantity() - choice); //Decrease the amount of books in the vector of books according to the quantity of books the user chose
		buy.setQuantity(choice);
		buy.setWholesale(books[position].getwholesale());
		buy.setRetail(books[position].getretail());
		cashierbuy.push_back(buy); //Add the book at the end of the cashierbuy vector
	}
	cout << endl << string(90, '=') << endl << endl;
	
	}
	else //Else tell the user that the book was not found
	{
		cout << "\n The book with ISBN: " << isbn << " was not found on the inventory.\n\n";
		cout << endl << string(90, '=') << endl << endl;
	}

	int cont = 0;
	string chc;
	//Ask the user if he/she would like to buy another book 
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to buy another book? Enter 'Yes' or 'No':  ";
		cin >> chc;
		cont++;
	} while ((chc != "Yes") && (chc != "No"));
	cout << endl << endl;

	//If the user wants to buy another book, call display menu 2
	if (chc == "No")
	if (cashierbuy.size() != 0)
		printreceipt(cashierbuy);
}

void Cashier::addbyTitle(vector<Book> &books, vector<Book> &cashierbuy) //Add a book to buy by title
{
	system("pause");
	system("CLS");

	cout << string(90, '=') << endl << endl;
	cout << "\t\t\t* * *  A D D   B Y   T I T L E  * * *\n\n";
	cout << string(90, '=') << endl << endl;

	cout << "\n Please enter the title of the book you want to look for:\n\n ";
	string title;
	int position;
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin, title);
	MenuItem::Sort(books, books.size(), "title"); //Call the member function of the base class that sorts the vector of books respect to the title
	position = MenuItem::SearchName(books, title, books.size() - 1, 0); //Call the member function of the base class that search the title the user inserted

	//If the book was found display the information of the book
	if (position != -1)
	{
		cout << endl << string(90, '-') << endl << endl;
		cout << "\t\t   I N F O R M A T I O N   F O R   T H E   B O O K\n\n\n";
		cout << books[position];
		cout << endl << endl;
		cout << string(90, '=') << endl << endl;
	

		//Ask the user if he/she would like the buy the book that was found
		string choice;
		int cont = 0;
		do
		{
			if (cont > 0)
			{
				cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
				cout << string(90, '-') << endl;
			}
			cout << "\n Is this the book you want to buy?. Enter 'Yes' or 'No':\n\n ";
			cin >> choice;
			cont++;
		} while ((choice != "Yes") && (choice != "No"));

		//If the user wants to buy the book that was found, ask the amount of books he/she will buy
		if (choice == "Yes")
		{
			int choice;
			int cont = 0;
			do
			{
				if (cont > 0)
				{
					cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
					cout << string(90, '-') << endl;
				}
				cout << "\n How many books of this title would you like to buy?: \n\n ";
				cin >> choice;

				//if there are not enough books tell the user and get a new value for the quantity
				while (choice > (books[position].getquantity()))
				{

					cout << "\n There are not enough books of this title. We have " << books[position].getquantity() << " available.\n\n";
					cout << string(90, '-') << endl;
					cout << " Please select a new quantity\n\n ";
					cin >> choice;
				}
				cont++;
			} while (choice < 0); //Quantity cannot be negative or 0

			Book buy; //Define an instance of the Book class that will set all the attributes
			buy.setISBN(books[position].getISBN());
			buy.setTitle(books[position].gettitle());
			buy.setAuthor(books[position].getauthor());
			buy.setPublisher(books[position].getpublisher());
			buy.setDateadded(books[position].getdateadded());
			books[position].setQuantity(books[position].getquantity() - choice); //Decrease the amount of books in the vector of books according to the quantity of books the user chose
			buy.setQuantity(choice);
			buy.setWholesale(books[position].getwholesale());
			buy.setRetail(books[position].getretail());
			cashierbuy.push_back(buy); //Add the book at the end of the cashierbuy vector
		}
		cout << endl << string(90, '=') << endl << endl;

	}
	else //Else tell the user that the book was not found
	{
		cout << "\n The book of title: " << title << " was not found on the inventory.\n\n";
		cout << endl << string(90, '=') << endl << endl;
	}

	int cont = 0;
	string chc;
	//Ask the user if he/she would like to buy another book 
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to buy another book? Enter 'Yes' or 'No':  ";
		cin >> chc;
		cont++;
	} while ((chc != "Yes") && (chc != "No"));
	cout << endl << endl;

	//If the user wants to buy another book, call display menu 2 
	if (chc == "No")
	if (cashierbuy.size()!=0)
		printreceipt(cashierbuy);

}
void Cashier::printreceipt(vector<Book>&cashierbuy) //Print the receipt for the transaction
{
	system("pause");
	system("CLS");

	char date[9];		//Definition of date
	_strdate_s(date);

	cout << endl << endl<<endl;
	cout << "\t\t\t\t\t* * *  S E R E N D I P I T Y   B O O K S E L L E R S  * * *" << endl << endl<<endl;
	cout<<"  Date: "<<date<<endl<<endl << "  ";
	cout << string(133, '=') << endl;
	cout << "  " << left << setw(16) << "ISBN" << "|" << left << setw(70) << "Title" << "|" << left << setw(10) << "Quantity" << "|" << left << setw(17) << "Cost" << "|" << left << setw(17) << "Total" << endl;
	cout << "  " << string(133, '=') << endl;
	double retail = 0.0;
	for (int x = 0; x < cashierbuy.size(); x++)
	{
		cout << "  " << left << setw(17) << cashierbuy[x].getISBN() << left << setw(71) << cashierbuy[x].gettitle() << left << setw(11) << cashierbuy[x].getquantity() <<
			left << setw(18) << setprecision(2) << fixed << cashierbuy[x].getretail() << left << setw(18) << setprecision(2) << fixed << (cashierbuy[x].getquantity())*(cashierbuy[x].getretail()) << endl << endl;
		retail = retail + (cashierbuy[x].getquantity())*(cashierbuy[x].getretail()); //Calculates the Subtotal
	}
	cout <<endl<<endl<<endl<< "  " << string(133, '-') << endl;
	cout << endl;
	cout << right << setw(119) << "Subtotal: " << setprecision(2) << fixed << retail<<endl;
	cout << right << setw(119) << "Tax: " << setprecision(2) << fixed << retail*0.075<<endl;
	cout << right << setw(119) << "Total: " << setprecision(2) << fixed << retail+(retail*0.075)<<endl;
	cout << endl << right << setw(134) << string(26, '=');
	cout << endl << endl;
	cout << "\t\t\t\t\t\tThank you for shopping at Serendipity!";
	cout << endl << endl;
	cashierbuy.clear(); //Clear the vector of books that the user bought to use it in another transaction 
}