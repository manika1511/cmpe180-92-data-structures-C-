#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

//class to store the word and its count
class Word
{
public:
	Word();            //default constructor
	Word(string text); //constructor
	virtual ~Word();   //default destructor

	string get_text() const; //getter function to get the text
	int get_count() const;   //getter function to get the count
	void set_text(string s); //setter function to set the text
	void set_count(int c);   //setter function to set the count

	void increment_count();  //function to increment the count

private:
	string text;     //variable to store the text of the word
	int count;       //variable to store the count of the word
};

#endif /* WORD_H_ */
