#define _CRT_SECURE_NO_WARNINGS

// Implementation file for the MenuItem class.
#include"MenuItem.h"

int MenuItem::displayMenu() //Display Main Menu and gets and validates the choice of the user.
{
	int choice;
	cout << string(60,'=')<<endl<<endl;
	cout <<"\t\t  Serendipity Booksellers\n\n";
	cout << "\t\t\t Main Menu\n\n";
	cout << string(60, '=')<<endl<<endl; 
	cout << "  1)Cashier Module\n\n";
	cout << "  2)Inventory Database Module\n\n";
	cout << "  3)Report Module\n\n";
	cout << "  4)Exit the program\n\n";
	cout << string(60, '=') << endl<<endl;
	int count = 0;
	do
	{
		if (count > 0)
		{
			cout << "\n You did not enter a correct value for your choice, try again\n\n";
			cout << string(60, '-')<<endl<<endl;
		}
		cout << " Please enter the number of your choice: ";
		cin >> choice;
		count++;
	} while ((choice > 4) || (choice < 1));
	cout << "\n\n You selected item " << choice<<endl<<endl;
	cout << string(60, '-') << endl<<endl;
		if (choice == 1)
			cout << "Redirecting to the Cashier module.\n\n";
		else if (choice==2)
			cout << "Redirecting to the Inventory module.\n\n";
		else if (choice == 3)
			cout << "Redirecting to the Report module.\n\n";
		else
			cout << "Thank you for using the Serendipity Bookstore POS.\n\n";
		system("pause");
	return choice;
}
int MenuItem::SearchISBN(vector<Book> &books, string value, int last, int first) //Function that search the ISBN that the user inserted using a Binary Search algorithm and a recursive function
{
	int middle = (last + first) / 2; // Middle position

	if (books[middle].getISBN() == value) // If value is found at the middle position is equal to the ISBN the user inserted then return middle;
		return middle;

	//If the number found in the middle position is greater than the ISBN inserted by the user then last=middle-1, else last will stay the same
	last = books[middle].getISBN() > value ? middle - 1 : last;
	//If the number found in the middle position is less or equal than the ISBN inserted by the user then last=middle+1, else first will stay the same
	first = books[middle].getISBN() < value ? middle + 1 : first;

	//if first is not less or equal to last return -1 else call the function again
	return !(first <= last) ? -1 : SearchISBN(books, value, last, first); //Return the position where the book was found
}
int MenuItem::SearchName(vector<Book> &books, string value, int last, int first) //Function that search the title that the user inserted using a Binary Search algorithm and a recursive function
{
	int middle = (last + first) / 2; // Middle position

	if (books[middle].gettitle() == value) // If value is found at the middle position is equal to the word the user inserted then return middle;
		return middle;

	//If the number found in the middle position is greater than the word inserted by the user then last=middle-1, else last will stay the same
	last = books[middle].gettitle() > value ? middle - 1 : last;
	//If the number found in the middle position is less or equal than the value inserted by the user then last=middle+1, else first will stay the same
	first = books[middle].gettitle() < value ? middle + 1 : first;

	//if first is not less or equal to last return -1 else call the function again
	return !(first <= last) ? -1 : SearchName(books, value, last, first); //Return the position where the book was found
}
void MenuItem::Sort(vector<Book> & books, int size, string type) //Sorts the vector in descending or ascending order according to the variable:type using a selection sort algorithm and a recursive function
{
	
	int maxIndex = 0;
	int index = 0;

	if (type == "isbn")
	{
		for (index = maxIndex; index < size; index++) //Goes through the vector and look for the biggest element 
		{
			if (books[index].getISBN() > books[maxIndex].getISBN()) //Compares every element of the array with the element in the position maxIndex
				maxIndex = index; //If it is greater maxIndex will take the value of the position of the element	
		}
	}
	if (type == "title")
	{
		for (index = maxIndex; index < size; index++) //Goes through the vector and look for the biggest element 
		{
			if (books[index].gettitle() > books[maxIndex].gettitle()) //Compares every element of the array with the element in the position maxIndex
				maxIndex = index; //If it is greater maxIndex will take the value of the position of the element	
		}
	}
	if (type == "retail")
	{
		for (index = maxIndex; index < size; index++) //Goes through the vector and look for the smallest element 
		{
			if (books[index].getretail() < books[maxIndex].getretail()) //Compares every element of the array with the element in the position maxIndex
				maxIndex = index; //If it is smaller maxIndex will take the value of the position of the element	
		}
	}
	if (type == "quantity")
	{
		for (index = maxIndex; index < size; index++) //Goes through the vector and look for the smallest element 
		{
			if (books[index].getquantity() <books[maxIndex].getquantity()) //Compares every element of the array with the element in the position maxIndex
				maxIndex = index; //If it is smaller maxIndex will take the value of the position of the element	
		}
	}
	if (type == "date")
	{
		for (index = maxIndex; index < size; index++) //Goes through the vector and look for the smallest element 
		{
			if (books[index].getdateadded() <books[maxIndex].getdateadded()) //Compares every element of the array with the element in the position maxIndex
				maxIndex = index; //If it is smaller maxIndex will take the value of the position of the element	
		}
	}
	
	//Swap the element in the last position of the vector with the smallest element of the vector.
	int temp;
	
	
	temp = books[size - 1].getquantity(); 
	books[size - 1].setQuantity(books[maxIndex].getquantity());
	books[maxIndex].setQuantity(temp);

	
	string temp1;
	temp1 = books[size - 1].getISBN();
	books[size - 1].setISBN(books[maxIndex].getISBN());
	books[maxIndex].setISBN(temp1);
	
	temp1 = books[size - 1].gettitle();
	books[size - 1].setTitle(books[maxIndex].gettitle());
	books[maxIndex].setTitle(temp1);

	temp1 = books[size - 1].getauthor();
	books[size - 1].setAuthor(books[maxIndex].getauthor());
	books[maxIndex].setAuthor(temp1);
	
	temp1 = books[size - 1].getpublisher();
	books[size - 1].setPublisher(books[maxIndex].getpublisher());
	books[maxIndex].setPublisher(temp1);
	
	temp1 = books[size - 1].getdateadded();
	books[size - 1].setDateadded(books[maxIndex].getdateadded());
	books[maxIndex].setDateadded(temp1);

	double temp2;
	
	temp2 = books[size - 1].getwholesale();
	books[size - 1].setWholesale(books[maxIndex].getwholesale());
	books[maxIndex].setWholesale(temp2);

	temp2 = books[size - 1].getretail();
	books[size - 1].setRetail(books[maxIndex].getretail());
	books[maxIndex].setRetail(temp2);

	if (size > 1) //If the size of the vector is more than 1, call this function again 
	{
		Sort(books, --size, type);
	}
}

