/*COP 2220  program 7 - larger gas selection program
//Brandon Denardo 11/10/21 COP 2220*/

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes

//Function from program 4
void Greeting();
//welcome the user to the gas station app

//Function from program 6
void ProcessSelection(char selection, double* balancePtr);
//input: the user's selection (input/output parameter)
//display the program options and get the users selection
//use an input/output parameter for the selection

//Function from program 6
void ViewAndGetSelection(char* selectionPtr);
//input: the user's selection by copy (input parameter)
//input: the account balance (input/output parameter)
//display a message that the selection has been entered
//display the balance when the user enters 'B'
//allow the user to add money to the account when the user enters 'A'
//complete a purchase when the user enters 'G'

void DisplayBalance(double accountBalance);


void DisplayGasPrices();
//display the gas choices and related item number

void GetGasChoice(int* itemPtr);
//input: users choice is set by the input/output parameter

void SetGallonPrice(int itemNumber, double* pricePtr);
//input: item number
//input: price is set by the input/output parameter

void CalculateTotal(double pricePerGallon, double* totalPtr);
//input price per gallon
//declare, ask and get the number of gallons
//calculate the total
//input/output parameter for the total


//Function from program 4
double AddMoney(doubleaccountBalance); 
//input: amount of money in the account
//displays the amount of money available in the account
//allows the user to add money to the account
//returns the updated balance after the money has been added

//Function from program 4
double CheckForEnoughMoney(double accountBalance, double total);
//input: amount of money in the account and the transaction total
//gets money from the user until the user has enough to make the purchase
//make the purchase and returns the remaining balance


int main()
{
	char choiceInMain;
	double balanceInMain = 0.00;

	//inPtr to read from the file
	FILE* inPtr;

	//outPtr to write to the file
	FILE* outPtr;

	//connect to the file
	inPtr = fopen("gasAccountBalance.txt", "r");
	//get the account balance from the file. use fscanf!
	fscanf(inPtr, "%lf", &balanceInMain);
	//greet the user
	Greeting();
	//view and get the selection
	ViewAndGetSelection(&choiceInMain);
	//change the selection to lower case
	choiceInMain = tolower(choiceInMain);
		//make sure the user did not enter q to quit
		while (choiceInMain != 'q')
		{
			//process the selection
			ProcessSelection(choiceInMain, &balanceInMain);
			//view and get the next selection
			ViewAndGetSelection(&choiceInMain);
			//change the selection to lower or upper case
			choiceInMain = tolower(choiceInMain);
		}

	printf("\nYou have $%.2f left in your account for next time.\n", balanceInMain);
	printf("\nsaving the amount in the file . . .\n");

	outPtr = fopen("gasAccountBalance.txt", "w");
	fprintf(outPtr, "%f", balanceInMain);

	//say goodbye to the user
	printf("Goodbye thank you for using this app");
	//close the file pointers
	fclose(inPtr);
	fclose(outPtr);
	// do not forget to return SUCCESS
	return 0;
}

//Function from program 4
void Greeting()
//welcome the user to the gas program
{
	printf("Welcome to the gas selection app");
}

//Function from program 6
void ViewAndGetSelection(char* selectionPtr)
//input: the user's selection (input/output parameter)
//display the program options and get the users selection
//use an input/output parameter for the selection
{
	printf("The menu options are displayed: \n");

	printf("Enter v to view the gas prices\n");

	printf("Enter g to purchase gas\n");

	printf("Enter b to view your account balance\n");

	printf("Enter a to add money to your account\n");

	printf("Enter q to quit\n");

	printf("Enter your selection: ");
	scanf(" %c", &*selectionPtr);

	*selectionPtr = toupper(*selectionPtr);

}

//Function from program 6
void ProcessSelection(char selection, double* balancePtr)
//input: the user's selection by copy (input parameter)
//input: the account balance (input/output parameter)
//display a message that the selection has been entered
//display the balance when the user enters 'b'
//allow the user to add money to the account when the user enters 'u'
{
	double amount = 0.0;
	if (selection == 'v')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("Here you will display the gas prices\n");
		DisplayGasPrices();
		printf("----------------------------------\n");
	}
	//add the rest of the conditions
	else if (selection == 'g')
	{
		int itemPtr;
		double pricePtr, total;
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("Here you will purchase gas\n");
		GetGasChoice(&itemPtr);
		SetGallonPrice(itemPtr,&pricePtr);
		CalculateTotal(pricePtr, &total);
		*balancePtr = CheckForEnoughMoney(total, *balancePtr);
		DisplayBalance(*balancePtr);
		printf("----------------------------------\n");
	}
	else if (selection == 'b')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("Your current account balance is $%.2f\n", *balancePtr);
		printf("----------------------------------\n");
	}
	else if (selection == 'a')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("Here you will add money to your account\n");
		printf("How much would you like to add?: ");
		scanf("%lf", &amount);
		*balancePtr = *balancePtr + amount;
		printf("\n----------------------------------\n");

	}
	else
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("That is an invalid entry\n");
		printf("----------------------------------\n");
	}

}

void DisplayGasPrices()
//display the gas choices and related item number
{
	printf("-----------------------------------------\n");
	printf("Here are the gas options\n");
	printf("1. Regular\t$2.35 per gallon\n");
	//add the rest of the prices
	printf("-----------------------------------------\n");
	printf("2. Midgrade\t$2.69 per gallon\n");

	printf("-----------------------------------------\n");
	printf("3. Premium\t$2.99 per gallon\n");

	printf("-----------------------------------------\n");
	printf("4. Diesel\t$2.60 per gallon");

	printf("-----------------------------------------\n");
	printf("5. E85\t\t$2.09 per gallon\n");
}

void GetGasChoice(int* itemPtr)
//input: users choice is set by the input/output parameter
{
	printf("\nselect the fuel option by entering the item number: ");
	scanf("%d", itemPtr);
}

void SetGallonPrice(int itemNumber, double* pricePtr)
//input: item number
//input: price is set by the input/output parameter
{
	if (itemNumber == 1)*pricePtr = 2.35;
	else if (itemNumber == 2)*pricePtr = 2.69;
	else if (itemNumber == 3)*pricePtr = 2.99;
	else if (itemNumber == 4)*pricePtr = 2.60;
	else if (itemNumber == 5)*pricePtr = 2.09;
	//add the other item numbers
	else
	{
		printf("\nyou did not enter a 1,2,3,4, or 5");
		*pricePtr = 0.00;
	}
}

void CalculateTotal(double pricePerGallon, double* totalPtr)
//input price per gallon
//declare, ask and get the number of gallons
//calculate the total
//input/output parameter for the total
{
	// input price per gallon
	//declare, ask and get the number of gallons
	double gallons;
	printf("How many gallons do you need?");
	scanf("%lf", &gallons);
	//calculate the total
	*totalPtr = gallons * pricePerGallon;
	printf("The total is %.2f\n", *totalPtr);
}

void DisplayBalance(double balance)
//input: amount of money in the account
//displays the amount of money available in the account
{
	printf("Your account balance is: %.2f\n", balance);
}

//Function from program 4
double AddMoney(double accountBalance)
//input: amount of money in the account
//displays the amount of money available in the account
//allows the user to add money to the account
//returns the updated balance after the money has been added
{
	DisplayGasPrices(accountBalance);
	printf("Enter the amount to add: ");
	double addbalance;
	scanf("%lf", &addbalance);
	//return the accountBalance
	return accountBalance + addbalance;
}

//Function from program 4
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