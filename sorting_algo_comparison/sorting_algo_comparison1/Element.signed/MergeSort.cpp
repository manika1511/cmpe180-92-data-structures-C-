#include <string>
#include "MergeSort.h"
#include "Sorter.h"
#include "LinkedList.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
   // Defensive programming: Make sure we end up
   // with the same size list after sorting.
   int size_before = data.get_size();
   
   mergesort(data);
   
   // Check sizes.
   int size_after = data.get_size();
   if (size_before != size_after)
   {
      string message = "***** Size mismatch: before " + to_string(size_before) + ", size after " +
                         to_string(size_after);
      throw message;
   }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
//***Citation: Data Structures using C++ by D.S. Malik
void MergeSort::mergesort(LinkedList& list)
{
   LinkedList sublist1, sublist2;   //lists to store the two sublists
   
   if (list.get_head() != nullptr)
   {
      if (list.get_head()->next != nullptr)
      {
         list.split(sublist1, sublist2);         //split if the list contains more than one element
      
         if(sublist1.get_head() != nullptr)
         {
            mergesort(sublist1);               //merge sort on first sublist
         }
         if(sublist2.get_head() != nullptr)
         {
            mergesort(sublist2);              //merger sort on second sublist
         }
         merge(list,sublist1,sublist2);       //merge the sublists
      }
   }
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
//***Citation: Data Structures using C++ by D.S. Malik 
void MergeSort::merge(LinkedList& list, LinkedList& sublist1, LinkedList& sublist2)
{
   list.reset();     
   /*
    *iterate through both the sublists if they are not empty and compare their head values.
    *Remove the head of the sublist having smaller value and add it to the list
   */
   while(sublist1.get_head() != nullptr && sublist2.get_head() != nullptr)   
   {
      if(sublist1.get_head()->element.get_value()<=sublist2.get_head()->element.get_value())
      {
         compare_count++;
         move_count++;
         list.add(sublist1.remove_head());
      }
      else
      {
         compare_count++;
         move_count++;
         list.add(sublist2.remove_head());
      }
   }
   //Concatenate the left over part of the sublist having elements to the list
   if (sublist1.get_head() == nullptr && sublist2.get_head() != nullptr)
   {
      list.concatenate(sublist2);
   }
   else if (sublist2.get_head() == nullptr && sublist1.get_head() != nullptr)
   {
      list.concatenate(sublist1);
   }
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }
