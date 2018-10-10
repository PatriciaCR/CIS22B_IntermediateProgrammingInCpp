// Specification file for the Book class
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


class Book
{
private:
	string ISBN;
	string title;
	string author;
	string publisher;
	string dateAdded;
	int quantityOnhand;
	double wholesaleCost;
	double retailPrice;

public:

	//Default Constructor
	Book(){ ISBN = ""; title = ""; author = ""; publisher = ""; dateAdded = ""; quantityOnhand = 0; wholesaleCost = 0.0; retailPrice = 0.0; }

	// Exception class for a negative number
	class NegativeNumber{ };

	// Exception class for a not valid input (incorrect data type)
	class NotValid{};

	// Mutator functions
	void setISBN(string isbnpass)
	{
		ISBN = isbnpass;
	}

	void setTitle(string titlepass)
	{
		title = titlepass;
	}

	void setAuthor(string authorpass)
	{
		author = authorpass;
	}

	void setPublisher(string publisherpass)
	{
		publisher = publisherpass;
	}

	void setDateadded(string dateAddedpass)
	{
		dateAdded = dateAddedpass;
	}

	void setQuantity(int quantitypass)
	{
		if (!cin.fail()) //Checks if the user inserted a correct value for quantity (integer)
			quantityOnhand = quantitypass;
		else //If he/she did not insert a correct value throw Notvalid Exception
			throw NotValid();

		if (quantitypass > 0) //Checks if the user inserted a non-negative greater than zero value 
			quantityOnhand = quantitypass; 
		else
			throw NegativeNumber();	 //If he/she did not insert a correct value throw NegativeNumber Exception
	}

	void setWholesale(double costpass)
	{
		if (!cin.fail()) //Checks if the user inserted a correct value for wholesale (double)
			wholesaleCost = costpass;
		else//If he/she did not insert a correct value throw Notvalid Exception
			throw NotValid(); 

		if (costpass > 0) //Checks if the user inserted a non-negative greater than zero value 
			wholesaleCost = costpass;
		else
			throw NegativeNumber(); //If he/she did not insert a correct value throw NegativeNumber Exception
	}

	void setRetail(double pricepass)
	{
		if (!cin.fail()) //Checks if the user inserted a correct value for retail (double)
			retailPrice = pricepass;
		else //If he/she did not insert a correct value throw Notvalid Exception
			throw NotValid();

		if (pricepass > 0) //Checks if the user inserted a non-negative greater than zero value 
			retailPrice = pricepass;
		else
			throw NegativeNumber(); //If he/she did not insert a correct value throw NegativeNumber Exception
	}

	// Accessor functions
	string getISBN()
	{
		return ISBN;
	}

	string gettitle()
	{
		return title;
	}

	string getauthor()
	{
		return author;
	}

	string getpublisher()
	{
		return publisher;
	}

	string getdateadded()
	{
		return dateAdded;
	}

	int getquantity()
	{
		return quantityOnhand;
	}

	double getwholesale()
	{
		return wholesaleCost;
	}

	double getretail()
	{
		return retailPrice;
	}

	friend ostream& operator << (ostream& os, Book& books) //Overload the ostream operator to display the information of an specific book object 
	{
		os << " 1) ISBN: ";
		os << books.getISBN();
		os << "\n\n 2) Title: ";
		os << books.gettitle();
		os << "\n\n 3) Author: ";
		os << books.getauthor();
		os << "\n\n 4) Publisher: ";
		os << books.getpublisher();
		os << "\n\n 5) Date Added: ";
		os << books.getdateadded();
		os << "\n\n 6) Quantity: ";
		os << books.getquantity();
		os << "\n\n 7) Wholesale value: ";
		os << books.getwholesale();
		os << "\n\n 8) Retail value: ";
		os << books.getretail();
		return os;
	}

	friend istream &operator >> (istream &is, Book & books) //Overload the ostream operator to get the information of an specific book object 
	{
		string temp;
		int temp1;
		double temp2;
		bool tryAgain = true; // Flag to re-read input

		cout << " 1) ISBN: ";
		is.clear();
		is.ignore(100, '\n');
		getline(is, temp);
		books.setISBN(temp); //Set ISBN
		cout << "\n\n 2) Title: ";
		getline(is, temp);
		books.setTitle(temp); //Set Title
		cout << "\n\n 3) Author: ";
		getline(is, temp);
		books.setAuthor(temp); //Set Author
		cout << "\n\n 4) Publisher: ";
		getline(is, temp);
		books.setPublisher(temp); //Set Publisher
		cout << "\n\n 5) Date Added (YYYY/MM/DD): ";
		getline(is, temp);
		books.setDateadded(temp); //Set Date added
		cout << "\n\n 6) Quantity: ";
		is >> temp1;
		// Store the quantity in the books object.
		while (tryAgain)
		{
			try
			{
				books.setQuantity(temp1);
				// If no exception was thrown, then the
				// next statement will execute.
				tryAgain = false;
			}
			catch (Book::NotValid) 
			{
				cin.clear(); //Clears the error flag on cin
				cin.ignore(1000, '\n'); //Skips to the next newline (to ignore anything else on the same line as the non-number so that it does not cause another parse failure)
				cout << "\n\tPlease enter a valid integer: ";
				is >> temp1;
			}
			catch (Book::NegativeNumber)
			{
				cout << "\n\tPlease enter a non-negative greater than zero value: ";
				is >> temp1;
			}
		}
		cout << "\n\n 7) Wholesale value: ";
		is >> temp2;
		tryAgain = true;
		// Store the wholesale in the books object.
		while (tryAgain)
		{
			try
			{
				books.setWholesale(temp2); //Set Wholesale Value
				// If no exception was thrown, then the
				// next statement will execute.
				tryAgain = false;
			}
			catch (Book::NotValid)
			{
				cin.clear(); //Clears the error flag on cin
				cin.ignore(1000, '\n');//Skips to the next newline (to ignore anything else on the same line as the non-number so that it does not cause another parse failure)
				cout << "\n\tPlease enter a valid decimal number: ";
				is >> temp2;
			}
			catch (Book::NegativeNumber)
			{
				cout << "\n\tPlease enter a non-negative value: ";
				is >> temp2;
			}
		}
		cout << "\n\n 8) Retail value: ";
		is >> temp2;
		tryAgain = true;
		// Store the retail in the books object.
		while (tryAgain)
		{
			try
			{
				books.setRetail(temp2); //Set Retail Value
				// If no exception was thrown, then the
				// next statement will execute.
				tryAgain = false;
			}
			catch (Book::NotValid)
			{
				cin.clear(); //Clears the error flag on cin
				cin.ignore(1000, '\n'); //Skips to the next newline (to ignore anything else on the same line as the non-number so that it does not cause another parse failure)
				cout << "\n\tPlease enter a valid decimal number: ";
				is >> temp2;
			}
			catch (Book::NegativeNumber)
			{
				cout << "\n\tPlease enter a non-negative value: ";
				is >> temp2;
			}
		}
		return is;
	}
};

#endif