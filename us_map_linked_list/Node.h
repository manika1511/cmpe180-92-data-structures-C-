#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A linked list node.
 */
class Node
{
public:
    Node();                        //default constructor
    Node(Coordinate coordinate);   //constructor for initialising node for Coordinate variable
    Node(City city);               //constructor for initialising node for City variable
    ~Node();                       //destructor

    string get_name() const;       //accessor function to get name
    string get_state() const;      //accessor function to get state
    int get_row() const;           //accessor function to get print row
    int get_col() const;           //accessor function to get print column

    // Public pointer to the next node in the list.
    Node *next;

    // Overloaded > operator.
    bool operator >(const Node& other);

    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, const Node& node);

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    int row;       // print row
    int col;       // print column

    void convert_coordinate(const Coordinate& coordinate);   //function to convert coordinate to print row and print col
};

#endif /* NODE_H_ */
