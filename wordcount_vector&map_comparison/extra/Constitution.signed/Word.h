#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

class Word
{
public:
    Word();
    Word(string text);
    virtual ~Word();

    string get_text() const;
    int get_count() const;
    void set_text(string s);
    void set_count(int c);

    void increment_count();

private:
    string text;
    int count;
};

#endif /* WORD_H_ */
