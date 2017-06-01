#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

#include "Node.h"

/**
 * A singly-linked list of Node objects that is sorted
 * by the nodes' rows and columns.
 */
class SortedLinkedList
{
public:
    SortedLinkedList();     //default constructor
    ~SortedLinkedList();    //destructor

    Node* get_head() const; //getter function to get head

    void insert(Node *node);//function to insert the node in a sorted list

    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, const SortedLinkedList& list); //overloaded << operator

private:
    Node *head;  // pointer to the head of the linked list
};

#endif /* SORTEDLINKEDLIST_H_ */
