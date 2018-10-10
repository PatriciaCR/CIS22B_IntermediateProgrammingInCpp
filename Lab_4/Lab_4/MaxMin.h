#ifndef MAXMIN_H
#define MAXMIN_H

//Definition of the function template max that calculates, from 2 elements, which one is the maximum or the minimum
template <class T>
T max(T var1, T var2)
{
	T Maximum; //Declares a variable of type T that will hold the maximum value of the 2 elements
	Maximum = var1 > var2 ? var1 : var2; //If var1 is greater than var2 set Maximum=var1, else Maximum=var2
	return Maximum; //Return Maximum
}

//Definition of the function template min
template <class T>
T min(T var1, T var2)
{
	T Minimum; //Declares a variable oof type T that will hold the minimum value of the 2 elements
	Minimum = var1 < var2 ? var1 : var2; //If var1 is less than var2 set Minimum=var1, else Minimum=var2
	return Minimum; //Return Minimum
}
#endif