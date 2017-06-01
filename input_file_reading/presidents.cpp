/* Assignment #1 : Presidents
 * Author: Manika Kapoor
 * Student ID: 011539203
 */


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <locale>

using namespace std;

const string INPUT_FILE_NAME = "presidents.in";

// Declaring a structure to store the values of various fields
struct ENTRY
{
	string first_name;
	string middle_name;
	string last_name;
	string born;
	string died;
	string age;
	string start;
	string end;
	string party;
};

int main()
{
    ifstream input;
    struct ENTRY data;
    int check=0;								 //variable to check whether the first word of the line has already been read or not
    string word;
    double total_age = 0;
    int dead_pres = 0;
    double average_age;
    input.open(INPUT_FILE_NAME);

    // Checking file open was successful or not
    if (input.fail())
    {
        cout << "Failed to open " << "input.txt" << endl;
        return -1;
    }

    // Printing the column headings
    cout << setw(12) << left << "First Name" << setw(12) << left << "Middle Name" << setw(12) << left << "Last Name" << setw(5) << left << "Born" << setw(6) << left << "Died" << setw(5) << left << "Age" << setw(6) << left << "Start" << setw(6) << left << "End" << left << "Party" << endl;
    cout << "----------" << "  " << "-----------" << " " << "---------" << "   " << "----" << " " << "----" << "  " << "---" << "  " << "-----" << " " << "----" << "  " << "-----" << endl;
    while(!input.eof())
		{
    		while (word != ".")
    		{
    			string name[5];					 	//string array to store name parts (first, middle,last)
    			int birth_year = 0, death_year = 0; //integer variables to read birth and death year
    			int age = 0;						//integer variable to store age
    			int t_end, t_start;					//variable to store the "start" year and "End" year
    			int count=0;						// variable to check number of words in name (first, middle & last name together)
    			if (check == 0)						//check if the first word of the line has already been read or not
    			{
    				input >> word;
    			}
    			if (word == ".")					//check if the first word of the sentence is a period (".").
    			{									//If yes, entire file has been read
    				break;
    			}

    			while (word != "(")					//Counting the number of words in the name
    			{									//first, middle and last name included
    				name[count] = word;
    				count++;
    				input >> word;
    			}

    		    /* Checking for the various conditions of Names and then storing appropriate values in
    		     * the structure */

    			if (count == 2)
    			{
    				data.first_name = name[0];
    				data.middle_name = " ";
    				data.last_name = name[1];
    			}
    			if (count == 3)
    			{
    				data.first_name = name[0];
    				if (isupper(name[1].at(0)))
    				{
    					data.middle_name = name[1];
    					data.last_name = name[2];
    				}
    				else
    				{
    					data.middle_name = " ";
    					data.last_name = name[1] + " " + name[2];
    				}
    			}
    			if (count == 4)
    			{
    				data.first_name = name[0];
    				if (isupper(name[1].at(0)))
    				{
    					if (isupper(name[2].at(0)))
    					{
    						data.middle_name = name[1] + " " + name[2];
    						data.last_name = name[3];
    					}
    					else
    					{
    						data.middle_name = name[1];
    						data.last_name = name[2] + " " + name[3];
    					}
    				}
    				else
    				{
    					data.middle_name = " ";
    					data.last_name = name[1] + " " + name[2] + " " + name[3];
    				}
    			}

    			input >> birth_year;				      //reading birth year as an integer
    			data.born = to_string(birth_year);
    			input >> word;
    			if (word == "-")
    			{
    				input >> death_year;				  //reading death year as an integer
    				data.died = to_string(death_year);
    				age = death_year - birth_year;		  //calculating age
    				total_age = total_age + age;
    				dead_pres = dead_pres + 1;
    				data.age = to_string(age);
    				input >> word;
    			}
    			else
    			{
    				data.died = " ";
    				data.age = " ";
    			}

    			input >> word;
    			data.party = word;

    			input >> t_start;
    			data.start = to_string(t_start);
    			t_end = t_start;						  //storing "Start" year in t_end

    			input >> word;
    			if (word == "-")
    			{
    				input >> t_end;
    				data.end = to_string(t_end);
    				check = 0;
    			}
    			else
    			{										   //storing "End" year same as "Start" year if there
    				data.end = to_string(t_end);		   //is no "End" year and then setting check to 1 indicating
    				check = 1;							   //that first word of next line has been read
    			}

    			//Printing out the output corresponding to eack line of input
    			cout << setw(12) << left << data.first_name << setw(12) << left << data.middle_name << setw(12) << left << data.last_name;
    			cout << setw(5) << left << data.born << setw(7) << left << data.died << setw(5) << left << data.age << setw(5) << left << data.start << setw(6) << left << data.end << left << data.party << endl;
    		}
		}
	//Calculating and displaying the "Average age at death" of presidents accurate to one decimal point
    average_age = (total_age/dead_pres);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << endl << "Average age at death = " << average_age;
    return 0;
}
