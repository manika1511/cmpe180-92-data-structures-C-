
#include "Employee.h"         //including Employee header file
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;

void execute(istream& record, vector<Employee> &list, char command);
//function to execute the command
//Precondition : The command ('+','?','-','%') has been read
//Postcondition: The result of the command execution is displayed

void print_all(vector<Employee> &list);
//function to print the sorted list of employees after execution of all commands
//Precondition : all the commands are executed and employee records are manipulated accordingly
//Postcondition: the employee records are displayed in sorted order

void print_stats(vector<Employee> &list);
//function to print the maximum, minimum and average salary
//Precondition : all the commands are executed and employee records are stored in sorted order
//Postcondition: the maximum, minimum and average salary is displayed

int search(vector<Employee> &list, int check);
//function to search for an element in the vector<Employee>list (binary search)
//Precondition : the employee id to be checked is input and the list is in sorted order
//Postcondition: the employee record with particular id is displayed/deleted/added

enum ERROR_CODE {NO_ERROR, DUPLICATE, NOT_FOUND, INVALID_COMMAND}; //error codes

const string INPUT_FILE_NAME = "commands.txt";   //input file

int main()
{
    // Open the input file.
    ifstream input;

    input.open(INPUT_FILE_NAME);      //checking if opening the file is successful or not
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl; //displaying error message if opening file is unsuccessful
        return -1;
    }

    char command;              //variable to store the command ('+','?','-','%')
    char ch;				   //variable to store the peeked value at the end of each command to check for eof
    vector<Employee> list;	   //vector to store the Employee records

    input >> command;          //input first command (i.e. '+')

    while (!input.eof())
    {
    	execute(input, list, command);   //function call to execute the command
    	ch = input.peek();               //peek the next char
    	if (ch == input.eof())
    	{
    	    break;                       //breaking out of loop if the next char is eof
    	}
    	input >> command;                //input the next command
    }

    print_all(list);                     //function call to print the sorted list of employees after execution of all commands
    print_stats(list);                   //function call to print the maximum, minimum and average salary

    return 0;
}

void execute(istream& input , vector<Employee> &list, char command)   //function to execute the command
{
	Employee e;         //variable to input employee record
	string line;        //variable to store line of input file
	int i;              //variable to iterate over the vector of employee records
	ERROR_CODE error;   //variable to store error code

	if (command == '+')    //adding record if command is '+'
	{
		int size = list.size();    //calculating size of vector list

		input >> ws;
		getline(input,line);       //input a line from input file
		istringstream record(line);//converting string line in input stream and store in record

		record >> e;               //input the employee record

		int index = search(list, e.get_id()); //search for the input employee id

		if (index == -1)          //set error to NO_ERROR if it doesn't exist
		{
			error = NO_ERROR;
		}
		else                       //set to error to DUPLICATE if it already exists
		{
			error = DUPLICATE;
		}

		if (size == 0)             //entering the first employee record
		{
			list.push_back(e);
			cout << command << " " <<  list[0].get_id() << ": " << list[0];
		}
		else
		{
			if (error == 0)        //inserting the employee record in the proper position(sorted)
			{
				i = 0;
				while(e.get_id() > list[i].get_id() && i<size)  //iterating over the vector list till the input id greater than existing ids
				{
					i++;
				}

				list.insert(list.begin() + i, e);  //inserting the employee record at the proper position
				cout << command << " " <<  list[i].get_id() << ": " << list[i]; //printing the entered employee record
			}
			if (error == 1)   //printing error message if the id already exists
			{
				cout << command << " " <<  e.get_id() << ": " << "*** Duplicate ID ***" << endl;
			}
		}
	}

	else if (command == '-')  //deleting a record (if exists)
	{
		input >> ws;
		getline(input,line);  //input a line from input file

		int check = stoi(line);//converting string to integer and storing the employee id to be deleted in check
		int index = search(list,check); //searching for the id in the list

		if (index == -1)
		{
			error = NOT_FOUND;
		}
		else                      //deleting the employee record if it exists
		{
			error = NO_ERROR;
			cout << command << " " << check << ": " << list[index]; //displaying the record to be deleted
			list.erase(list.begin()+index);
		}

		if (error == 2)              //displaying error message if the id doesn't exist
		{
			cout << command << " " << check << ": " << "*** ID not found ***" << endl;
		}
	}

	else if (command == '?')      //searching for the id and displaying the entire employee record
	{
		input >> ws;
		getline(input, line);     //input a line from input file

		int check = stoi(line);   //converting string to integer and storing the employee id to be searched in check

		int index = search(list,check); //searching for the employee id to be displayed

		if (index == -1)
		{
			cout << command << " " << check << ": " << "*** ID not found ***" << endl;
		}
		else                      //displaying the employee record if it exists
		{
			cout << command << " " << check << ": " << list[index];
		}
	}

	else            //displaying error message INVALID_COMMAND if the command is invalid
	{
		input >> ws;
		getline(input,line); //input a line from input file

		istringstream record(line);//converting string line into input stream and store it in record

		record >> e;    //input the record
		cout << command << " " << e.get_id() << ": " << "*** Invalid command ***" << endl; //display the error message
	}
}

void print_all(vector<Employee> &list)   //function call to print the sorted list of employees after execution of all commands
{
	cout << endl;
	cout << "All employees" << endl;
	cout << "-------------" << endl;
	for (int i = 0; i < list.size(); i++)  //printing the employee records
	{
		cout << list[i];
	}
}

void print_stats(vector<Employee> &list) //function call to print the maximum, minimum and average salary
{
	double average_salary;             //variable to store average salary
	double total_salary = 0;           //variable to store total salary

	//sorting the employee records on salary
	for (int i = 0; i< list.size(); i++)
	{
		if(list[i].get_salary() > list[i+1].get_salary() && (i+1) < list.size())
		{
		    Employee temp;
		    temp = list[i];
		    list[i] = list[i+1];
		    list[i+1] = temp;
		}
	}

	for (int i = 0; i< list.size(); i++)         //calculating total salary (of all employees)
	{
		total_salary = total_salary + list[i].get_salary();
	}

	average_salary = (total_salary/list.size()); //calculating average salary

	//printing the minimum, maximum and average salary
	cout << endl;
	cout << "Statistics" << endl;
	cout << "----------" << endl;
	cout << fixed;
	cout << showpoint;
	cout << setprecision(2);
	cout << "Minimum salary = $" << right << setw(9) << list[0].get_salary() << endl;
	cout << "Maximum salary = $" << right << setw(9) << list[list.size()-1].get_salary() << endl;
	cout << "Average salary = $" << right << setw(9) << average_salary << endl;
}

int search (vector<Employee> &list, int check)  //function to search a given employee id (binary search)
{
	int size = list.size();      //size of the vector<Employee> list
	int start = 0;               //index of first element in the list
	int end = size - 1;          //index of last element in the list
	int mid;                     //variable to store index of middle element
	while(start <= end)
	{
		mid = start+((end-start)/2);  //calcuating index of middle element

		if (list[mid].get_id() == check)  //return the index if the middle element employee id equals the one to be checked
		{
			return mid;
		}
		else if (list[mid].get_id() < check) //if the value to be checked lies above the mid element set start to mid+1
		{
			start = mid+1;
		}
		else                   //if the value to be checked lies below the mid element set end to mid-1
		{
			end = mid - 1;
		}
	}
	return -1;
}








