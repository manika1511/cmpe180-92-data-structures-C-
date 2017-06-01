#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
public:
    Coordinate();   //default constructor
    Coordinate(double lati, double longi);  //constructor
    ~Coordinate();   //default destructor

    double get_latitude() const;        //accessor function to get latitude
    double get_longitude() const;       //accessor function to get longitude

    void set_latitude(double lati);     //setter function to set latitude
    void set_longitude(double longi);   //setter function to set longitude

    // Overloaded input stream extraction operator.
    friend istream& operator >>(istream& ins, Coordinate& coordinate);

    // Constants for this app's input data.
    static const double MAX_LATITUDE;
    static const double MIN_LONGITUDE;

private:
    double latitude;         //variable to store latitude
    double longitude;        //variable to store longitude
};

#endif /* COORDINATE_H_ */
