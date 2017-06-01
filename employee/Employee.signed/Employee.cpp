/* Assignment #6 : Employee Records
 * Author: Manika Kapoor
 * Student ID: 011539203
*/

//Employee.cpp file containing definations of class Employee member functions

#include "Employee.h"
#include <fstream>

Employee::Employee()      //default constructor
{
	id = 0;            //setting id to 0
	last = " ";        //setting last to blank
	first = " ";       //setting first to blank
	salary = 0;        //setting salary to 0
}

Employee::Employee(int a, string b, string c, double d) //contsructor
{
	id = a;           //setting id to a
	last = b;         //setting last to b
	first = c;        //setting first to c
	salary = d;       //setting salary to d
}

Employee::~Employee() //default destructor
{
	;
}

int Employee::get_id() const   //accessor function to get id
{
	return id;
}

string Employee::get_last() const //accessor function to get last name
{
	return last;
}

string Employee::get_first() const  //accessor function to get first name
{
	return first;
}

double Employee::get_salary() const //accessor function to get salary
{
	return salary;
}

void Employee::set_id(int a)    //setter function to set id
{
	id = a;
}

void Employee::set_last(string b) //setter function to set last name
{
	last = b;
}

void Employee::set_first(string c) //setter function to set first name
{
	first = c;
}

void Employee::set_salary(double d) //setter function to set salary
{
	salary = d;
}

istream& operator >>( istream& ins, Employee &e)  //function to overload >> operator
{
	string line;                //variable to store one line from input
	string v1, v2;              //variable to store id and salary as a string
	string last, first;         //variable to store last and first
	int id;                     //integer to store id
	double salary;              //double to store salary

	//storing comma separated values in variables v1,last,first and v2
	getline(ins, v1, ',');
	getline(ins, last, ',');
	getline(ins, first, ',');
	getline(ins,v2,',');

	id = stoi(v1);           //converting v1 string to integer and store it in id
	e.set_id(id);            //set employee id to id

	e.set_last(last);        //setting employee last name to last
	e.set_first(first);      //setting employee first  name to first

	salary = stod(v2);       //converting vr string to double and store it in salary
	e.set_salary(salary);    //setting employee salary to salary

	return ins;
}

ostream& operator << (ostream& outs, Employee &e)  //function to overload >> operator
{
	cout << "Employee{ID=" << e.get_id() << ", "  << "last=" << e.get_last() << ", " << "first=" << e.get_first() << ", " << "salary=" << e.get_salary() << "}" << endl;
	return outs;
}
