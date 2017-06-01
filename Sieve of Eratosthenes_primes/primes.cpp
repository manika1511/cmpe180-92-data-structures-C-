/* Assignment #3.a.: Prime Numbers
 * Author: Manika Kapoor
 * Student ID: 011539203
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

void compute_primes(int numbers[], int size);
//function to compute whether a number is prime or not
//Precondition : The user must have entered the numbers to be checked in an array (maximum number not more than MAX_NUMBER).
//Postcondition: All the composite numbers are set to zero so that only prime numbers are there in the array.

void print_primes (int numbers[], int size);
//function to print the prime numbers
//Preconditions : All the composite numbers in the input array must be set to 0.
//Postcondition : All the elements not equal to 0 are printed i.e. all the prime numbers are printed
//                only constant ROW_SIZE numbers per row.

 /*
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
	int numbers[MAX_NUMBER];                 //array to store the numbers to be checked for prime
	int start = 2;                           //first number to be filled in the array
	for (int i=0; i < MAX_NUMBER; i++)           //filling array with numbers from start to MAX_NUMBER
	{
		numbers[i] = start;
		start++;
	}
	compute_primes(numbers, MAX_NUMBER);     //function call to determine which elements are prime in the array
	return 0;
}

void compute_primes(int numbers[], int size) //function to compute whether a number is prime or not
{
	int num;                                 //variable to store the array element to be checked
	int next;                                //variable to store the index of the element next to the element being checked

	/*Checking whether an element is prime or not by iterating the loop and setting all the elements that
	 *are divisible by the element being checked to zero. Only non-zero elements are checked. After all the
	 *elements are checked, all the composite numbers would have been set to zero.
	 */
	 
	for (int i=0; i<size; i++)
	{
		if (numbers[i]!=0)
		{
			num = numbers[i];                //storing element to be checked in num
			next = i+1;                      //storing the index of next element in variable next
			while (next < size)
			{
				if (numbers[next] % num == 0)
				{
					numbers[next] = 0;       //setting composite numbers to zero
				}
				next++;
			}
		}
	}
	print_primes(numbers,size);              //function call to print the prime numbers
}

void print_primes (int numbers[], int size)  //function to print the prime numbers
{
	int count = 0;                           //variable to store the number of elements being printed
	for (int i = 0; i < MAX_NUMBER; i++)
	{
		if (numbers[i]!=0 && numbers[i] < MAX_NUMBER) //printing only non-zero numbers less than MAX_NUMBER
		{
			count++;

			if(count % ROW_SIZE !=0)         //printing only ROW_SIZE numbers per row
			{
				cout << setw(4) << right << numbers[i];
			}
			else
			{
				cout << setw(4) << right << numbers[i];
				cout << "\n";
			}
		}
	}

	cout << "\n";
	cout << "\n";
	cout << "Done!";
}