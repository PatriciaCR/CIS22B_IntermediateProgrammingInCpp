#define _CRT_SECURE_NO_WARNINGS

// Implementation file for the Report class.
#include"Report.h"

int Report::displayMenu() //Display the Report Menu and get the choice of the user
{
	int choice, cont = 0;

	cout << string(60, '=') << endl << endl;
	cout << "\t\t  Serendipity booksellers\n\n\t\t\t  Report\n\n";
	cout << string(60, '=') << endl << endl;
	cout << "  1)Inventory Listing\n\n";
	cout << "  2)Inventory Wholesale Value\n\n";
	cout << "  3)Inventory Retail Value\n\n";
	cout << "  4)Listing by Quantity\n\n";
	cout << "  5)Listing by Cost\n\n";
	cout << "  6)Listing by Age\n\n";
	cout << "  7)Return to Main Menu\n\n";
	cout << string(60, '-') << endl << endl;

	//Validate the choice
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice,try again\n\n";
			cout << string(60, '-')<<endl<<endl;
		}
		cout << " Please enter the number of your choice: ";
		cin >> choice;
		cont++;
	} while ((choice > 7) || (choice < 1));
	cout << "\n\n You selected item " << choice<<endl<<endl;

	return choice; //Return choice to main
}

void Report::InventoryListing(vector<Book>& books) //Display the Inventory Listing
{
	system("pause");
	system("CLS");
	cout << endl << endl;
	cout << "\t\t\t\t\t\t  * * *  I N V E N T O R Y   L I S T I N G  * * *" << endl << endl << endl << "  ";
	cout << string(145, '=') << endl;
	cout << "  " << left << setw(16) << "ISBN" << "|" << left << setw(70) << "Title" << "|" << left << setw(47) << "Author" << endl;
	cout << "  " << string(145, '=') << endl;

	for (int x = 0; x < books.size(); x++)
	{
		cout << "  " << left << setw(16) << books[x].getISBN() << "|" << left << setw(70) << books[x].gettitle() << "|" << left << setw(47) << books[x].getauthor() << endl;
		cout << "  " << string(145, '-') << endl;
	}
	cout << endl << endl << endl;
}

void Report::InventoryWholesale(vector<Book>& books) //Display the Inventory Wholesale Value
{
		   system("pause");
		   system("CLS");
		   cout << endl << endl;
		   cout << "\t\t\t\t\t\t  * * *  I N V E N T O R Y   W H O L E S A L E   V A L U E  * * *" << endl << endl << endl << "  ";
		   cout << string(165, '=') << endl;
		   cout << "  " << left << setw(16) << "ISBN" << "|" << left << setw(70) << "Title" << "|" << left << setw(47) << "Author" << "|" << left << setw(10) << "Quantity" << "|" << left << setw(17) << "Wholesale Value" << endl;
		   cout << "  " << string(165, '=') << endl;
		   double whole = 0.0;
		   for (int x = 0; x < books.size(); x++)
		   {
			   cout << "  " << left << setw(16) << books[x].getISBN() << "|" << left << setw(70) << books[x].gettitle() << "|" << left << setw(47) << books[x].getauthor() << "|" << left << setw(10) << books[x].getquantity() << "|" << left << setw(17) << setprecision(2) << fixed << (books[x].getquantity())*(books[x].getwholesale()) << endl;
			   cout << "  " << string(165, '-') << endl;
			   whole = whole + (books[x].getquantity())*(books[x].getwholesale()); //Calculates the Total Wholesale Value
		   }
		   cout << endl;
		   cout << right << setw(149) << "Total wholesale value: " << setprecision(2) << fixed << whole;
		   cout << endl << right << setw(167) << string(41, '=');
		   cout << endl << endl << endl;

}

void Report::InventoryRetail(vector<Book> & books) //Display the Iventory Retail Value
{
	system("pause");
		   system("CLS");
		   cout << endl << endl;
		   cout << "\t\t\t\t\t\t\t* * *  I N V E N T O R Y   R E T A I L   V A L U E  * * *" << endl << endl << endl << "  ";
		   cout << string(165, '=') << endl;
		   cout << "  " << left << setw(16) << "ISBN" << "|" << left << setw(70) << "Title" << "|" << left << setw(47) << "Author" << "|" << left << setw(10) << "Quantity" << "|" << left << setw(17) << "Retail Value" << endl;
		   cout << "  " << string(165, '=') << endl;
		   double retail = 0.0;
		   for (int x = 0; x < books.size(); x++)
		   {
			   cout << "  " << left << setw(16) << books[x].getISBN() << "|" << left << setw(70) << books[x].gettitle() << "|" << left << setw(47) << books[x].getauthor() <<
				   "|" << left << setw(10) << books[x].getquantity() << "|" << left << setw(17) << setprecision(2) << fixed << (books[x].getquantity())*(books[x].getretail()) << endl;

			   cout << "  " << string(165, '-') << endl;
			   retail = retail + (books[x].getquantity())*(books[x].getretail()); //Calculates the Retail Value 
		   }
		   cout << endl;
		   cout << right << setw(149) << "Total retail value: " << setprecision(2) << fixed << retail;
		   cout << endl << right << setw(167) << string(38, '=');
		   cout << endl << endl << endl;
}

void Report::ListingQuantity(vector<Book> & books) //Display the Listing of the Inventory by Quantity
{
	system("pause");
		   system("CLS");
		   MenuItem::Sort(books, books.size(),"quantity"); //Call the member function of the base class that sorts the vector of books in descending order respect to the quantity of books. 
		   cout << endl << endl;
		   cout <<"\t\t\t\t  * * *  L I S T I N G   O F   T H E   I N V E N T O R Y   B Y   Q U A N T I T Y  * * *" << endl << endl << endl << "  ";
		   cout << string(150, '=') << endl;
		   cout << "  " << left << setw(16) << "ISBN" << "|" << left << setw(70) << "Title" << "|" << left << setw(47) << "Author" << "|" << left << setw(10) << "Quantity" << endl;
		   cout << "  " << string(150, '=') << endl;

		   for (int x = 0; x < books.size(); x++)
		   {
			   cout << "  " << left << setw(16) << books[x].getISBN() << "|" << left << setw(70) << books[x].gettitle() << "|" << left << setw(47) << books[x].getauthor() << "|" << left << setw(10) << books[x].getquantity() << endl;
			   cout << "  " << string(150, '-') << endl;
		   }
		   cout << endl << endl << endl;
}

void Report::ListingCost(vector<Book> & books) //Display the Listing of the Inventory by Cost.
{
	system("pause");
		   system("CLS");
		   MenuItem::Sort(books, books.size(), "retail"); //Call the member function of the base class that sorts the vector of books in descending order respect to the retail cost 
		   cout << endl << endl;
		   cout << "\t\t\t\t    * * *  L I S T I N G   O F   T H E   I N V E N T O R Y   B Y   C O S T  * * *" << endl << endl << endl << "  ";
		   cout << string(150, '=') << endl;
		   cout << "  " << left << setw(16) << "ISBN" << "|" << left << setw(70) << "Title" << "|" << left << setw(47) << "Author" << "|" << left << setw(10) << "Price per unit" << endl;
		   cout << "  " << string(150, '=') << endl;

		   for (int x = 0; x < books.size(); x++)
		   {
			   cout << "  " << left << setw(16) << books[x].getISBN() << "|" << left << setw(70) << books[x].gettitle() << "|" << left << setw(47) << books[x].getauthor() << "|" << left << setw(10) << setprecision(2) << fixed << books[x].getretail() << endl;
			   cout << "  " << string(150, '-') << endl;
		   }
		   cout << endl << endl << endl;
}

void Report::ListingAge(vector<Book> & books) //Display the Listing of the Inventory by Age
{
	system("pause");
		   system("CLS");
		   MenuItem::Sort(books, books.size(), "date"); //Call the member function of the base class that sorts the vector of books in descending order respect to the date the book was added. 
		   cout << endl << endl;
		   cout << "\t\t\t\t      * * *  L I S T I N G   O F   T H E   I N V E N T O R Y   B Y   A G E  * * *" << endl << endl << endl << "  ";
		   cout << string(150, '=') << endl;
		   cout << "  " << left << setw(16) << "ISBN" << "|" << left << setw(70) << "Title" << "|" << left << setw(47) << "Author" << "|" << left << setw(10) << "Date added" << endl;
		   cout << "  " << string(150, '=') << endl;

		   for (int x = 0; x < books.size(); x++)
		   {
			   cout << "  " << left << setw(16) << books[x].getISBN() << "|" << left << setw(70) << books[x].gettitle() << "|" << left << setw(47) << books[x].getauthor() << "|" << left << setw(10) << books[x].getdateadded() << endl;
			   cout << "  " << string(150, '-') << endl;
		   }
		   cout << endl << endl << endl;
}