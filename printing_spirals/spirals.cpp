/* Assignment #3.b.: Spirals
 * Author: Manika Kapoor
 * Student ID: 011539203
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

void do_spiral(const int n, const int start);
//function to check the validity of the 2D-array size and the start number
//Precondition : The values of both parameters are put
//Postcondition: If the 2D-array has odd size <= MAX_SIZE and starting number <= MAX_START
//               then the function is valid else an Error message is displayed

void make_spiral(int matrix[MAX_SIZE][MAX_SIZE], int size, int start);
//function to store the elements in the spiral (anti-clockwise) arrangement with starting number at the center of the 2D-array
//Precondition : A valid 2D-array size and start number must be there
//Postcondition: The elements are stored in spiral (anti-clockwise) fashion in the 2D-array with start
//               number at the center of the 2D-array

void print_spiral(int matrix[MAX_SIZE][MAX_SIZE], int size);
//function to print the spiral arrangement of elements in 2D-array
//Precondition : The elements must stored in spiral (anti-clockwise) fashion in the 2D-array with start
//               number at the center of the 2D-array
//Postcondition: The spiral arrangement of elements in 2D-array is displayed on the screen

  /*
   * The main: Generate and print spirals of various sizes.
  */

int main()
{

    /* Function calls to check whether the entered parameters are resulting into valid 2D-array and
     * starting number
    */

    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}

void do_spiral(const int n, const int start)   //function to check the validity of the 2D-array size and the start number
{
	cout << "Spiral of size " << n << " starting at " << start;

	if ( n % 2 != 0 && start <= MAX_START )                          //calling function make_spiral only if the size is odd
	{
		int matrix[MAX_SIZE][MAX_SIZE];
		cout << "\n";
		cout << "\n";
		make_spiral(matrix, n, start);
	}
	else
	{
		cout << "\n";
		cout << "***** ERROR: Size " << n << " must be odd. \n";
		cout << "\n";
	}
}

void make_spiral(int matrix[MAX_SIZE][MAX_SIZE], int size, int start) //function to store elements in the spiral (anti-clockwise) arrangement with starting number at the center of the 2D-array
{
	int direction[2] = {0,1};                       //direction of motion (right) stored in direction array
	int i, j;                                       //variables to iterate 2D array
	int t_moves = 1;                                //total number of moves in one direction
	int moves=1;                                    //number of moves taken out of total moves
	int temp;                                       //Temporary variable used to swap the elements in direction array
	i = (size-1)/2;
	j = (size-1)/2;
	matrix[i][j] = start;                           //storing start at the center of the 2D-array


  /* Filling the array with elements in spiral(anti-clockwise) fashion by taking equal moves in two perpendicular
   * directions and then increasing the total number of moves by 1. Starting with moving right total moves 1 and then
   * changing the direction by 90 degrees counter-clockwise and then taking 1 move and then again changing
   * direction by 90degrees counter-clockwise and increasing total moves by 1.
  */
	while ( i < size && j < size && t_moves < size )
	{
		while (moves <= t_moves)                    //movement towards right
		{
			i = i+direction[0];                     //setting the index of element to be filled
			j = j+direction[1];                     //setting the index of element to be filled
			start++;
			matrix[i][j] = start;
			moves++;
		}

		temp = direction[0];                        //changing direction by 90degrees counter-clockwise
		direction[0] = -direction[1];
		direction[1] = temp;

		moves = 1;
		while (moves <= t_moves)                    //movement in another direction
		{
			i = i+direction[0];
			j = j+direction[1];
			start++;
			matrix[i][j] = start;
			moves++;
		}
		temp = direction[0];                        //changing direction by 90degrees counter-clockwise
		direction[0] = -direction[1];
		direction[1] = temp;
		moves = 1;
		t_moves++;
	}
	while (moves <= (t_moves-1))                    //filling the last row of the 2D-array
	{
		i = i+direction[0];
		j = j+direction[1];

		start++;
		matrix[i][j] = start;

		moves++;
	}

	print_spiral(matrix, size);                     //function call to print the spiral arrangement of elements in 2D-array
}

void print_spiral(int matrix[MAX_SIZE][MAX_SIZE], int size) //function to print the spiral arrangement of elements in 2D-array
{
	for ( int i = 0; i< size; i++)                              //printing 2D-array
	{
		for (int j=0; j< size; j++)
		{
			cout << right << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n";
}