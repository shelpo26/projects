/*COP 2220  (program4.c) - larger program */
//Brandon Denardo, 9/27/21, Prog 4 gas choice longer program

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //for printf and scanf

//function prototypes

void Greeting(void);
//welcome the user to the gas purchasing app

int DisplayGasSelections();
//display the gas choices and related item number
//declare, ask, get, and return the item number

double GallonPrice(int itemNumber);
//input: item number
//returns the price per gallon of the selected type of fuel

double CheckForEnoughMoney(double accountBalance, double total);
//input: amount of money in the account and the transaction total
//gets money from the user until the user has enough to make the purchase
//make the purchase and returns the remaining balance

double AddMoney(double accountBalance);
//input: amount of money in the account
//displays the amount of money available in the account
//allows the user to add money to the account
//returns the updated balance after the money has been added

void DisplayBalance(double accountBalance);
//input: amount of money in the account
//displays the amount of money available in the account


int main()
{
	//declare variables here
	double accountBalance, total, price, gallons;
	int itemNumber;
	char answer;
	accountBalance = 20;
	//greet the user - Greeting function call
	Greeting();
	//display the account balance - DisplayBalance function call
	DisplayBalance(accountBalance);
	//get the item number -  DisplayGasSelections function call
	itemNumber = DisplayGasSelections();
	//get the price per gallon - GallonPrice function call
	price = GallonPrice(itemNumber);
	//ask and get the number of gallons
	printf("\nEnter the number of gallons if gas you need : ");
	scanf("%lf", &gallons);
	//calculate the total
	total = price * gallons;
	//check if there is enough money - CheckForEnoughMoney function call
	accountBalance = CheckForEnoughMoney(accountBalance, total);
	//ask and get a character from the user when they are ready to see the remaining balance
	printf("\nDo you want to see your remaining balance? (y/n): ");
	scanf(" %c", &answer);
	if (answer == 'y')
	{
		//display remaining account balance
		DisplayBalance(accountBalance);
	}

	//thank the user
	printf("\nThank you for using the calculator!");
	//say goodbye to the user
	printf("\nHave a great day!\n\n");

	// do not forget to return SUCCESS
	return 0;
	// type your command here...
}


//function definitions
void Greeting(void)
//welcome the user to the gas purchasing app
{
	printf("Welcome to the gas purchasing app\n");

}

int DisplayGasSelections()
//display the gas choices and related item number
//declare, ask, get, and return the item number
{
	printf("\n\nHere are the gas choices\n");
	printf("1. Regular    $2.35 per gallon\n 2. Midgrade    $2.69 per gallon\n 3. Premium    $2.99 per gallon\n 4. Diesel    $2.60 per gallon\n 5. E85     $2.09 per gallon\n");
	int gaschoice;
	printf("Enter the number of your gas choice (1-5): ");
	scanf("%d", &gaschoice);
	return gaschoice;

}

double GallonPrice(int itemNumber)
//input: item number
//returns the price per gallon of the selected type of fuel
{
	switch (itemNumber)
	{
	case 1:
		return 2.35;
	case 2:
		return 2.69;
	case 3:
		return 2.99;
	case 4:
		return 2.60;
	case 5:
		return 2.09;
	default:
		return 0;
	}

}


double CheckForEnoughMoney(double accountBalance, double total)
//input: amount of money in the account and the transaction total
//gets money from the user until the user has enough to make the purchase
//make the purchase and returns the remaining balance
{
	while (accountBalance < total)//not enough
	{
		accountBalance = AddMoney(accountBalance);
		printf("\n-------------------------------------------------------");
		printf("\nThe total is $%.2f and you have $%.2f in your account\n\n", total, accountBalance);
	}
	//make the transaction and return the accountBalance
	return accountBalance - total;

}

double AddMoney(double accountBalance)
//input: amount of money in the account
//displays the amount of money available in the account
//allows the user to add money to the account
//returns the updated balance after the money has been added
{
	DisplayBalance(accountBalance);
	printf("Enter the amount to add: ");
	double addbalance;
	scanf("%lf", &addbalance);
	//return the accountBalance
	return accountBalance + addbalance;
}

void DisplayBalance(double accountBalance)
//input: amount of money in the account
//displays the amount of money available in the account
{
	printf("Your account balance is: %.2f\n", accountBalance);
}