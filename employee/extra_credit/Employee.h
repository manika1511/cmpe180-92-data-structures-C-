//Header file containing class declaration

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <string>
using namespace std;

class Employee               //declaring Employee class
{
public:
    Employee();         //default constructor
    Employee(int a, string b, string c, double d);//constructor
    ~Employee();        //default destructor

    //accessor functions
    int get_id() const;
    string get_last() const;
    string get_first() const;
    double get_salary() const;

    //setter functions
    void set_id(int a);
    void set_last(string b);
    void set_first(string c);
    void set_salary(double d);

    friend ostream& operator <<(ostream& outs, Employee &e);
    //function to overload << operator

    friend istream& operator >>( istream& ins, Employee &e);
    //function to overload >> operator

private:
    int id;             //variable to store employee ID
    string last, first; //variables to store employee last and first name respectively
    double salary;      //variable to store employee salary
};

#endif  EMPLOYEE_H_
