// Specification file for the MenuItem class
#ifndef MENUITEM_H
#define MENUITEM_H
	
#include<string>
#include "Book.h"
#include<vector>

class MenuItem
{
public:
	virtual int displayMenu();
	int SearchISBN(vector<Book> & , string , int , int);
	int SearchName(vector<Book> &, string, int, int);
	void Sort(vector<Book> &, int, string);
};
#endif
