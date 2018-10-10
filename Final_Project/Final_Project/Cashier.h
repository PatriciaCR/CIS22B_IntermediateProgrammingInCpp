// Specification file for the Cashier class
#ifndef CASHIER_H
#define CASHIER_H

#include<string>
#include"MenuItem.h"
#include "Book.h"
#include<vector>

class Cashier: public MenuItem
{
public:
	int displayMenu();
	void addbyISBN(vector<Book> &,vector<Book> &);
	void addbyTitle(vector<Book> &, vector<Book> &);
	void printreceipt(vector<Book>&);
};
#endif