/*
 * Assignment 7: U.S. Maps
 * Author      : Manika Kapoor
 * Student ID  : 011539203
 */

#include "City.h"

/*
 * default constructor generates City (" ", " ", 0,0)
 */
City:: City()
{
	name = " ";
	state = " ";
	coordinate.set_latitude(0);
	coordinate.set_longitude(0);
}

/*
 * constructor to generate City (c_name, c_state, c_coordi(latitude), c_coordi(longitude))
 */
City:: City(string c_name, string c_state, Coordinate c_coordi)
{
	name = c_name;
	state = c_state;
	coordinate.set_latitude(c_coordi.get_latitude());
	coordinate.set_longitude(c_coordi.get_longitude());
}

City:: ~City()          //default destructor
{

}

string City:: get_name() const    //getter function to get name
{
	return name;
}

string City:: get_state() const   //getter function to get state
{
	return state;
}

Coordinate City:: get_coordinate() const  //getter function to get coordinate
{
	return coordinate;
}

/**
 * Overloaded >> operator used to input the City taking one row as input at a time
 * @param city: input City
 */
istream& operator >>(istream& ins, City& city)
{
	string name, state, lati, longi; //variable to store the name, state, latitude and longitude as strings

	getline(ins,name,',');     //reading name into name
	getline(ins,state,',');    //reading state into state
	getline(ins,lati,',');     //reading latitude into lati
	getline(ins,longi);        //reading longitude into longi

	double c_lati;             //variable to store lati as double
	double c_longi;            //variable to store longi as double

	//converting lati and longi into double
	c_lati = stod(lati);
	c_longi = stod(longi);

	//setting city name, state, latitude and longitude
	city.name = name;
	city.state = state;
	city.coordinate.set_latitude(c_lati);
	city.coordinate.set_longitude(c_longi);

	return ins;
}

/*
 * overloaded << operator to display city
 * @param city: input City
 */
ostream& operator <<(ostream& outs, const City& city)
{
	outs << "*" << city.get_name() << " " << city.get_state();
	return outs;
}
