#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
   Node(const Element the_value); //Constructor
   Node(const Node& other);       //Copy Constructor
   virtual ~Node();               //destructor
   Element get_value() const;     //accessor function to access the value in node
   Node* next;                    //pointer pointing to the next Node of the list
   Element element;               //variable which is a part of Node
};

#endif /* NODE_H_ */
