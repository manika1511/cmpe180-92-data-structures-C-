#include <iostream>
#include "QuickSorter.h"
#include "VectorSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
   quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
   int pivotLoc;
   if (left < right)
   {
      Element pivot = choose_pivot(left, right);
      pivotLoc = partition(left, right, pivot);
      quicksort (left, pivotLoc-1);
      quicksort (pivotLoc+1, right);
   }
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
   return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
//***Citation: Data structures using C++ by D.S. Malik
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
   int index, small;
   compare_count++;
   
   /*
    *swap the pivot with the leftmost element. As in suboptimal case the pivot itself is 
    *the leftmost element so no swapping.
   */
   if (data[left].get_value() != pivot.get_value() && left > -1 && left < data.size())
   {
      compare_count++;
      if (data[right].get_value() != pivot.get_value())
      {
         swap(left, (left+right)/2);
      }
      else
      {
         swap(left, right);
      }
   }
   
   small = left;
   
   //iterate through the vector starting from 2nd element as first element is now pivot
   for(index = left+1; index <= right && small < data.size(); index++)
   {
      compare_count++;
      if (data[index] < pivot)    //comparing the pivot with element at index 
      {
         small++;
         swap(small, index);      //swap only if the element is less than the pivot
      }
   }
   
   //small has the sorted position of the pivot
   swap(left, small);             //swap the pivot with the element at index small 
   return small;
}
