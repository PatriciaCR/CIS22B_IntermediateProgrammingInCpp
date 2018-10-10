// Specification file for the Inventory class
#ifndef INVENTORY_H
#define INVENTORY_H

#include<string>
#include "Book.h"
#include"MenuItem.h"
#include<vector>


class Inventory : public MenuItem
{
public:
	int displayMenu();
	void LookUp(vector<Book>&);
	void Add(vector<Book>&);
	void Edit(vector<Book>&);
	void Delete(vector<Book>&);
};
#endif