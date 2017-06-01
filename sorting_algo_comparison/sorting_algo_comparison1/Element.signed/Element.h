#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
   Element();                      //default constructor
   Element(long val);              //constructor   
   Element(const Element& other);  //copy constructor
   virtual ~Element();             //default destructor
   
   long get_value() const;         //getter function to get value
   
   void operator = (const Element &E );         //overloaded = operator
   bool operator >(const Element& other) const; //overloaded > operator 
   bool operator <(const Element& other) const; //overloaded < operator
   friend ostream& operator<<(ostream& outs, const Element& E); //overloaded << operator
   
   // Access and reset the values of the static member variables.
   static long get_copy_count();
   static long get_destructor_count();
   static void reset();
   
private:
   long value;
   // Static member variables, which are global to the class.
   // These variables exist independently from any Node objects.
   static long copy_count;
   static long destructor_count;
};

#endif /* DATA_H_ */
