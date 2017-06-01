/* Assignment #2 : Rock Paper Scissors
 * Author: Manika Kapoor
 * Student ID: 011539203
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

const int MAX_ROUNDS = 20;                      // max rounds per game

enum Player { HUMAN, COMPUTER, TIE };           // players and winners
enum Thing  { ROCK, PAPER, SCISSORS };          // what each player chooses

Thing human_input();
//function to input human choice
//Precondition : user must be ready to enter input.
//Postcondition: Thing corresponding to valid human input ('r' or 'R', 's' or 'S', 'p' or 'P') is returned to the calling function.
//               else an error message is popped asking to enter a valid input.

Thing computer_input(int comp_in);
//function to determine computer input (Thing)
//Precondition : comp_in is the pseudo-random number generated by computer (among 1, 2 & 3).
//Postcondition: Thing corresponding to the generated random number is returned to the calling function.

Player winner (Thing human_in, Thing computer_in);
//function to determine the winner
//Precondition : human_in is human input (Thing) and computer_in is computer input (Thing).
//Postcondition: the winner of the round is returned to the calling function.

void record_win( Player winner, int& h_win , int& c_win , int& ties );
//function to record the winner of a round
//Precondition : variable winner has the winner of the current round, h_win stores human wins, c_win stores computer_wins
//               and ties stores number of ties.
//Postcondition: the values of h_win or c_win or ties is incremented based on the winner of current round.

void summary (int human_win, int comp_win, int ties );
//function to print the summary of the game
//Precondition : human_win, comp_win and ties stores total human wins, computer wins and ties respectively
//               in a game of 20 rounds.
//Postcondition: the summary of the game (20 rounds) is printed on the screen.

int main()
{
    int human_wins = 0;							//variable to record human wins
    int computer_wins = 0;						//variable to record computer wins
    int ties = 0;								//variable to record ties
    int comp_in;								//variable to store random input generated using rand()
    Player won_by;								//variable to store the winner of a round
    int round = 1;								//variable to store the round number
    Thing human_in; 							//variable to store human input
    Thing computer_in;							//variable to store converted computer input (Thing)

    while (round <= MAX_ROUNDS)					//condition to check the number of rounds
    {
    	cout << "Round : " << round << endl;	//output value of Round
    	human_in = human_input();				//take human input
    	srand(time(NULL));                   	//seed the random number generator
    	comp_in = rand() % 3 + 1;				//random number generated by computer
    	computer_in = computer_input(comp_in);	//convert randomly generated integer input into a Thing
    	won_by = winner (human_in, computer_in); //determine the winner
    	record_win (won_by, human_wins, computer_wins, ties);//record the winner of each round
    	round++;
    	cout << endl;
    }
    summary (human_wins, computer_wins, ties);	//print the summary of the game

    return 0;
}

Thing human_input()						//funtion to take human input
{
	char h_input;						//variable to store human input as 'r','R','p','P','s', 'S' or any invalid input
	char h_in;							//variable to store the uppercase character of input
	Thing h_choice;						//variable to store the human choice as a Thing
	do
	{
		cout << "Your choice? ";
		cin >> h_input;					//inputting human choice
		cout << h_input << endl;
		h_in = toupper(h_input);		//converting lower case input to upper case

		switch (h_in)					//determining human input corresponds to which Thing
		{
		 case 'R':						//case to determine whether human input is ROCK
				 {
					h_choice = ROCK;
					cout << "You chose ROCK." << endl;
					break;
				 }

		 case 'P':						//case to determine whether human input is PAPER
				 {
					h_choice = PAPER;
					cout << "You chose PAPER." << endl;
					break;
				 }

		 case 'S':						//case to determine whether human input is SCISSORS
				 {
					h_choice = SCISSORS;
					cout << "You chose SCISSORS." << endl;
					break;
				 }

		 default :						//default condition if any other(invalid) human input is entered
				 {
					cout << "*** ERROR: Valid choices are R, P and S" << endl;
					break;
				 }
		}

	} while (h_in != 'R' && h_in != 'P' && h_in != 'S');	//condition to check whether a valid input is entered by human or not

	return h_choice;
}

Thing computer_input(int comp_in) 		//function to determine computer input (Thing)
{
	Thing comp_choice;					//variable to store computer choice as a Thing

	switch(comp_in)						//determining computer input corresponds to which Thing
	{
	case 1:								//case to determine whether computer input is ROCK
		  {
			  comp_choice = ROCK;
			  cout << "The computer chose ROCK." << endl;
			  break;
		  }

	case 2:								//case to determine whether computer input is PAPER
		  {
			  comp_choice = PAPER;
			  cout << "The computer chose PAPER." << endl;
			  break;
		  }

	case 3:								//case to determine whether computer input is SCISSORS
		  {
			  comp_choice = SCISSORS;
			  cout << "The computer chose SCISSORS." << endl;
			  break;
		  }
	}

	return comp_choice;
}


Player winner (Thing human_in, Thing computer_in) //function to determine winner of each round
{
	if (human_in == computer_in)				  //determine if it's a TIE
	{
		return TIE;
	}

	/* Determine the winner if it's not a TIE using conditions ROCK beats SCISSORS, PAPER beats ROCK
	 * and SCISSORS beat PAPER
	*/
	if (human_in == ROCK)
	{
		if (computer_in == PAPER)
		{
			return COMPUTER;
		}
		if (computer_in == SCISSORS)
		{
			return HUMAN;
		}
	}
	if (human_in == PAPER)
	{
		if (computer_in == SCISSORS)
		{
			return COMPUTER;
		}
		if (computer_in == ROCK)
		{
			return HUMAN;
		}
	}
	if (human_in == SCISSORS)
	{
		if (computer_in == ROCK)
		{
			return COMPUTER;
		}
		if (computer_in == PAPER)
		{
			return HUMAN;
		}
	}
}

void record_win (Player winner, int& h_win, int& c_win, int& ties) //function to record winner of a round
{
	if (winner == HUMAN)
	{
		cout << "The winner is you." << endl;
		h_win++;										//incrementing human win if human wins
 	}
	if (winner == COMPUTER)
	{
		cout << "The winner is the computer." << endl;
		c_win++;										//incrementing computer win if computer wins
	}
	if (winner == TIE)
	{
		cout << "It's a tie." << endl;
		ties++;											//incrementing ties if it's a TIE
	}
}

void summary( int human_win, int comp_win, int ties)	//function to print the summary of the game(20 rounds)
{
	cout << endl;
	cout << "Summary" << endl;
	cout << "-------" << endl;
	cout << setw(15) << right << "Human wins: " << left << human_win << endl;
	cout << "Computer wins: " << left << comp_win << endl;
	cout << setw(15) << right << "Ties: " << left << ties << endl;
}

