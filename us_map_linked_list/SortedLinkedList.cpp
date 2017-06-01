#include <math.h>
#include <string>
#include "SortedLinkedList.h"

SortedLinkedList:: SortedLinkedList()     //default constructor
{
	head = nullptr;
}

SortedLinkedList:: ~SortedLinkedList()    //destructor
{
	delete head;
}

Node* SortedLinkedList:: get_head() const  //getter function to get pointer to the head of the list
{
	return head;
}
/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */
void SortedLinkedList::insert(Node *node)
{
	Node* temp;               //pointer to store current node
	Node* prev;               //pointer to store previous node

	if (head == nullptr)      //inserting node in the empty list
	{
		head = node;
		node->next = nullptr;
	}

	else if (*head > *node)  //inserting the node at the head of the list if node pointed by head is greater than the node to be inserted
	{
		node->next = head;
		head = node;
	}
	else                     //inserting node in the middle or end
	{
		temp = head;
		while(temp != nullptr && (*node) > (*temp))   //iterate through the list till the node to be inserted is greater then the list node
		{
			prev = temp;
			temp = temp->next;
		}
		//inserting the node before the greater node in the list
		prev->next = node;
		node->next = temp;
	}
}

/*
 * overloaded << operator
 * @param: takes list as input
 * outputs the list nodes in the required format and pattern
 */
ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
	Node* temp;              //pointer to store head

	//deleting the duplicate Coordinate type nodes
	temp = list.head;
	if (temp != nullptr)
	{
	    Node *temp_next;              //pointer pointing the next node

	    while (temp->next != nullptr)         //iterating through the list
	    {
	    	//deleting the next node if the current and next node both have same row and col
	    	if (temp->next->get_name() == " " && (temp->get_row() == temp->next->get_row()) && (temp->get_col() == temp->next->get_col()))
	    	{
	    		temp_next = temp->next->next;
	    		delete temp->next;
	    		temp->next = temp_next;
	    	}
	    	else
	    	{
	    		temp = temp->next;
	    	}
	    }
	}

	//deleting the coordinate type node if the City type node has the same row and col
	temp = list.head;
	if (temp != nullptr)
	{
		Node *temp_next;        //pointer to next node

		while (temp->next != nullptr)     //iterating through the loop
		{
			/*
			 * deleting the Coordinate type node if the current City node has the same row and col
			 * deleting the next city node if the current city node has the same row and col
			 */
		    if (temp->next->get_name() != " " && (temp->get_row() == temp->next->get_row()) && (temp->get_col() == temp->next->get_col()))
		    {
		    	temp_next = temp->next->next;
		    	delete temp->next;
		    	temp->next = temp_next;
		    }
		    else
		    {
		    	temp = temp->next;
		    }
		}
	}

	//deleting the next node if its col lies in the print length of the current city node as Western city is prefered for printing
	temp = list.head;
	if (temp != nullptr)
	{
		Node *temp_next;     //pointer to the next node

		while (temp->next != nullptr) //iterating through the list
		{
			if (temp->next->next != nullptr && temp->get_name() != " " && temp->get_row() == temp->next->get_row()) //if the consecutive nodes are cities
			{
				int n_len = temp->get_name().length();           //length of name string of current node
				int s_len = temp->get_state().length();          //length of state string of current node
				int total_len = n_len + s_len + 1;               //total length includes "*" in starting

				int diff = abs(temp->get_col() - temp->next->get_col());   //difference between the col of the two nodes
				if (diff <= (total_len))                        //delete the node if the difference is less than or equal to the toatal length
				{
					temp_next = temp->next->next;
					delete temp->next;
					temp->next = temp_next;
				}
				else
				{
					temp = temp->next;
				}
			}
			else
			{
			    temp = temp->next;
			}
		}
	}


	int matrix_row;    //variable to store the max row
	int matrix_col;    //variable to store the max col

	//calculating the max row
	temp = list.head;
	matrix_row = list.head->get_row(); //intialising matrix_row to the row of head node
	temp = temp->next;
	while(temp != nullptr)      //iterating through the list and replacing matrix_row with the row of the node if greater than the matrix_row
	{
		if (temp->get_row() > matrix_row)
		{
			matrix_row = temp->get_row();
		}
		temp = temp->next;
	}

	//calculating max col
	temp = list.head;
	matrix_col = list.head->get_col(); //intialising matrix_row to the col of head node
	temp = temp->next;
	while(temp != nullptr)     //iterating through the list and replacing matrix_col with the col of the node if greater than the matrix_col
	{
		if (temp->get_col() > matrix_col)
		{
			matrix_col = temp->get_col();
		}
		temp = temp->next;
	}

	//displaying nodes as per the required format(U.S. map)
	temp = list.head;
	int row, col;         //variables to iterate the row and col

	while(temp != nullptr)      //iterate through the list
	{
		temp = list.head;
		for(int i = 0; i < matrix_row+1; i++)   //loop for iterating through row
		{
			row = temp->get_row();           //storing row of current node

			int j = 0;                      //variable to iterate through col
			while(temp != nullptr && temp->get_row() == i)
			{
				col = temp->get_col();          //storing col of current node
				while(j != col && j < matrix_col+1)    //print " " till the column of matrix not equal to col of teh node
				{
					outs << " ";
					j++;
				}
				if (j == col)                    //printing the node when matrix column equals col of the node
				{
					if (temp->get_name() == " ") //print node if current node name is " "
					{
						outs << *temp;
						j++;                     //incrementing the matrix column to go to next column
					}
					else
					{
						//if the node name is not " " then print the node and then increase the matrix column by the length of the node printed
						outs << *temp;
						int len = temp->get_name().length() + temp->get_state().length() + 2;
						j  = j + len;
					}
				}
				temp = temp->next;
			}
			if (i != matrix_row)   //printing new line if the matrix row is not the last one
			{
				outs << endl;
			}
		}
	}

	return outs;
}
