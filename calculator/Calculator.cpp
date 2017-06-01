/*
 * Assignment 10: Calculator
 * Author      : Manika Kapoor
 * Student ID  : 011539203
 */

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <iomanip>
#include "Input.h"
#include "Calculator.h"

using namespace std;

static istringstream ins;   //static istream variable to read in user input
static int count_o = 0;     //static variable to count number of open braces
static int count_c = 0;     //static variable to count number of closed braces

//default constructor does nothing
Calculator:: Calculator()
{

}

/*function to get user input and call the expression function to
 * evaluate and then calls print function to print the output
 */
Input Calculator:: get_user_input()
{
	string s;
	cout << "Expression? " << endl;
	getline(cin,s);                 //taking user input
	if (s == "exit" || s == "Exit") //exit if the user wants to exit
	{
		Input done;					//declare an Input variable
		done.set_char('d');			//set its char part to 'd' indicating the user wants to exit
		return done;				//return Input done
	}
	ins.str(s);						//setting the static istringstream variable to s
	Input result = expression();    //storing the result of evaluation in result
	print_output(result);           //printing the result
}


//function to print the result of evaluation
void Calculator:: print_output(Input result)
{
	if (count_o < count_c)
	{
		cout << "Unexpected Extra ')' ***" << endl;  //displaying error message if the number of closing braces > number of opening braces
	}
	else if (count_o > count_c)
	{
		cout << "Missing closing braces***" << endl; //displaying error message if the number of closing braces < number of opening braces
	}
	else if ((result.get_char()  != 'e') && (result.get_char() == '=' || result.get_char() == ')')) //printing the result if the value is not error input containing ch as 'e'
	{
		cout << result.get_value() << endl;
	}
	count_o = 0;                //setting static variable count_o to 0
	count_c = 0;				//setting static variable count_c to 0
	cout << endl;
}

//function to read the characters of user input one by one
Input Calculator:: get_next()
{
	char ch;
	ins >> ws;            //reading any whitespaces
	ch = ins.peek();     //peeking the next character
	ins >> ws;
	if (isdigit(ch))     //input the double value if it is a digit
	{
		double value;
		ins >> ws;
		ins >> value;
		Input in(value); //setting an Input variable in with value as value and ch as ' '
		return in;       //return in
	}
	else
	{
		//read the character in char variable only if it either +, -, *, /, (, ), =
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=')
		{
			ins >> ws;
			ins >> ch;
			if (ch == '(')    //increment count_o if ch = ')'
			{
				count_o++;
			}
			else if (ch == ')') //increment count_c if ch = '('
			{
				count_c++;
			}
			Input in(ch);      //setting an Input variable in with ch as ch
			return in;         //return in
		}
		else   //if any other char is there display the error message
		{
			if(!ins.eof())
			{
				cout << "****Unexpected " << ch << endl; //display error message
				Input err;           //declare an error Input variable
 				err.set_char('e');   //set ch of err to 'e' to indicate that error has occurred
				return err;          //return the error Input variable
			}
		}
	}
}

//function to evaluate single term or terms separated by + or -
Input Calculator:: expression()
{
	Input in, val;              //variables to store Input type value

	val = term();               //function call to term

	if (val.get_char() == 'e')  //return the Input val if the ch is 'e' as it indicates error has occurred
	{
		return val;
	}
	if (val.get_char() == ' ')  //reading the next character in user input in Input in only if it has not already been read
	{
		in = get_next();
	}
	else                        //if it has already been read then set the ch of Input in to the already read char
	{
		in.set_char(val.get_char());
	}

	if (in.get_char() == '+')   //performing addition if ch is +
	{
		val = val + term();     //add the terms and call term function to extract factors and number if any

		if(val.get_char() == 'e') //check if the resultant Input val has ch as 'e' which indicates error has occurred
		{
			return val;          //return the value if error has occurred to stop further processing
		}

		//check next character in user input if the '=' has not been read
		while (val.get_char() != '=' && (val.get_char() == '+' || val.get_char() == '-'))
		{
			if (val.get_char() == '+') //add next term if there is + character
			{
				val = val + term();
			}
			else if (val.get_char() == '-') // subtract next term if there is - character
			{
				val = val - term();
			}
			if (val.get_char() == 'e')   //if the resultant val has ch as 'e' return it as error has occurred
			{
				return val;
			}
		}
	}
	else if (in.get_char() == '-')		//performing subtraction if ch is -
	{
		val = val - term();			  	//subtract the terms and call term function to extract factors and number if any

		if (val.get_char() == 'e')		//return the Input val if the ch is 'e' as it indicates error has occurred
		{
			return val;
		}

		//check next character in user input if the '=' has not been read
		while (val.get_char() != '=' && (val.get_char() == '+' || val.get_char() == '-'))
		{
			if (val.get_char() == '+')  //add next term if there is + character
			{
				val = val + term();
			}
			else if (val.get_char() == '-') // subtract next term if there is - character
			{
				val = val - term();
			}
			if (val.get_char() == 'e')  //if the resultant val has ch as 'e' return it as error has occurred
			{
				return val;
			}
		}
	}
	else     //set the ch of the val to the read character if the read character is neither '+' nor '-'
	{
		val.set_char(in.get_char());
	}
	return val;
}

//function to evaluate single factor or factors separated by * or /
Input Calculator:: term()
{
	Input val = factor();  //function call to term
	Input in;

	if (val.get_char() == 'e')   //return the Input val if the ch is 'e' as it indicates error has occurred
	{
		return val;
	}
	if (val.get_char() == ' ' || val.get_char() != '=') //reading the next character in user input in Input in only if it has not already been read
	{
		in = get_next();
	}
	else   							//if it has already been read then set the ch of Input in to the already read char
	{
		in.set_char(val.get_char());
	}

	if (in.get_char() == '*')		//performing multiplication if ch is *
	{
		val = val * factor();		//multiply the factors and call factor function to extract factors or numbers if any

		if (val.get_char() == 'e')	//check if the resultant Input val has ch as 'e' which indicates error has occurred
		{
			return val;
		}

		Input i = get_next();       //read the next character in user input

		if (i.get_char() == 'e')	//check if the resultant Input val has ch as 'e' which indicates error has occurred
		{
			return i;
		}

		if (i.get_char() == '*' || i.get_char() == '/') //perform multiplication or division if read char has ch * or / respectively
		{
			if (i.get_char() == '*')		//multiply next term if there is * character
			{
				val = val * factor();
			}
			else
			{
				val = val / factor();      //multiply next term if there is * character
			}
			if (val.get_char() == 'e')		//check if the resultant Input val has ch as 'e' which indicates error has occurred
			{
				return val;
			}
		}
		else
		{
			val.set_char(i.get_char());		//set the ch of the val to the read character if the read character is neither '*' nor '/'
		}
	}
	else if (in.get_char() == '/')
	{
		val = val / factor();     //performing division if ch is /

		if (val.get_char() == 'e') //check if the resultant Input val has ch as 'e' which indicates error has occurred
		{
			return val;
		}

		Input i = get_next();		//read the next character in user input

		if (i.get_char() == 'e')	//check if the resultant Input val has ch as 'e' which indicates error has occurred
		{
			return i;
		}
		if (i.get_char() == '*' || i.get_char() == '/') //perform multiplication or division if read char has ch * or / respectively
		{
			if (i.get_char() == '*') //multiply next term if there is * character
			{
				val = val * factor();
			}
			else
			{
				val = val / factor(); //multiply next term if there is * character
			}
			if (val.get_char() == 'e')
			{
				return val;
			}
		}
		else
		{
			val.set_char(i.get_char()); //check if the resultant Input val has ch as 'e' which indicates error has occurred
		}
	}
	else
	{
		val.set_char(in.get_char()); //set the ch of the val to the read character if the read character is neither '*' nor '/'
	}
	return val;
}

//function to evaluate expression within braces or single number
Input Calculator:: factor()
{
	Input val;
	Input in;
	val = get_next();      //read a character from user input

	if (val.get_char() == 'e') //check if the resultant Input val has ch as 'e' which indicates error has occurred
	{
		return val;
	}
	if (val.get_char() == '(') //if the read Input value has ch '(' it idicates that it is an expression
	{
		val = expression();		//function call to evaluate expression between braces

		if (val.get_char() == 'e') //check if the resultant Input val has ch as 'e' which indicates error has occurred
		{
			return val;
		}
		if (val.get_char() == ' ') //read the next value if it has not already been read
		{
			in = get_next();
		}
		else    					//set the ch of val to the ch of next value if the next value has already been read
		{
			in.set_char(val.get_char());
		}
		if (in.get_char() == ')')   //if the read Input in ch is ')' indicates that the expression is evaluated
		{
			val.set_char(in.get_char());
		}
	}
	return val; 					//return the resultant value
}



