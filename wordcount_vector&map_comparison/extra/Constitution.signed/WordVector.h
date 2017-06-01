#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include <vector>
#include <ctime>
#include <chrono>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

//class to implement Word vector
class WordVector : public TimedContainer
{
public:
	WordVector();          //default constructor
	virtual ~WordVector(); //default destructor

	vector<Word>& get_data();               //getter function to get data
	int get_count(const string text) const; //getter function to get the count of a particular Word in data

	void insert(const string text);         //function to insert a word into the data
	vector<Word>::iterator search(const string text);//function to search a word in data
	int find_insert(const string text, int low, int high); //function to search an index to insert an element into the data vector

private:
	vector<Word> data;     //vector variable to store Word

	int find(const string text, int low, int high) const; //function to search an element index in the data vector
};

#endif /* WORDVECTOR_H_ */
