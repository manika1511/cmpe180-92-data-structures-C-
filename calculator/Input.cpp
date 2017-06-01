/*
 * Assignment 10: Calculator
 * Author      : Manika Kapoor
 * Student ID  : 011539203
 */

#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include "Input.h"

using namespace std;

//default constructor sets input char to ' ' and input value to -1
Input:: Input()
{
	ch = ' ';
	value = -1;
}

//Constructor sets input char to c and input value to -1
Input::Input(char c)
{
	ch = c;
	value = -1;
}

//Constructor sets input char to ' ' and input value to d
Input:: Input(double d)
{
	ch = ' ';
	value = d;
}

//accessor function returns char part of input
char Input:: get_char() const
{
	return ch;
}

//accessor function returns value part of input
double Input:: get_value() const
{
	return value;
}

//setter function to set char part of input. Sets input ch to c
void Input:: set_char(char c)
{
	ch = c;
}

//setter function to set value part of input. Sets input value to d
void Input:: set_value(double d)
{
	value = d;
}

/*Overloaded = operator
 * Assigns the value of a to the calling input value and ch of a to calling input ch
 */
void Input:: operator = (const Input &a)
{
	ch = a.ch;
	value = a.value;
}

/*Overloaded + operator
 * Adds the value of a and b and assigns it to sum and also assigns b ch to sum ch
 * Returns sum
 */
Input operator +(Input a, Input b)
{
	Input sum;       //Input variable to store sum
	sum.value = a.value + b.value;
	a.ch = b.ch;
	sum.ch = b.ch;
	return sum;		//return sum
}

/*Overloaded - operator
 * Subtracts the value of b from a and assigns it to diff and also assigns b ch to diff ch
 * Returns diff
 */
Input operator -(Input a, Input b)
{
	Input diff;        //Input variable to store difference
	diff.value = a.value - b.value;
	a.ch = b.ch;
	diff.ch = b.ch;
	return diff;	  //return difference
}

/*Overloaded * operator
 * Multiplies the value of a and b and assigns it to product and also assigns b ch to product ch
 * Returns product
 */
Input operator *(Input a, Input b)
{
	Input product;       //Input variable to store product
	product.value = a.value * b.value;
	a.ch = b.ch;
	product.ch = b.ch;
	return product;		//return product
}

/*Overloaded / operator
 * Divides the value of a by b and assigns it to division and also assigns b ch to division ch
 * Returns division
 */
Input operator /(Input a, Input b)
{
	Input division;     //Input variable too store quotient

	//Displaying error if the denominator i.e. b value is zero and then returning an error Input variable with ch = 'e'
	if (b.value == 0)
	{
		cout << "Division by zero***" << endl;  //displaying error
		Input err;         						//declaring Input variable to store error
		err.ch = 'e';							//setting ch of err to 'e' to indicate that an error has alreading occurred
		return err;                             //return the Input err variable
	}

	//Perform division if no error occurred
	division.value = a.value / b.value;
	a.ch = b.ch;
	division.ch = b.ch;
	return division;           					//return division
}



