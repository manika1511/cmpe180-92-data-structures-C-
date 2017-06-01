/* Assignment #4 : Big Pi Extra Credits
 * Author: Manika Kapoor
 * Student ID: 011539203
*/

#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace std;

const int MAX_ITERATIONS = 10;
const int PLACES         = 1000000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

void print(const mpf_t& pi);
//Function to print the PLACES decimal digits of pi
//Precondition : mpf_t type variable pi contains value of pi upto PLACES decimal digits
//Postcondition: pi value upto PLACES decimal digits
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits
    mpf_t pi;       //variable to store value of pi
    mpf_init(pi);   //initializing pi to 0

    mpf_t a;        //variable to store variable 'a' in Borwein's Quartic algorithm
    mpf_init(a);    //initializing a to 0
    mpf_t y;        //variable to store variable 'y' in Borwein's Quartic algorithm
    mpf_init(y);    //initializing y to 0
    mpf_t a_next;   //variable to store next value of 'a'
    mpf_t y_next;   //variable to store next value of 'y'
    mpf_init(a_next);//initializing a_ext to 0
    mpf_init(y_next);//initialising y_next to 0

    mpf_t v, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16; //variables to store intermediary computational values

    //initialising the intermediary variables to 0
    mpf_init(v);
    mpf_init(v1);
    mpf_init(v2);
    mpf_init(v3);
    mpf_init(v4);
    mpf_init(v5);
    mpf_init(v6);
    mpf_init(v7);
    mpf_init(v8);
    mpf_init(v9);
    mpf_init(v10);
    mpf_init(v11);
    mpf_init(v12);
    mpf_init(v13);
    mpf_init(v14);
    mpf_init(v15);
    mpf_init(v16);

    //declaring unsigned integer variables used to compute values of 'a', 'a_next', 'y', 'y_next' and initialising them
    mpir_ui two = 2;
    mpir_ui one = 1;
    mpir_ui ten = 10;
    mpir_ui four = 4;

    mpf_sqrt_ui (v, two);        //storing square root of 2 in v
    mpf_sub_ui (v1, v, one);     //storing (√(2)-1) in v1
    mpf_pow_ui (v2, v1, two);    //storing square of v1 in v2

    mpf_mul_ui (a, v2, two);     //storing product of 2 and v2 in 'a' so a= 2*((√(2)-1))^2

    mpf_sub_ui (y, v, one);      //storing (√(2)-1) in 'y' so y = (√(2)-1)


    // Loop MAX_ITERATIONS times to calculate PLACES number of decimal digits in value of pi
    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {
        /*Calculating a_next and y_next according to Borwein's Quartic algorithm */
        //Calculating 2^(k+1) 
        int k, l;            //variable to store intermediary values 
        k = (2*i)+1;         //calculating a variable to be used in calculating a_next
        l = pow(2,k);        //calculating a variable to be used in calculating a_next
        mpir_ui pow = l;     //declaring and initialising mpir unsigned int type variable 

        /*Calculating value of y_next */
        mpf_pow_ui (v3, y, four);
        mpf_ui_sub (v4, one, v3);
        mpf_sqrt (v5, v4);
        mpf_sqrt (v6, v5);
        mpf_ui_sub (v7, one, v6);
        mpf_add_ui (v8, v6, one);
        mpf_div (y_next, v7, v8);

        /*Calculating value of a_next */
        mpf_add_ui (v9, y_next, one);
        mpf_pow_ui (v10, v9, four);
        mpf_mul (v11, a, v10);
        mpf_pow_ui (v12, y_next, two);
        mpf_add (v13, v12, y_next);
        mpf_add_ui (v14, v13, one);
        mpf_mul (v15, v14, y_next);
        mpf_mul_ui (v16, v15, pow);
        mpf_sub (a_next, v11, v16);

        mpf_init_set (a, a_next);          //setting a to a_next
        mpf_init_set (y, y_next);          //setting y to y_next

    }

    mpf_ui_div (pi, one, a);            //storing value of pi by inversing a
    print (pi);                         //function call to print pi upto PLACES no. of digits
    return 0;
}

void print(const mpf_t& pi)            //function to print PLACES decimal digits of pi
{
    char* str;        //string to store output as character array
    mp_exp_t exp;     //variable to store exponent
    str = mpf_get_str (str, &exp, BASE, size_t (PRECISION+2), pi); //storing value of pi as a string in str
    char pi_final[PLACES+2] = {0};     //char array to store pi string
    strcpy(pi_final, str);             //copying str to pi
    cout << "Pi = " << pi_final[0];    //printing 3 
    cout <<".";                        //printing the decimal
    int k = 0;                         //variable to count number of rows printed 
    
    /* Printing according to the required format. 100 words per line and 10 digits in a column */ 
    for (int i = 1; i < PRECISION; i++) 
    {
        if (i%10 == 0)                             //Every 10th digit 
        {
            if (i%100 ==0)                          
            {
                cout << pi_final[i];               
                cout << "\n";                      //print a new line after printing every 100th digit 
                k++;                               //incrementing the number of rows
                if (k%5 == 0)                      //if numbers of rows divisible by 5 print a new line
                {
                    cout << "\n";                   
                }
                if (k%25 == 0 )                    //printing two new lines after 25 rows         
                {
                    cout << "\n";
                }
                cout << "       ";
            }
            else
            {
                cout << pi_final[i];               //print " " after every 10th digit
                cout << " ";
            }
        }
        else
        {
            cout << pi_final[i];                   //otherwise just print the digit 
        }
    }
}
