#ifndef TOTAL_H
#define TOTAL_H

//Definition of the function template total that calculates the running total of a serie of elements
template <class T>
T total(T arr[], int numit)
{
	T Total=T(); //Define a variable of type T that will hold the running total of the elements.
	for (int x = 0; x < numit; x++) //Goes through the array adding the elements
	{
		Total =Total+ arr[x]; //Calculate the running total of an array 
	}
	return Total; //Return running total
}
#endif