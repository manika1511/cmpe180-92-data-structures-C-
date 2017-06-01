#include <string>
#include "Word.h"
using namespace std;

Word::Word() : text(""), count(0)
{
}

Word::Word(string text) : text(text), count(1)
{
}

Word::~Word()
{
}

string Word::get_text()  const { return text; }
int    Word::get_count() const { return count; }

void   Word::increment_count() { count++; }
void Word::set_text(string s)
{
	text = s;
	count = 1;
}
void Word:: set_count(int x)
{
	count = x;
}
