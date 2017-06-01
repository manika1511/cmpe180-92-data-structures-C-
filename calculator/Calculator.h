/*
 * Assignment 10: Calculator
 * Author      : Manika Kapoor
 * Student ID  : 011539203
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

//Class to prompt for and evaluate arithmetic expressions, and print their results.
class Calculator
{
public:
	Calculator();          			 //default constructor does nothing
	Input get_user_input();  		 //function to get user input
	void print_output(Input result); //function to print the result
	Input expression();				 //function to evaluate single term or terms separated by + or -
	Input term();					 //function to evaluate single factor or factors separated by * or /
	Input factor();					 //function to evaluate expression within braces or single number
	Input get_next();                //function to read the next char in the user input
};

#endif /* CALCULATOR_H_ */
