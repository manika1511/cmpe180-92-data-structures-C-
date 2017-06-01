#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
//***Citation*** : http://cforbeginners.com/insertionsort.html
void InsertionSort::run_sort_algorithm() throw (string)
{
   int check, index; 
   for(check = 1; check < size; check++)
   {
      Element temp = data[check];    //storing element to be checked   
      index = check-1;               //index of previous element
      compare_count++;
      while((temp < data[index]) && (index >= 0)) //comapring with all the elements
      {
         compare_count++;
         data[index+1] = data[index];    //moves element forward
         move_count++;
         index--;
      }
      data[index+1] = temp;              //insert element in proper place
   }
}
