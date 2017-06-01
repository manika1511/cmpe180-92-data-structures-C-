#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/*
 * default constructor. Construct coordinate (0,0)
 */
Coordinate:: Coordinate()
{
	latitude = 0;
	longitude = 0;
}

/*
 * constructor. Construct coordinate (lati, longi)
 */
Coordinate:: Coordinate(double lati, double longi)       //constructor
{
	latitude = lati;
	longitude = longi;
}

Coordinate:: ~Coordinate()       //default destructor
{

}

double Coordinate:: get_latitude() const    //accessor function to get latitude
{
	return latitude;
}

double Coordinate:: get_longitude() const   //accessor function to get longitude
{
	return longitude;
}

void Coordinate:: set_latitude(double lati) //setter function to get latitude
{
	latitude = lati;
}

void Coordinate:: set_longitude(double longi) //setter function to get longitude
{
	longitude = longi;
}

/**
 * Overloaded >> input stream extraction operator to read a coordinate,
 * one value per input line.
 */
istream& operator >>(istream& ins, Coordinate& coordinate)
{
	string lati, longi;        //variables to store latitude and longitude read as string

	getline(ins,lati,',');     //reading latitude into lati
	getline(ins,longi);        //reading longitude into longi

	double c_lati;             //variable to store latitude as double
	double c_longi;            //variable to store longitude as double

	c_lati = stod(lati);       //converting lati(string) to double
	c_longi = stod(longi);     //converting longi(string) to double

	//Setting latitude and longitude of coordinate
	coordinate.latitude = c_lati;
	coordinate.longitude = c_longi;

	return ins;
}

