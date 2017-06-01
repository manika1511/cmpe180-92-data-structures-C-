/*
 *Assignment #12: Sorting Algorithms
 *Author        : Manika Kapoor
 *Student ID    : 011539203
*/
#include <iostream>
#include "Element.h"

using namespace std;

long Element::copy_count = 0;          //static variable to store copy constructor calls
long Element::destructor_count = 0;    //static variable to store copy constructor calls 

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
   value = other.value;
   copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
   destructor_count++;
}

//Accessor function returns copy_count
long Element:: get_copy_count()
{
   return copy_count;
}

//Accessor function returns destructor_count
long Element:: get_destructor_count()
{
   return destructor_count;
}

/*
*Function to reset the static variables.
*Sets constructor_count, copy_count, destructor_count to zero
*/
void Element:: reset()
{
   copy_count = 0;
   destructor_count = 0;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

/*
 *Overloaded = operator to compare two nodes
 */
void Element:: operator = (const Element &E)
{
   value = E.value;
}

/*
 *Overloaded > operator to compare two nodes
 *Returns true if value to be inserted is greater than or equal to the value in Node
 */
bool Element:: operator >(const Element& other) const
{
   if (value > other.value)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/*
 *Overloaded < operator to compare two nodes
 *Returns true if value to be inserted is greater than or equal to the value in Node
 */
bool Element:: operator <(const Element& other) const
{
   if (value < other.value)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/*
 *Overloaded << operator to compare two nodes
 *Returns true if value to be inserted is greater than or equal to the value in Node
 */
ostream& operator<<(ostream& outs, const Element& E)
{
   outs << E.value;
   return outs;
}
