#ifndef ABSVAL_H
#define ABSVAL_H

//Definition of the function template abs that calculates the absolute value of an element
template <class T>
T abs(T num)
{
	T Absolute; //Declares a variable of type T that will hold the absolute value of a number
	Absolute = num >=0 ? num : -num; //If the number is greater or equal to 0 Absolute=num else, Absolute=-num
	return Absolute; //Return Absolute
}

#endif