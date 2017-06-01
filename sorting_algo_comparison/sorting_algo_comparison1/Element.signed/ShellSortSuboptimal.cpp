#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
//***Citation: http://quiz.geeksforgeeks.org/shellsort/
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
   int increment;
   
   //first increment starts from half the size of vector
   for (increment = size/2; increment > 0; increment = increment/2)
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
