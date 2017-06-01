#ifndef WORDMAP_H_
#define WORDMAP_H_

#include <map>
#include <ctime>
#include <chrono>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

//class to implement Word map
class WordMap : public TimedContainer
{
public:
	WordMap();          //default constructor
	virtual ~WordMap(); //default destructor

	map<string, Word>& get_data(); //getter function to get data
	void set_data (Word w);        //setter function to set data
	int get_count(const string text) const; //getter function to get the count of a particular Word in data
	void insert(const string text);    //function to insert a word into the data
	map<string, Word>::iterator search(const string text); //function to search a word in data

private:
	map<string, Word> data;  //map variable to store Word
};

#endif /* WORDMAP_H_ */
