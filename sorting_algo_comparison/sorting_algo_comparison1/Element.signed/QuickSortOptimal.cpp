#include "QuickSortOptimal.h"
#include <vector>
#include <algorithm>

using namespace std;
/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortOptimal::QuickSortOptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
   if (data.size() > 2)
   {
      long l = data[left].get_value();           //variable to store the leftmost Element
      long m = data[(left+right)/2].get_value(); //variable to store the middle Element 
      long r = data[right].get_value();          //variable to store the rightmost Element
      compare_count++;
      compare_count++;
      
      //Pivot is the middle of the above three values
      if ((l <= m && l >= r) || (l >= m && l <= r))
      {
         return data[left];
      }
      else if ((m <= l && m >= r) || (m >= l && m <= r))
      {
         return data[(left+right)/2];
      }
      else if ((r <= l && r >= m) || (r >= l && r <= m))
      {
         return data[right];
      }
   }
   else
   {
      return data[left];
   }
}
