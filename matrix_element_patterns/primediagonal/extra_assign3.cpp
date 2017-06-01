/* Assignment 3.: Extra Credit - Prime Diagonal
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

void do_prime_diagonal(const int n, const int start);
//function to check the validity of the 2D-vector size and the start number
//Precondition : The values of both parameters are put.
//Postcondition: If the 2D-vector has odd size and starting number <= MAX_START
//               then the function is valid else an Error message is displayed.

void make_diagonal(vector<vector<int> >, int start);
//function to input the elements in diagonal fashion in 2D-vector with first element at top left corner
//Precondition : A valid 2D-vector size and start number must be there
//Postcondition: The elements are stored in diagonal fashion with first element at the top left corner

vector<int> prime_vector(int n, int start);
//function to check whether the element is prime or not and then create a vector of primes
//Precondition : The total number (n^2) of elements to be checked and the starting value to be checked are there.
//Postcondition: A vector containing the prime numbers starting from start value till the n^2.

void print_prime_diagonal(vector<vector<int> > matrix, vector<int> primes);
//function to print the diagonal arrangement of elements in 2D-vector with primes replaced with "#" and
//composite numbers replaced with "."
//Precondition : The elements must stored in diagonal fashion in the 2D-vector with start
//               number at the top left corner of the 2D-vector
//Postcondition: A diagonal 2D-vector with primes replaced with "#" and composite numbers replaced with "."
//               is displayed on the screen

  /*
   *The main: Generate and print prime spirals of various sizes.
  */

int main()
{
    /*Function calls to check whether the entered parameters are resulting into valid 2D-vector and
     * starting number
    */

    do_prime_diagonal(5, 1);
    do_prime_diagonal(25, 11);
    do_prime_diagonal(35, 0);
    do_prime_diagonal(50, 31);
    do_prime_diagonal(101, 41);
}

void do_prime_diagonal(const int n, const int start)   //function to check the validity of the 2D-vector size and the start number
{
	vector<vector<int> > matrix(n, vector<int>(n));  //vector of 'n' vectors of size 'n'

	cout << "Prime spiral of size " << n << " starting at " << start;

	if ( n % 2 != 0 )
	{
		if ( start > 0 && start <= MAX_START )       //calling function make_diagonal if the vector is valid
		{
			cout << "\n";
			cout << "\n";
			make_diagonal(matrix, start);
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

void make_diagonal(vector<vector<int> > matrix, int start)  //function to store elements in diagonal fashion with starting number at the top left corner of 2D-vector
{
	int initial = start;                             //variable to store start value
	int i=0, j=0;

	matrix[i][j] = start;                            //storing start value in the top left corner(first element of 2D-vector)
	start++;

	/* storing elements in 2D vector in diagonal fashion by decrementing i and incrementing j */

	for ( i = 1; i < matrix.size(); i++)
	{
		int temp = i;                          //temporary variable to store row value i
		j = 0;
		while (j <= temp)                      //storing value in a diagonal
		{
			matrix[i][j] = start;
			start++;
			i--;
			j++;
		}
		i = temp;                              //storing temp value to i
	}

	for ( j = 1; j < matrix.size(); j++)       //loop to store elements in element after the longest diagonal is filled
	{
		i = matrix.size() - 1;                 //value of i (last row)
		int temp = j;

		while ( j < matrix.size())
		{
			matrix[i][j] = start;
			start++;
			i--;
			j++;
		}
		j = temp;
	}

	vector<int> primes = prime_vector(matrix.size(), initial); //storing primes vector
	print_prime_diagonal(matrix,primes);                       //function call to print the diagonal arrangement of elements
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

void print_prime_diagonal(vector<vector<int> > matrix, vector<int> primes)//function to print the diagonal 2D-vector with primes replaced with "#" and composite numbers replaced with "."
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



