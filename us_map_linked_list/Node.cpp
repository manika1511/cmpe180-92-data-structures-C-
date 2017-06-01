#include <math.h>
#include "Node.h"

Node:: Node()                            //default constructor creating node (" ", " ", 0, 0, nullptr)
{
	name = " ";
	state = " ";
	row = 0;
	col = 0;
	next = nullptr;
}

Node:: Node(Coordinate coordinate)      //constructor for initialising node for Coordinate variable
{
	convert_coordinate (coordinate);   //converting coordinate to row and col
	name = " ";
	state = " ";
	next = nullptr;
}

Node:: Node(City city)                 //constructor for initialising node for City variable
{
	convert_coordinate (city.get_coordinate()); //converting city coordinate to row and col
	name = city.get_name();
	state = city.get_state();
	next = nullptr;
}

Node:: ~Node()     //default destructor
{

}

string Node:: get_name() const        //getter function to get name
{
	return name;
}

string Node:: get_state() const      //getter function to get state
{
	return state;
}

int Node:: get_row() const           //getter function to get print row
{
	return row;
}

int Node:: get_col() const           //getter function to get print column
{
	return col;
}

ostream& operator <<(ostream& outs, const Node& node)           //operator << overloaded
{
	if (node.get_name() == " " && node.get_state() == " ")      //print "#" if name and state are empty strings
	{
		outs << "#";
	}
	if (node.get_name() != " " && node.get_state() != " ")      //print "*" + name + state if name and state are not empty strings
	{
		string out = "*" + node.get_name() + " " + node.get_state();
		outs << out;
	}
	return outs;
}

/**
 * Overloaded > operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator >(const Node &other)
{
	if (row > other.row)                  //compare the row. lesser row node comes first
	{
		return true;
	}
	else if (row == other.row)            //if rows are equal, compare columns
	{
		if (col > other.col)              //lesser column node comes first
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else                                  //row less than the other
	{
		return false;
	}
}


/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */
void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}



