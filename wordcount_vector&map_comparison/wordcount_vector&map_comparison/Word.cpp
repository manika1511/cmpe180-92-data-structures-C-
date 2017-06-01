#include <string>
#include "Word.h"
using namespace std;

//default constructor sets count to 0 and text to ""
Word::Word(): text(""), count(0)
{
}

//Constructor sets text to text and count to 1
Word::Word(string text) : text(text), count(1)
{
}

//Default destructor
Word::~Word()
{
}

//getter function returns the value of text
string Word::get_text()  const { return text; }

//getter function returns the value of count
int    Word::get_count() const { return count; }

//function increments count by 1
void   Word::increment_count() { count++; }

//setter function to set the value of text sets text to s and count to 1
void Word::set_text(string s)
{
	text = s;
	count = 1;
}

//setter function sets count to x
void Word:: set_count(int x)
{
	count = x;
}
