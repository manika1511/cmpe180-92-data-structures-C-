/* Assignment #5 : Rational
 * Author: Manika Kapoor
 * Student ID: 011539203
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const string INPUT_FILE_NAME = "rational.in";  //input file used

//Class for Rational numbers

class Rational
{
public:
    Rational();
    //constructor
    //Postcondition: rational number initialized to (0/1)

    Rational(int x);
    //Constructor
    //Postcondition: rational number initialized to (x/1)

    Rational(int x, int y);
    //Constructor
    //Postcondition: rational number initialized to (x/y)

    int get_num()  const;
    //Returns the numerator (a) of the rational number

    int get_den() const;
    //Returns the denominator (b)  of the rational number

    void set_num(int x);
    //Function to set the value of numerator (a)
    //Postcondition: the numerator of rational number is set to value x

    void set_den(int y);
    //Function to set the denominator (b) of rational number
    //Postcondition: the denominator of rational number is set to value y

    friend Rational operator +(const Rational& r1, const Rational& r2);
    //friend function to overload the '+' operator
    //Postcondition: Addition of two rational numbers r1 and r2 can be done by calling (r1+r2)

    friend Rational operator -(const Rational& r1, const Rational& r2);
    //friend function to overload the '-' operator
    //Postcondition: Subtraction of two rational numbers r1 and r2 can be done by calling (r1-r2)

    friend Rational operator *(const Rational& r1, const Rational& r2);
    //friend function to overload the '*' operator
    //Postcondition: Product of two rational numbers r1 and r2 can be done by calling (r1*r2)

    friend Rational operator /(const Rational& r1, const Rational& r2);
    //friend function to overload the '/' operator
    //Postcondition: Division of two rational numbers r1 and r2 can be done by calling (r1/r2)

    friend ostream& operator <<(ostream& outs, const Rational& r);
    //friend function to overload the '<<' operator

    friend istream& operator >>(istream& outs, Rational& r);
    //friend function to overload the '>>' operator

private:
    int a, b;  // numerator and denominator of rational number
};

void do_problem(const Rational r1, const Rational r2, const char op);
//function to call evaluating function and printing the output
//Precondition : The rational numbers r1 and r2 and operator op ('+', '-', '*', '/') have been read
//Postcondition: Prints the output in required format (proper fraction)

Rational evaluate (Rational r1, Rational r2, const char op);
//function to evaluate the result of the operation op ('+', '-', '*', '/')
//Precondition : The rational numbers r1 and r2 and operator op have been read
//Postcondition: Returns the result of the operation

Rational reduced_fraction (Rational &r);
//function to convert a rational number into reduced fraction
//Precondition : rational number r is input
//Postcondition: the rational number r is converted into reduced fraction

int main()
{
    //Open the input file.
	ifstream input;                   //declaring input file stream
    input.open(INPUT_FILE_NAME);      //opening file INPUT_FILE_NAME
    if (input.fail())                 //condition to check whether the file is opened successfully or not
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl; //Displaying error message is file opening is unsuccessful
        return -1;
    }

    Rational r1, r2;       //variables to store two rational numbers
    char op;               //char variable to store operator op (+, -, *, /)
    char ch;               //char variable to check whether the end of file has reached or not

    //Reading file until end of file
    do
    {
        input >> r1 >> op >> r2;    //input rational numbers r1 & r2 and operator op

        do_problem(r1, r2, op);     //function call to evaluate and print the required output
        ch = input.peek();          //peeking into the next char
        if (ch == input.eof())      //checking for end of file and coming out of the loop if it is eof
        {
        	break;
        }
    }while (!input.eof());

    cout << endl << "Done!" << endl;
    return 0;
}

Rational::Rational() //Default constructor to initialize rational number to (0/1)
{
	a = 0;
	b = 1;
}

Rational::Rational(int x) //Constructor to initialize rational number to (x/1)
{
	a = x;
	b = 1;
}

Rational::Rational(int x, int y) //Constructor to initialize rational number to (x/y)
{
	a = x;
	b = y;
}

int Rational::get_num() const   //function to return value of numerator of rational number
{
	return a;
}

int Rational::get_den() const   //function to return value of denominator of the rational number
{
	return b;
}

void Rational::set_num(int x)   //function to set the numerator of rational number to value x
{
	a = x;
}

void Rational::set_den(int y)   //function to set the denominator of rational number to the value y
{
	b = y;
}

Rational operator +(const Rational& r1, const Rational& r2)  //friend function to overload the '+' operator
{
	int num_r1, num_r2;     //variables to store numerators of r1 and r2 respectively
	int den_r1, den_r2;     //variables to store denominators of r1 and r2 respectively
	Rational add;           //variable to store the result of addition
	int add_num, add_den;   //variables to store numerator and denominator of the add respectively

	//storing the numerator and  denominator of r1 & r2 using accessor functions
	num_r1 = r1.get_num();
	den_r1 = r1.get_den();
	num_r2 = r2.get_num();
	den_r2 = r2.get_den();

	add_num = ((num_r1*den_r2) + (den_r1*num_r2)); //calculating numerator of add
	add_den = (den_r1*den_r2);                     //calculating denominator of add

	//setting the numerator and denominator of add using setter functions
	add.set_num(add_num);
	add.set_den(add_den);

	return add;
}

Rational operator -(const Rational& r1, const Rational& r2) //friend function to overload the '-' operator
{
	int num_r1, num_r2;      //variables to store numerators of r1 and r2 respectively
	int den_r1, den_r2;      //variables to store denominators of r1 and r2 respectively
	Rational sub;            //variable to store the result of subtraction
	int sub_num, sub_den;    //variables to store numerator and denominator of the sub respectively

	//storing the numerator and  denominator of r1 & r2 using accessor functions
	num_r1 = r1.get_num();
	den_r1 = r1.get_den();
	num_r2 = r2.get_num();
	den_r2 = r2.get_den();

	sub_num = ((num_r1*den_r2) - (den_r1*num_r2)); //calculating numerator of sub
	sub_den = (den_r1*den_r2);                     //calculating denominator of sub

	//setting the numerator and denominator of sub using setter functions
	sub.set_num(sub_num);
	sub.set_den(sub_den);

	return sub;
}

Rational operator *(const Rational& r1, const Rational& r2)  //friend function to overload the '*' operator
{
	int num_r1, num_r2;     //variables to store numerators of r1 and r2 respectively
	int den_r1, den_r2;     //variables to store numerators of r1 and r2 respectively
	Rational mul;           //variable to store the result of multiplication
	int mul_num, mul_den;   //variables to store numerator and denominator of the product respectively

	//storing the numerator and  denominator of r1 & r2 using accessor functions
	num_r1 = r1.get_num();
	den_r1 = r1.get_den();
	num_r2 = r2.get_num();
	den_r2 = r2.get_den();

	mul_num = (num_r1*num_r2); //calculating numerator of mul
	mul_den = (den_r1*den_r2); //calculating numerator of mul

	//setting the numerator and denominator of mul using setter functions
	mul.set_num(mul_num);
	mul.set_den(mul_den);

	return mul;
}

Rational operator /(const Rational& r1, const Rational& r2)  //friend function to overload the '/' operator
{
	int num_r1, num_r2;    //variables to store numerators of r1 and r2 respectively
	int den_r1, den_r2;    //variables to store denominators of r1 and r2 respectively
	Rational div;          //variable to store the result of division
	int div_num, div_den;  //variables to store numerator and denominator of the division

	//storing the numerator and  denominator of r1 & r2 using accessor functions
	num_r1 = r1.get_num();
	den_r1 = r1.get_den();
	num_r2 = r2.get_num();
	den_r2 = r2.get_den();

	//calculating and setting the numerator and denominator of div
	if (num_r2 == 0)    //setting numerator of div to 0 and denominator to 1 if numerator of r2 is 0
	{
		div.set_num(0);
		div.set_den(1);
	}
	else
	{
		div_num = (num_r1*den_r2); //calculating numerator of div
		div_den = (den_r1*num_r2); //calculating denominator of div

		div.set_num(div_num);      //setting numerator of div using setter functions
		div.set_den(div_den);      //setting denominator of div using setter functions
	}

	return div;
}

ostream& operator <<(ostream& outs, const Rational& r) //friend function to overload the '<<' operator
{
	Rational result;                     //variable to store the rational number
	result.set_num(r.get_num());         //setting numerator of result to numerator of r
	result.set_den(r.get_den());         //setting denominator of result to denominator of r

	if (result.get_num() != 0)           //reducing the fraction if the numerator is not 0
	{
		result = reduced_fraction(result); //function call to convert fraction into reduced form
	}

	if (result.get_num() < result.get_den() && result.get_num() != 0 && result.get_den() != 1) //printing rational number of form (a/b) where a<b, a is not 0 and b is not 1
	{
		outs << "(" << result.get_num() << "/" << result.get_den() << ")";
	}
	else if(result.get_den() == 1 )  //printing rational number of form (a/b) where denominator is 1
	{
		cout << result.get_num();
	}
	else if (result.get_num() == 0) //printing rational number of form (a/b) where a = 0
	{
		cout << "0";
	}
	else          //printing rational number of form (a/b) where a>b i.e. printing mixed fraction
	{
		int num, den;  //variables to store the numerator and denominator of r
		int integer;   //variables to store the integer part of mixed fraction
		int num_res, den_res;  //variables to store the numerator and denominator of the mixed fraction

		//storing numerator and denominator of r using accessor functions
		num = result.get_num();
		den = result.get_den();

		//converting into mixed fraction
		integer = num / den;    //integer part is result of division of num and den
		num_res = num % den;    //numerator of fraction part of result is modulo of num and den
		den_res = den;          //denominator of fraction part of result is same as the denominator of r

		cout << integer << "(" << num_res << "/" << den << ")";
	}

	return outs;
}

istream& operator >>(istream& outs, Rational& r) //function to overload >> operator
{
	int den, num, a; //variables to store numerator, denominator & integer part of mixed fraction respectively
	char ch;         //char variable to iterate through each character
	outs >> ws;      //deleting any white space
	ch = outs.peek();//peeking the next character

	if (ch == '(')   // reading and storing a rational number of form (x/y)
	{
		outs >> ch;      //reading '('
		outs >> ws;
		outs >> num;     //reading numerator
		outs >> ws;
		outs >> ch;      //reading '/'
		outs >> ws;
		outs >> den;     //reading denominator
		outs >> ws;
		outs >> ch;      //reading ')'
		outs >> ws;

		ch = outs.peek(); //peeking next character

		if (ch == '=')    //condition to check whether next character is operator ('+', '-', '*', '/') or '='
		{
			outs >> ch;   //reading '='
		}

		r.set_num(num);   //setting the numerator of the rational number r to num
		r.set_den(den);   //setting the denominator of the rational number r to den

		return outs;
	}
	else                 //reading & storing a rational of form c(a/b) or a
	{
		outs >> a;       //reading the integer part of rational number
		outs >> ws;
		ch = outs.peek();//peeking the next character

		if (ch == '(')   //reading & storing the rational number of form c(a/b) (mixed fraction)
		{
			outs >> ch;  //reading '('
			outs >> ws;
			outs >> num; //reading the numerator part of fraction part
			outs >> ws;
			outs >> ch;  //reading '/'
			outs >> ws;
			outs >> den; //reading the denominator part of the fraction part
			outs >> ws;
			outs >> ch;  //reading ')'
			outs >> ws;

			ch = outs.peek(); //peeking next character

			if (ch == '=')   //condition to check whether next character is operator ('+', '-', '*', '/') or '='
			{
				outs >> ch;  //reading '='
			}

			//storing mixed fraction as an improper fraction (numerator > denominator)
			r.set_num((den*a)+num);  //setting the numerator of the rational number r
			r.set_den(den);          //setting the denominator of the rational number r

			return outs;
		}
		else                //Storing the integer as a fraction
		{
			ch = outs.peek(); //peeking next character

			if (ch == '=')  //condition to check whether next character is operator ('+', '-', '*', '/') or '='
			{
				outs >> ch; //reading '='
			}
			//storing integer as a fraction with denominator set to 1
			r.set_num(a);   //setting numerator as a
			r.set_den(1);   //setting denominator as 1

			return outs;
		}
	}
}

void do_problem(const Rational r1, const Rational r2, const char op) //function call to evaluate and print the required output
{

    Rational result = evaluate(r1, r2, op);                          //function call to evaluate the result

    cout << r1 << " " << op << " " << r2 << " = " << result << endl; //printing the output in required format
}

Rational evaluate (Rational r1, Rational r2,const char op)  //function to evaluate the result of the operation op
{
	Rational result;

	switch(op)
	{
	case '+':                     //case if the operation is addition
		{
			result = r1 + r2;
			break;
		}
	case '-':                    //case if operation is subtraction
		{
			result = r1 - r2;
			break;
		}
	case '*':
		{
			result = r1*r2;     //case if operation is multiplication
			break;
		}
	case '/':
		{
			result = r1/r2;     //case if operation is division
			break;
		}
	}

	return result;
}

Rational reduced_fraction (Rational &r) //function to convert a rational number into reduced fraction
{
	int num, den; //variables to store absolute values of numerator and denominator respectively of r
	int gcd;      //variables to store Greatest Common Divisor(gcd) of num and den
	int num_ori;  //variable to store numerator of r (this will not be modified)
	int den_ori;
	num_ori = r.get_num(); //storing numerator of r so that it can be used later
	den_ori = r.get_den();

	//storing absolute values of numerator and denominator of r
	num = abs(r.get_num());
	den = abs(r.get_den());

	if (den == 1)    //no need to calculate gcd if denominator is 1 and return the rational number as it is
	{
		return r;
	}
	else             //converting rational number into reduced fraction
	{
		//Calculating gcd of numerator and denominator
		while (num != den)
		{
			if (num > den)
			{
				num = num - den;
			}
			else
			{
			    den = den - num;
			}
		}
		gcd = num;

		num_ori = num_ori/num;  //dividing numerator of r by gcd
		r.set_num(num_ori);     //setting numerator of r to new numerator
		den_ori = den_ori/num;  //dividing denominator of r by gcd
		r.set_den(den_ori);     //setting denominator of r to new denominator

		return r;
	}
}


