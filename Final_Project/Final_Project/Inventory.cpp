#define _CRT_SECURE_NO_WARNINGS

// Implementation file for the Inventory class.
#include"Inventory.h"

int Inventory::displayMenu() //Display the Inventory Menu and get the choice of the user
{
	int choice, cont = 0;

	cout << string(60, '=') << endl<<endl;
	cout << "\t\t  Serendipity booksellers\n\n\t\t    Inventory Database\n\n";
	cout << string(60, '=') << endl<<endl;
	cout << "  1)Look Up a Book\n\n";
	cout << "  2)Add a Book\n\n";
	cout << "  3)Edit a Book's Record\n\n";
	cout << "  4)Delete a Book\n\n";
	cout << "  5)Return to Main Menu\n\n";
	cout << string(60, '-') << endl<<endl;

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
	} while ((choice > 5) || (choice < 1));
	cout << "\n\n You selected item " << choice<<endl<<endl;
	
	return choice;
}
void Inventory::LookUp(vector<Book>& books) //Look up for a book by ISBN or by Title
{
	system("pause");
	system("CLS");

	cout << string(90,'=')<<endl<<endl;
	cout << "\t\t\t* * *  L O O K   U P   A   B O O K  * * *\n\n";
	cout << string(90, '=') << endl << endl;

	int cont = 0;
	string chc;

	//Ask the user how to look for the book
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your preference. Please try again\n\n";
			cout << string(90,'-')<<endl<<endl;
		}
		cout << " Would you like to look for the book by ISBN (Enter 'ISBN') or by title (Enter 'Title')?\n\n ";
		cin >> chc;
		cont++;
	} while ((chc != "ISBN") && (chc != "Title"));

	//If the user wants to search by ISBN
	if (chc == "ISBN")
	{
		cout <<endl<< string(90, '=') << endl;
		cout << "\n Please enter the ISBN of the book you want to look for: ";
		string isbn;
		int position;
		cin >> isbn;
		MenuItem::Sort(books, books.size(), "isbn"); //Call the member function of the base class that sorts the vector of books respect the ISBN
		position = MenuItem::SearchISBN(books, isbn, books.size() - 1, 0); //Call the member function of the base class that search the ISBN the user inserted
		
		if (position != -1) //If the book was found display the information
		{
			cout <<endl <<string(90, '-') << endl<<endl;
			cout << "\t\t    I N F O R M A T I O N   O F   T H E   B O O K\n\n\n";
			cout << books[position]; // << Operator overloading
			cout << endl<<endl;
		}
		else //Else tell the user that the book was not found
		{
			cout << "\n The book with ISBN: " << isbn << " was not found on the inventory.\n\n";
			
		}
	}
	else //Else if the user wants to search by Title 
	{
		cout <<endl <<string(90, '=') << endl;
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
			cout << books[position]; // << Operator overloading
			cout << endl << endl;

		}
		else //Else tell the user that the book was not found
		{
			cout << "\n The book of title: " << title << " was not found on the inventory.\n\n";
			
		}
	}
	cont = 0;
	cout << string(90, '=') << endl << endl;
	
	//Ask the user if he/she would like to look for another book
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to look for another book? Enter 'Yes' or 'No': ";
		cin >> chc;
		cont++;
	} while ((chc != "Yes") && (chc != "No"));

	cout << endl << endl;

	//If the user wants to look for another book call this function again 
	if (chc == "Yes")
		LookUp(books);

}
void Inventory::Add(vector<Book>& books) //Add a book
{
	system("pause");
	system("CLS");

	cout << string(90, '=') << endl << endl;
	cout << "\t\t\t    * * *  A D D   A   B O O K  * * *\n\n";
	cout << string(90, '=') << endl << endl;

	Book book; //Creates a Book object and call the default constructor
	

	//Ask the user for the information for the new book
	cout << " Please insert the information for the new book:\n\n";
	cin >> book; // >> Operator overloading

	books.push_back(book); //Add the new book at the end of the vector 

	cout <<"\n\n"<< string(90, '=') << endl << endl;
	int cont= 0;
	string chc;

	//Ask the user if he/she would like to add another book
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to add another book? Enter 'Yes' or 'No': ";
		cin >> chc;
		cont++;
	} while ((chc != "Yes") && (chc != "No"));
	cout << endl << endl;

	//If the user wants to add another book call this function again
	if (chc == "Yes")
		Add(books);
}
void Inventory::Edit(vector<Book>& books) //Edit the information of a book
{
	system("pause");
	system("CLS");

	cout << string(90, '=') << endl << endl;
	cout << "\t\t\t   * * *  E D I T   A   B O O K  * * *\n\n";
	cout << string(90, '=') << endl << endl;

	int cont = 0;
	string chc;

	//Ask the user how he/she would like to look for the book he/she wants to edit by ISBN or Title
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your preference. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to look for the book you want to edit by ISBN (Enter 'ISBN') or by title\n\n (Enter 'Title')?\n\n\n ";
		cin >> chc;
		cont++;
	} while ((chc != "ISBN") && (chc != "Title"));
	cout <<endl <<string(90, '=') << endl << endl;

	//If the user wants to look by ISBN
	if (chc == "ISBN")
	{
		string isbn;
		int position;
		cout << " Please insert the ISBN of the book you want me to edit: ";
		cin >> isbn;
		MenuItem::Sort(books, books.size(), "isbn"); //Call the member function of the base class that sorts the vector by ISBN
		position = MenuItem::SearchISBN(books, isbn, books.size() - 1, 0); //Call the member function of the base class that search the ISBN the user inserted
		if (position != -1) //If the book is found in the vector, display its information 
		{
			cout <<endl<< string(90, '-') << endl<<endl;
			cout << " Information of the book\n\n";
			cout << books[position]; // << Operator overloading
			cout << endl << endl<<" ";
	
			//Ask the user if the book that was found is the one that he/she would like to edit
			string choice;
			cont = 0;
			do
			{
				if (cont > 0)
				{
					cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
					cout << string(90, '-') << endl;
				}
				cout << "\n Is this the book you want to edit?. Enter 'Yes' or 'No':\n\n ";
				cin >> choice;
				cont++;
			} while ((choice != "Yes") && (choice != "No"));

			//If the user wants to edit the book that was found, ask for the new information
			if (choice == "Yes")
			{
				cout << endl <<endl<< string(90, '=') << endl << endl;
				cout << " Please insert the new information for the book:\n\n\n";
				cin >> books[position]; // >> Operator overloading
				cout << endl;
			}
		}
		else //If the book was not found tell the user
		{
			cout << "\n\n The book with ISBN: " << isbn << " was not found on the inventory.\n\n";
	
		}
	}

	else //Else if the user wants to search by Title
	{
		string title;
		int position;
		cout << " Please insert the title of the book you want me to edit:\n\n ";
		cin.clear();
		cin.ignore(100, '\n');
		getline(cin, title);
		MenuItem::Sort(books, books.size(), "title"); //Call the member function of the base class that will sort the vector of books by Title 
		position = MenuItem::SearchName(books, title, books.size() - 1, 0); //Call the search function of the base class that will search the title of the book in the vector
		
		//If the book was found display the information 
		if (position != -1)
		{
			cout << endl << string(90, '-') << endl << endl;
			cout << books[position]; // << Operator overloading
			cout << endl << endl;
			string choice;
			cont = 0;

			//Ask the user if the book that was found is the one that he/she would like to edit
			do
			{
				if (cont > 0)
				{
					cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
					cout << string(90, '-') << endl ;
				}
				cout << "\n Is this the book you want to edit?. Enter 'Yes' or 'No':\n\n ";
				cin >> choice;
				cont++;
			} while ((choice != "Yes") && (choice != "No"));

			//If the user wants to edit the book that was found, ask for the new information
			if (choice == "Yes")
			{
				cout << endl << endl << string(90, '=') << endl << endl;
				cout << " Please insert the new information for the book:\n\n\n";
				cin>> books[position]; // >> Operator overloading
				cout << endl;
			}
		}
		else //Else if the book was not found tell the user
		{
			cout << "\n\n The book of title: " << title << " was not found on the inventory.\n\n";
		
		}
	}

	//Ask the user if he/she would like to add a new book
	cont = 0;
	cout <<endl <<string(90, '=') << endl << endl;
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to edit another book? Enter 'Yes' or 'No':  ";
		cin >> chc;
		cont++;
	} while ((chc != "Yes") && (chc != "No"));
	cout << endl << endl;

	//If the user wants to edit a book call this function again
	if (chc == "Yes")
		Edit(books);
}


void Inventory::Delete(vector<Book>& books)
{
	system("pause");
	system("CLS");

	cout << string(90, '=') << endl << endl;
	cout << "\t\t     * * *  D E L E T E   A   B O O K  * * *\n\n";
	cout << string(90, '=') << endl << endl;

	//Ask the user how he/she would like to look for the book he/she wants to delete by ISBN or Title 
	int cont = 0;
	string chc;
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your preference. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to look for the book you want to delete by ISBN (Enter 'ISBN') or by title\n\n (Enter 'Title')?\n\n\n ";
		cin >> chc;
		cont++;
	} while ((chc != "ISBN") && (chc != "Title"));
	cout << endl << string(90, '=') << endl << endl;

	//If the user wants to look for the book by ISBN
	if (chc == "ISBN")
	{
		string isbn;
		int position;
		cout << " Please insert the ISBN of the book you want me to delete: ";
		cin >> isbn;
		MenuItem::Sort(books, books.size(), "isbn"); //Call the member function of the base class that sorts the vector of books respect the ISBN
		position = MenuItem::SearchISBN(books, isbn, books.size() - 1, 0); //Call the member function of the base class that search the ISBN the user inserted
		
		//If the book was found display the information 
		if (position != -1)
		{
			cout << endl << string(90, '-') << endl << endl;
			cout << " Information of the book\n\n";
			cout << books[position];
			cout << endl << endl << " ";

			string choice;
			cont = 0;
		
			//Ask the user if the book that was found is the one that he/she would like to delete
			do
			{
				if (cont > 0)
				{
					cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
					cout << string(90, '-') << endl;
				}
				cout << "\n Is this the book you want to delete?. Enter 'Yes' or 'No':\n\n ";
				cin >> choice;
				cont++;
			} while ((choice != "Yes") && (choice != "No"));
			
			//If the user wants to delete the book that was found... Delete it
			if (choice == "Yes")
			{
				//If the book is in the last position of the vector delete the last position
				if (position == (books.size() - 1))
					books.pop_back();
				else //Else, copy the information of the book that is in the last position of the vector in the position of the book that is going to be deleted and then erase the last position
				{
					int last = books.size() - 1;
					books[position].setISBN(books[last].getISBN());
					books[position].setTitle(books[last].gettitle());
					books[position].setAuthor(books[last].getauthor());
					books[position].setPublisher(books[last].getpublisher());
					books[position].setDateadded(books[last].getdateadded());
					books[position].setQuantity(books[last].getquantity());
					books[position].setWholesale(books[last].getwholesale());
					books[position].setRetail(books[last].getretail());
					books.pop_back();
				}
			}
		}
		else //Else if the book was not found tell the user
		{
			cout << "\n\n The book with ISBN: " << isbn << " was not found on the inventory.\n\n";

		}
	}

	else //Else if the user wants to look for the book by Title
	{
		string title;
		int position;
		cout << " Please insert the title of the book you want me to delete:\n\n ";
		cin.clear();
		cin.ignore(100, '\n');
		getline(cin, title);
		MenuItem::Sort(books, books.size(), "title");  //Call the member function of the base class that sorts the vector of books respect the title
		position = MenuItem::SearchName(books, title, books.size() - 1, 0); //Call the member function of the base class that search the title the user inserted
		
		//If the book is found in the vector display the information of the book 
		if (position != -1)
		{
			cout << endl << string(90, '-') << endl << endl;
			cout << " Information of the book\n\n";
			cout << books[position];
			cout << endl << endl << " ";

			string choice;
			cont = 0;
			
			//Ask the user if the book that was found is the one that he/she would like to delete 
			do
			{
				if (cont > 0)
				{
					cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
					cout << string(90, '-') << endl;
				}
				cout << "\n Is this the book you want to delete?. Enter 'Yes' or 'No':\n\n ";
				cin >> choice;
				cont++;
			} while ((choice != "Yes") && (choice != "No"));

			//If the user wants to delete the book that was found... Delete it
			if (choice == "Yes")
			{
				//If the book that the user wants to erase is in the last position of the vector erase the last position of the vector.
				if (position == (books.size() - 1))
					books.pop_back();
				else //Else, copy the information of the book that is in the last position of the vector in the position of the book that is going to be deleted and then erase the last position 
				{
					int last = books.size() - 1;
					books[position].setISBN(books[last].getISBN());
					books[position].setTitle(books[last].gettitle());
					books[position].setAuthor(books[last].getauthor());
					books[position].setPublisher(books[last].getpublisher());
					books[position].setDateadded(books[last].getdateadded());
					books[position].setQuantity(books[last].getquantity());
					books[position].setWholesale(books[last].getwholesale());
					books[position].setRetail(books[last].getretail());
					books.pop_back();
				}
			}
		}
		//Else if the book was not found tell the user
		else
		{
			cout << "\n\n The book of title: " << title << " was not found on the inventory.\n\n";
			
		}
	}
	cout << endl << string(90, '=') << endl << endl;
	cont = 0;

	//Ask the user if he/she would like to delete another book 
	do
	{
		if (cont > 0)
		{
			cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
			cout << string(90, '-') << endl << endl;
		}
		cout << " Would you like to delete another book? Enter 'Yes' or 'No':  ";
		cin >> chc;
		cont++;
	} while ((chc != "Yes") && (chc != "No"));
	cout << endl << endl;
	
	//If the user wants to delete another book, call this function again 
	if (chc == "Yes")
		Delete(books);
}
