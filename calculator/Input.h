/*
 * Assignment 10: Calculator
 * Author      : Manika Kapoor
 * Student ID  : 011539203
 */

#ifndef INPUT_H_
#define INPUT_H_

//Class to store the return type value containing one integer part and one char part to store the read char
class Input
{
public:
	Input();              //default constructor
	Input(char c);        //constructor
	Input(double d);      //constructor

	//Accessor and mutator functions to get and set the input private members
	char get_char() const;
	double get_value() const;
	void set_char(char c);
	void set_value(double d);

	friend Input operator +(Input a, Input b); //overloaded + operator to perform addition
	friend Input operator -(Input a, Input b); //overloaded - operator to perform subtraction
	friend Input operator *(Input a, Input b); //overloaded * operator to perform multiplication
	friend Input operator /(Input a, Input b); //overloaded / operator to perform division
	void operator = (const Input &a);          //overloaded = operator to perform assignment

private:
	char ch;              //variable to store read char
	double value;         //variable to store read value
};




#endif /* INPUT_H_ */
