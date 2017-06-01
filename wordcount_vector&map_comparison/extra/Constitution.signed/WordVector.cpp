#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"
#include "Word.h"

using namespace std;
using namespace std::chrono;

//default constructor
WordVector::WordVector()
{
}

//default destructor
WordVector::~WordVector()
{
}

//function to get the data, returns data
vector<Word>& WordVector::get_data() { return data; }

//function to get the count of a Word in the vector
int WordVector::get_count(const string text) const
{
	Word w(text);    //initialising the Word w with text
	int count;
	int i;
	for (i = 0; i < data.size(); i++) //looping through the vector to find the index of the word to be searched
	{
		if (data[i].get_text() == text)  //if found, break
		{
			break;
		}
	}
	count = data[i].get_count();   //store the count of word in count
	return count;
}

//function to insert a Word into the vector data
void WordVector::insert(const string text)
{
	steady_clock::time_point start_time = steady_clock::now(); //start time
	Word w(text);              //initialising the Word w with text
	vector<Word>::iterator it; //iterator to iterate the vector
	it = data.begin();         //set iterator to the start of the vector data

	if (data.empty())          //insert the Word in the vector if it is empty
	{
		data.push_back(w);
	}
	else                       //find the position for the Word to be inserted
	{
		int low = 0;
		int high = data.size() - 1;
		int index = find_insert(text, low, high);  //binary search the index to insert the Word with text

		if (data[index].get_text() == text)        //if the word already exists increment the count
		{
			data[index].increment_count();
		}
		else                                     //if it doesn't exist insert it into the proper index
		{
			it = data.begin();
			advance(it, index);
			data.insert(it, w);
		}
	}
	steady_clock::time_point end_time = steady_clock::now(); //stop time
	const long elapsed_time = duration_cast<microseconds>(end_time - start_time).count(); //elapsed time
	increment_elapsed_time(elapsed_time); //increment elapsed time
}

//function to serach a Word in the vector data
vector<Word>::iterator WordVector::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now(); //start time
	vector<Word>::iterator it;        //iterator to iterate the vector
	int low = 0;
	int high = data.size() - 1;
	int index = find(text, low, high);//binary search the index of the Word to be searched

	if (index >= 0) //if the Word is found return iterator pointing towards it
	{
		it = data.begin() + index;           //converting index to iterator
		steady_clock::time_point end_time = steady_clock::now(); //stop time
		const long elapsed_time = duration_cast<microseconds>(end_time - start_time).count(); //elapsed time
		increment_elapsed_time(elapsed_time);      //increment elapsed time
		return it;
	}
	else  //if not found  then return the iterator pointing the end of vector data
	{
		steady_clock::time_point end_time = steady_clock::now(); //stop time
		const long elapsed_time = duration_cast<microseconds>(end_time - start_time).count();//elapsed time
		increment_elapsed_time(elapsed_time);   //increment the elapsed time
		return data.end();
	}
}

/*function to find the index for the Word having text as text
 *@param text: Word with text as text to be searched for
 *@param low : start index of vector
 *@param high: end index of the vector
 */
int WordVector::find(const string text, int low, int high) const
{
	int mid; //mid-point of the vector
	while(low <= high)
	{
		mid = low + (high-low)/2; //calculate middle index of the vector

		if (data[mid].get_text() == text) //return mid if word at index mid equal to the text
		{
			return mid;
		}
		else if (data[mid].get_text() < text) //set low to mid+1 if the text > text of word at index mid
		{
			low = mid + 1;
		}
		else          //set high to mid-1 if the text < text of word at index mid
		{
			high = mid - 1;
		}
	}
	return -1;
}

/*function to find the index to insert the Word having text as text
 *@param text: Word with text as text to be searched for
 *@param low : start index of vector
 *@param high: end index of the vector
 */
int WordVector:: find_insert(const string text, int low, int high)
{
	int mid; //mid-point of the vector
	while(low <= high)
	{
		mid = low + (high-low)/2; //calculate middle index of the vector

		if (data[mid].get_text() == text) //return mid if word at index mid equal to the text
		{
			return mid;
		}
		else if (data[mid].get_text() < text) //set low to mid+1 if the text > text of word at index mid
		{
			low = mid + 1;
		}
		else          //set high to mid-1 if the text < text of word at index mid
		{
			high = mid - 1;
		}
	}
	return low;
}

