#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"
#include "Word.h"

using namespace std;
using namespace std::chrono;

WordMap::WordMap()
{
}

WordMap::~WordMap()
{
}

map<string, Word>& WordMap::get_data() { return data; }

void WordMap:: set_data (Word w)
{
	data[w.get_text()] = w;
}

int WordMap::get_count(const string text) const
{
    int count = data.at(text).get_count();
    return count;
}

void WordMap::insert(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();
	map<string, Word>::iterator it;
	it = data.find(text);
	if (it != data.end())
	{
		it->second.increment_count();
	}
	else
	{
		Word w;
		w.set_text(text);
		data[text] = w;
	}
	steady_clock::time_point end_time = steady_clock::now();
	const long elapsed_time = duration_cast<microseconds>(end_time - start_time).count();
	increment_elapsed_time(elapsed_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();
	map<string, Word>::iterator it;
	it = data.find(text);
	steady_clock::time_point end_time = steady_clock::now();
	const long elapsed_time = duration_cast<microseconds>(end_time - start_time).count();
	increment_elapsed_time(elapsed_time);
	return it;

}


