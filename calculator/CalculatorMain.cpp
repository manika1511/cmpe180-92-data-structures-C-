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
#include "Calculator.h"

using namespace std;

//main program to ask for user input
int main()
{
	Calculator c; 					//Calculator variable
	int number = 1;					//integer variable sets to 0 when quit
	while(number != 0)				//take user inputs while number is not equal to 0
	{
		Input done = c.get_user_input(); //taking user input
		if (done.get_char() == 'd')		 //check the char part of done, if it is 'd', the user wants to exit print "Done!" and exit.
		{
			cout << "Done!" << endl;
			number = 0;
		}
	}
}





