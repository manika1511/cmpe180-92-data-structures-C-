/*Assignment 3: Extra Credit (Prime Spiral- first element at top  left corner)
 * Author: Manika Kapoor
 * Student ID: 011539203
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

const int MAX_START = 50;   // maximum starting number

void do_prime_spiral(const int n, const int start);
//function to check the validity of the 2D-array size and the start number
//Precondition : The values of both parameters are put.
//Postcondition: If the 2D-vector has odd size and starting number <= MAX_START
//               then the function is valid else an Error message is displayed.

void make_spiral(vector<vector<int> >, int start);
//function to store the elements in spiral (clockwise) with starting number at the top left corner of the 2D-vector
//Precondition : A valid 2D-vector size and start number must be there
//Postcondition: The elements are stored in spiral (clockwise) fashion in the 2D-vector with start
//               number at the top left corner of the 2D-vector

vector<int> prime_vector(int n, int start);
//function to check whether the element is prime or not and then create a vector of primes
//Precondition : The total number (n^2) of elements to be checked and the starting value to be checked are there.
//Postcondition: A vector containing the prime numbers starting from start value till the n^2.

void print_prime_spiral(vector<vector<int> > matrix, vector<int> primes);
//function to print the spiral arrangement of elements in 2D-vector with primes replaced with "#" and composite numbers replaced with "."
//Precondition : The elements must stored in spiral (clockwise) fashion in the 2D-vector with start
//               number at the top left corner of the 2D-vector
//Postcondition: A spiral 2D-vector with primes replaced with "#" and composite numbers replaced with "."
//               is displayed on the screen



  /*
   *The main: Generate and print prime spirals of various sizes.
  */

int main()
{
    /*Function calls to check whether the entered parameters are resulting into valid 2D-vector and
     * starting number
    */

    do_prime_spiral(5, 1);
	do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
}

void do_prime_spiral(const int n, const int start)   //function to check the validity of the 2D-vector size and the start number
{
	vector<vector<int> > matrix(n, vector<int>(n));  //vector of 'n' vectors of size 'n'

	cout << "Prime spiral of size " << n << " starting at " << start;

	if ( n % 2 != 0 )
	{
		if ( start > 0 && start <= MAX_START )       //calling function make_spiral if the vector is valid
		{
			cout << "\n";
			cout << "\n";
			make_spiral(matrix, start);
		}
		else                                         //displaying error message if not valid vector
		{
			cout << "\n";
			cout << "***** ERROR: Starting value " << start << " < 1 or > 50 \n";
			cout << "\n";
		}

	}
	else                                             //displaying error message if not valid vector
	{
		cout << "\n";
		cout << "***** ERROR: Size " << n << " must be odd. \n";
		cout << "\n";
	}
}

void make_spiral(vector<vector<int> > matrix, int start)  //function to make the spiral (clockwise) with starting number at the top left corner of the 2D-vector
{
	int initial = start;                        //store the start value;
	int i=0;                                    //variable for row iteration
	int j=0;								    //variable for column iteration
	int n = matrix.size();                      //store matrix size
	int r = 0;		                            //variable to keep track of row from top
	int c = 0;                                  //variable to keep track of column from left
	int last_row = n;                           //variable to store number of rows
	int last_col = n;                           //variable to store number of columns

	/* Filling the matrix by first filling the first of the empty rows (i.e first row in the starting) and then incrementing the row tracker 'r'
	 * followed by filling the last column of the empty one's (i.e. last column in the starting) and then decreasing the 'last_col'. Then filling
	 * the last of the empty rows and then decrementing last_row and then filling the first of the empty columns and incrementing the column tracker 'c.
	 * Repeating these steps till the entire matrix is filled.
	*/

	while( i < n && j < n )
	{
		j=c;
		while(j<last_col)                       //filling the first row of the empty rows
		{
			matrix[r][j] = start;
			start++;
			j++;
		}
		r++;

		i = r;
		while(i<last_row)                       //filling the last column of the empty columns
		{
			matrix[i][last_col-1] = start;
			start++;
			i++;
		}
		last_col--;

		if (r<n)                                //filling the last row of the empty rows
		{
			j = last_col-1;
			while(j>=c)
			{
				matrix[last_row-1][j] = start;
				start++;
				j--;
			}
			last_row--;
		}

		if(c<n)                                  //filling the last column of the empty columns
		{
			i = last_row-1;
			while(i>=r)
			{
				matrix[i][c] = start;
				start++;
				i--;
			}
			c++;
		}
	}

	vector<int> primes = prime_vector(matrix.size(), initial); //storing primes vector
	print_prime_spiral(matrix,primes);                         //function call to print the spiral
}

vector<int> prime_vector (int n, int start) //function to check whether the element is prime or not and then create a vector of primes
{
	vector<int> primes;                     //vector to store primes
	int initial = start;                    //storing starting value
	for (int i=0; i < n*n; i++)             //filling primes vector with elements from start to n^2 where n is size of the 2D-vector
	{
		primes.push_back(start);
		start++;
	}

    /*Checking whether an element is prime or not by iterating the loop and setting all the elements that
     *are divisible by the element being checked to zero. Only non-zero elements are checked. After all the
     *elements are checked, all the composite numbers would have been set to zero.
    */

	for (int i = 0; i < primes.size(); i++)
	{
		if (primes[i]!=0)                   //checking non-zero elements
		{
			if (primes[i] == 1)             //if the element value is 1, set it to 0
			{
				primes[i]= 0;
				i++;
			}

			int num = primes[i];            //storing element to be checked in num
			int next = i+1;                 //storing the index of next element in variable next

			while (next < primes.size())
			{
				if (primes[next] % num == 0) //setting composite numbers to zero
				{
					primes[next] = 0;
				}
				next++;
			}
			int j = 2;
			while ( j < initial)             //dividing the element being checked by integers from 2 to (initial-1)
			{
				if (primes[i] % j == 0)      //setting the element to 0 if divisible
				{
					primes[i] = 0;
				}
				j++;
			}
		}
	}
	primes.erase(remove(primes.begin(), primes.end(), 0), primes.end()); //erasing elements with value 0
	return primes;
}

void print_prime_spiral(vector<vector<int> > matrix, vector<int> primes)//function to print the spiral arrangement of elements in 2D-vector with primes replaced with "#" and composite numbers replaced with "."
{
	int i, j;

	for ( i = 0; i< matrix.size(); i++)
	{
		for (j=0; j< matrix.size(); j++)
		{
		    int number = matrix[i][j];
			vector <int>::iterator i = primes.begin ();
			i = find(primes.begin (),primes.end (), number);     //checking whether the element in matrix vector exists in primes vector
			if (i != primes.end ())                              //printing "#" if exists in primes vector
			{
				cout << "#";
			}
			else                                                 //printing "." if doesn't exist in primes vector
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	cout << "\n";
}
