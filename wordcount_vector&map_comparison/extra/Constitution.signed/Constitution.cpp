/* Assignment #11 : STL Vector and Map Extra Credit(binary search)
 * Author: Manika Kapoor
 * Student ID: 011539203
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <stdlib.h>
#include <iterator>
#include <sstream>
#include <cctype>
#include "Word.h"
#include "WordVector.h"
#include "WordMap.h"

using namespace std;

const string INPUT_FILE_NAME = "USConstitution.txt";
const int    MAX_SEARCHES    = 100000;

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m); //function to calculate the insertion times of vector and map
void make_spot_checks(WordVector& v, WordMap& m) throw(string);     //function to print sample counts for Words in vector and map
void check_concordances(WordVector& v, WordMap& m) throw(string);   //function to compare the vector and map counts
void time_word_searches(WordVector& v, WordMap& m) throw(string);   //function to calculate search times in vector and map
string commafy(const long n);    //function to convert a number to a string with commas

int main()
{
	ifstream in;
	in.open(INPUT_FILE_NAME); //open the file
	if (in.fail())       //check if the file is opened properly
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	WordVector v;
	WordMap    m;

	try
	{
		time_word_insertions(in, v, m);
		make_spot_checks(v, m);
		check_concordances(v, m);
		time_word_searches(v, m);
	}
	catch (string& msg)
	{
		cout << endl << endl << "***** " << msg << endl;
	}

	return 0;
}

//function to calculate the insertion times of vector and map
void time_word_insertions(ifstream& in, WordVector& v, WordMap& m)
{
	string line;
	int line_count = 0;
	int character_count = 0;
	int word_count = 0;

	cout << "Timed insertions ..." << endl;

	// Loop once per line of the input file.
	while (getline(in, line))
	{
		line_count++;   //increment line_count

		//replace punctuations and digits in line with a " "
		for (int i = 0; i < line.length(); i++)
		{
			if (ispunct(line[i]) || isdigit(line[i]))
			{
				line[i] = ' ';
			}
			character_count = character_count + 1; //calculating total number of characters in the input file
		}

		istringstream iss(line); //convert the line into stream
		string word;
		while(iss >> word)       //while the file is not fully read
		{
			word[0] = tolower(word[0]); //convert the first character of the input Word to lowercase
			word_count++;               //increment the word_count
			v.insert(word);   //insert the read Word in the vector
			m.insert(word);   //insert the read Word in the map
		}
	}

	//output the line_count, character_count, word_count, vector and map size
	cout << "          Lines: " << setw(6) << commafy(line_count) << endl;
	cout << "     Characters: " << setw(6) << commafy(character_count) << endl;
	cout << "          Words: " << setw(6) << commafy(word_count) << endl;
	cout << endl;
	cout << "    Vector size: " << commafy(v.get_data().size()) << endl;
	cout << "       Map size: " << commafy(m.get_data().size()) << endl;
	cout << endl;
	cout << "    Vector total insertion time: " << setw(8)
		 << commafy(v.get_elapsed_time()) << " usec" << endl;
	cout << "       Map total insertion time: " << setw(8)
		 << commafy(m.get_elapsed_time()) << " usec" << endl;

	//reset the elapsed time
	v.reset_elapsed_time();
	m.reset_elapsed_time();
}

//function to print sample counts for Words in vector and map
void make_spot_checks(WordVector& v, WordMap& m) throw(string)
{
	cout << endl << "Spot checks of word counts ..." << endl;

	vector<Word>&      vdata = v.get_data();
	map<string, Word>& mdata = m.get_data();

	vector<string> texts =
	{
			"amendment", "article", "ballot", "citizens", "congress",
			"constitution", "democracy", "electors", "government", "law",
			"legislature", "people", "president", "representatives",
			"right", "trust", "united", "vice", "vote"
	};

	for (string text : texts)
	{
		cout << "    " << text << ": ";

		vector<Word>::iterator      itv = v.search(text); //search the text
		map<string, Word>::iterator itm = m.search(text); //search the text

		if (itm != mdata.end())    //if the Word exists print its count
		{
			cout << "vector:" << itv->get_count() << " map:" << itm->second.get_count() << endl;
		}
		else //print not found if it doesn't exist
		{
			cout << "vector:" << "(not found)" << " map:" << "(not found)" << endl;
		}
	}
}

//function to compare the vector and map counts
void check_concordances(WordVector& v, WordMap& m) throw(string)
{
	cout << endl << "Checking concordances ... ";  cout.flush();

	vector<Word>&      vdata = v.get_data();
	map<string, Word>& mdata = m.get_data();

	int vsize = vdata.size();
	int msize = mdata.size();

	if (vsize == 0) throw("Empty vector.");
	if (msize == 0) throw("Empty map.");

	if (vsize != msize ) throw(string("Size mismatch: ") + to_string(vsize) + " and " + to_string(msize));

	vector<Word>::iterator      itv = vdata.begin();
	map<string, Word>::iterator itm = mdata.begin();

	//Comparing vector and map counts
	while (itv != vdata.end())
	{
		if ((*itv).get_count() != itm->second.get_count())
		{
			throw string(string("Data mismatch: ")
					+ itv->get_text() + ":" + to_string(itv->get_count())
					+ " and " + itm->second.get_text() + ":"
					+ to_string(itm->second.get_count()));
		}

		++itv;
		++itm;
	}

	cout << "both match!" << endl;
}

//function to calculate search times in vector and map
void time_word_searches(WordVector& v, WordMap& m) throw(string)
{
	cout << endl << "Timed searches (" << commafy(MAX_SEARCHES)
			     << " searches) ..." << endl;

	int size = v.get_data().size(); //size of Word vector

	for (int i = 1; i <= MAX_SEARCHES; i++)
	{
		int index = rand()%size;                     //generating random index
		string text = v.get_data()[index].get_text();
		vector<Word>::iterator itv = v.search(text); //search the word in vector
		map<string, Word>::iterator itm = m.search(text);//search the word in map
	}

	cout << endl;
	cout << "    Vector total search time: " << setw(8)
		 << commafy(v.get_elapsed_time()) << " usec" << endl;
	cout << "       Map total search time: " << setw(8)
		 << commafy(m.get_elapsed_time()) << " usec" << endl;
}

/*
 * Convert a number to a string with commas.
 * @param n the number.
*/
string commafy(const long n)
{
	string str = to_string(n);
	int pos = str.length() - 3;

	while (pos > 0)
	{
		str.insert(pos, ",");
		pos -= 3;
	}

	return str;
}

