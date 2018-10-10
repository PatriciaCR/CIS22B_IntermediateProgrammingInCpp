// Specification file for the Report class
#ifndef REPORT_H
#define REPORT_H

#include<string>
#include "Book.h"
#include"MenuItem.h"
#include<vector>

class Report : public MenuItem
{
public:
	int displayMenu();
	void InventoryListing(vector<Book>&);
	void InventoryWholesale(vector<Book>&);
	void InventoryRetail(vector<Book>&);
	void ListingQuantity(vector<Book>&);
	void ListingCost(vector<Book>&);
	void ListingAge(vector<Book>&);
};
#endif