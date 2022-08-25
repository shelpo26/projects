/************************************************************************************************************************

Name: Brandon Denardo                                Z#:Z23596879
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 2/15/22                     Due Time:11:59pm
Total Points: 10
Assignment #: 4

Description: This program will get an amount of cents from the user between 0 and 100. Then tell what coins to give out 
for any amount of change from 1 to 99 cents. Given in quarters, dimes and pennies, by using functions to make calculations for each coin value.

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// function prototypes
void compute_coins(int coin_value, int& num, int& amount_left);
void userinput(int& useramount);


// function definitions
void compute_coins(int coin_value, int& num, int& amount_left)
{
	num = amount_left / coin_value;
	amount_left = amount_left - (num *coin_value);
}

void userinput(int& amount_left) // get input from user
{
	cout << "Enter a value between 0 and 100 (exclusive):" << endl;
	cin >> amount_left;
	if (amount_left < 1 || amount_left > 99)
	{
		cout << "Enter a value between 0 and 100 (exclusive):" << endl;
		cin >> amount_left;
	}
}


int main()
{
	int coin_value, num, amount_left;
	char answer;
	do {
		userinput(amount_left);
		cout << amount_left << "cent(s) can be given as"; // the amount in cents
		cout << endl;
		// calculations
		compute_coins(25, num, amount_left);
		cout << num << "quarter(s)";
		cout << endl;
		compute_coins(10, num, amount_left);
		cout << num << "dime(s)";
		cout << endl;
		cout << amount_left << "pennie(s)";
		cout << endl;
		//ask user to continue or not
		cout << "Do you want to continue? (y or n)";
		cin >> answer;
		cout << endl;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}