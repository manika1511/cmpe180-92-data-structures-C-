#include "Node.h"
#include "Element.h"

//Constructor sets value to the_value and increases constructor_count by 1
Node:: Node(const Element the_value)
{
   element = the_value;
   next = nullptr;
}

//Copy Constructor 
Node:: Node(const Node& other)
{
   element = other.element;
   next = nullptr;
}

//Destructor increments destructor_count by 1
Node:: ~Node()
{

}

//Accessor function returns value
Element Node:: get_value() const
{
   return element;
}
