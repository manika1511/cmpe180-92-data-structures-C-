#include "ShellSortOptimal.h"
#include "VectorSorter.h"
#include "Sorter.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
 //***Citation: Data Structures using C++ by D.S. Malik
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
   int inc;
   //finding the biggest increment to start using Don Kuth's algorithm
   for (inc = 1; inc < (size-1)/9; inc = 3*inc+1);
   
   int increment;
   for (increment = inc; increment > 0; increment = increment/3)
   {
      compare_count++;
      
      for (int i = increment; i < size; i++)
      {
         Element temp = data[i];
         int j = i;
         compare_count++;
         
         //compare the element at start and start-increment position and swap if it is smaller
         while(j >= increment && data[j - increment] > temp) 
         {
            data[j] = data[j - increment];
            move_count++;
            j = j - increment;
         }
         data[j] = temp;    
      }
   }
}
