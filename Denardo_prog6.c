/*COP 2220  (program 6) -
//Brandon Denardo 11/1/21 Gas program adding features*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings 

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes

void Greeting();
//welcome the user to the gas station app

void ViewAndGetSelection(char* selectionPtr);
//input: the user's selection (input/output parameter)
//display the program options and get the users selection
//use an input/output parameter for the selection

void ProcessSelection(char selection, double* balancePtr);
//input: the user's selection by copy (input parameter)
//input: the account balance (input/output parameter)
//display a message that the selection has been entered
//display the balance when the user enters 'b'
//allow the user to add money to the account when the user enters 'u'


int main()
{
	char choiceInMain;
	double balanceInMain = 20.00;

	//call the greeting function

	//view and get the selection - function call
	ViewAndGetSelection(&choiceInMain);
	printf("\nYou entered : %c\n", choiceInMain);
	//change the selection to lower or upper case
	choiceInMain = tolower(choiceInMain);
	//make sure the user did not enter q to quit
	while (choiceInMain != 'q')
	{
		//process the selection
		ProcessSelection(choiceInMain, &balanceInMain);
		//view and get the next selection
		ViewAndGetSelection(&choiceInMain);
		printf("\nYou entered : %c\n", choiceInMain);
		//change the selection to lower or upper case
		choiceInMain = tolower(choiceInMain);

	}

	//say goodbye to the user
	printf("Thank you for using the program, goodbye!");
	// do not forget to return SUCCESS
	return 0;
}

//function definitions

void Greeting()
//welcome the user to the gas program
{
	printf("Welcome to the gas selection");
}


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
	scanf(" %c", selectionPtr);

	selectionPtr = toupper(selectionPtr);

}

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
		printf("----------------------------------\n");
	}
	//add the rest of the conditions
	else if (selection == 'g')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("Here you will purchase gas\n");
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