#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"
#include "Word.h"

using namespace std;
using namespace std::chrono;

//default constructor
WordMap::WordMap()
{
}

//default destructor
WordMap::~WordMap()
{
}

//function to get the data, returns data
map<string, Word>& WordMap::get_data() { return data; }

//function to set the data
void WordMap:: set_data (Word w)
{
	data[w.get_text()] = w; //inserting a Word into data
}

//function returns the count of word in the data
int WordMap::get_count(const string text) const
{
	int count = data.at(text).get_count(); //count of word text in data
	return count;
}

//function to insert a word into data
void WordMap::insert(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();  //starts the time
	map<string, Word>::iterator it;   //iterator to loop through the data map
	it = data.find(text);             //searching for the text in map
	if (it != data.end())             //incrementing the count if the word already exists
	{
		it->second.increment_count(); //increment the count if it already exists
	}
	else
	{
		Word w;
		w.set_text(text);
		data[text] = w;               //inserting the element if it doesn't exist
	}
	steady_clock::time_point end_time = steady_clock::now(); //stop the time
	const long elapsed_time = duration_cast<microseconds>(end_time - start_time).count(); //elapsed time
	increment_elapsed_time(elapsed_time);                   //increment elapsed time
}

//function to search for a word in the data map
map<string, Word>::iterator WordMap::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();  //start time
	map<string, Word>::iterator it;                             //iterator to loop through the data map
	it = data.find(text);                                       //find the word
	steady_clock::time_point end_time = steady_clock::now();    //stop time
	const long elapsed_time = duration_cast<microseconds>(end_time - start_time).count(); //elapsed time
	increment_elapsed_time(elapsed_time);            //increment elapsed time
	return it;
}


