/*COP 2220  (program 5) -
Brandon Denardo 10/11/21 Gas program adding features */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings 

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes

void Greeting();
//welcome the user to the gas station app

char ViewAndGetSelection();
//display the program options, declare, ask, get, and return the selection

void ProcessSelection(char selection);
//input: the user's selection as an input parameter (copy)
//display a message that the selection has been entered



int main()
{
	char choiceInMain;
	//greet the user - Greeting function call
	Greeting();


	//view and get the selection - loop initalization 
	choiceInMain = ViewAndGetSelection();
	//change the selection to lower or upper case
	choiceInMain = tolower(choiceInMain);

	//make sure the user did not enter q to quit
	while (choiceInMain != 'q') //test
	{
		//process the selection
		ProcessSelection(choiceInMain);
		//view and get the next selection - loop update
		choiceInMain = ViewAndGetSelection();
		//change the selection to lower or upper case
		choiceInMain = tolower(choiceInMain);
	}


	//say goodbye to the user
	printf("\nThank you, goodbye!\n");
	// do not forget to return SUCCESS
	return 0;
}

//function definitions
void Greeting()
//welcome the user to the gas station app
{
	printf("Welcome to the program!\n\n");
}

char ViewAndGetSelection()
//display the program options, declare, ask, get, and return the selection
{
	char letter;
	printf("Enter v to view the gas prices\n");

	printf("Enter g to purchase gas\n");

	printf("Enter b to view your account balance\n");

	printf("Enter a to add money to your account\n");

	printf("Enter q to quit\n");

	scanf(" %c", &letter);
	return letter;
}

void ProcessSelection(char selection)
//input: the user's selection as an input parameter (copy)
//display a message that the selection has been entered

{
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
		printf("Here you will view you account balance\n");
		printf("----------------------------------\n");
	}
	else if (selection == 'a')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("Here you will add money to your account\n");
		printf("----------------------------------\n");
	}

	else
	{
		printf("\n----------------------------------\n");
		printf("That is an invalid entry\n");
		printf("----------------------------------\n");
	}
}
