#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:
    City();            //default constructor
    City(string c_name, string c_state, Coordinate c_coordi); //constructor
    ~City();           //default destructor

    string get_name() const;       //gettter function to get name
    string get_state() const;      //getter function to get state
    Coordinate get_coordinate() const;//getter function to get coordinate

    // Overloaded stream I/O operators.
    friend ostream& operator <<(ostream& outs, const City& city);
    friend istream& operator >>(istream& ins, City& city);

private:
    string name;      //variable to store name
    string state;     //variable to store state
    Coordinate coordinate; //variable to store coordinate
};

#endif /* CITY_H_ */
