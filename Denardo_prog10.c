//program 10 (larger program)
//gas purchase list
//Brandon Denardo, 12/9/21 Gas purchase strings, arrays, structs
//spring 2021


#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 50 //size of the list
#define SIZE2 20//size of character arrays

typedef struct {
	//ADD the rest of the fields here
	char gasType[SIZE2];
	char lastName[SIZE2];
	char firstName[SIZE2];
	int itemNumber;
	int numGallons;
	double totalCost;
	double pricePerGallon;

}gasPurchase;

//function prototypes

void Greeting();
//Greets the user

//add the rest of the prototypes here
void RunMenu(char* selectionPtr);
//input: the user's selection (input/output parameter)
//display the program options and get the users selection (A, P, S, or Q)
//use an input/output parameter for the selection

void ProcessSelection(char selection, gasPurchase list[], int* count);
//input: the user's selection by copy (input parameter)
//input/output: the gasPurchase list and count 
//display a message that the selection has been entered
//call the required function for each selection (A, P, or S)

void AddTransaction(gasPurchase list[], int* count);
//input/output: the gasPurchase list and count 
//add a gas purchase transaction to the list and 
//add 1 to the "value at" count only if the itemNumber is valid 

int SetPrice(gasPurchase list[], int count);
//input/output: the gasPurchase list
//input count by copy (input parameter)
//checks to see if the itemNumber is valid
//sets the pricePerGallon and gasType
//returns a 1 if the itemNumber is valid and returns 0 if the itemNumber is not valid

void CalculateTotal(gasPurchase list[], int count);
//input/output: the gasPurchase list
//input count by copy (input parameter)
//and Calculates the totalCost based on the itemNumber

void PrintList(gasPurchase list[], int count);
//input/output: the gasPurchase list
//input count by copy (input parameter)
//prints the contents of the list onto the screen 

void PrintE85_purchases(gasPurchase list[], int count);
//input/output: the gasPurchase list
//input count by copy (input parameter)
//Searches the array and prints the name and 
//totalCost of any E85 purchases(list and count)

void PrintDiesel_purchases(gasPurchase list[], int count);
//input/output: the gasPurchase list
//input count by copy (input parameter)
//Searches the array and prints the name and 
//totalCost of any Diesel purchases(list and count)



int main()
{
	char menu = 'y';
	//greet the user
	Greeting();
	//declare the gas purchase list
	gasPurchase list[SIZE];
	//declare and initialize count to 0
	int count = 0;
	//declare a character for the menu choice
	char menuchoice;

	//run the menu choices
	RunMenu(&menuchoice);
	//begin the while or while loop
	while (menuchoice != 'q' && menuchoice != 'Q') //test
	{
		//process the selection
		ProcessSelection(menuchoice, list, &count);
		//be sure to update the while loop (call run menu function to get the selection)
		 //update
		RunMenu(&menuchoice);
	}

	//say goodbye
	printf("Thank you for using the program, goodbye!");
	return 0;
}


//function definitions

void Greeting()
//Greets the user
{
	printf("Welcome to the gas list program!\nYou will enter a transaction, last name and gas type.\nMake sure to enter valid item numbers so your total can be calculated correctly.");
}

void RunMenu(char* selectionPtr)
//input: the user's selection (input/output parameter)
//display the program options and get the users selection (A, P, S, or Q)
//use an input/output parameter for the selection
{
	printf("\n------------------------------------------------------------------------------------\n");
	printf("What would you like to do?\n");
	printf("Please select from the following options:\n\n");
	printf("Enter 'A' to add a gas purchase entry.\n");
	printf("Enter 'P' to print the list.\n");
	printf("Enter 'E' to print the full name and the total cost of any E85 gas purchase.\n");
	printf("Enter 'D' to print the full name and the total cost of any diesel gas purchase.\n");
	printf("Enter 'Q' to quit.\n");

	scanf(" %c", selectionPtr);
	*selectionPtr = tolower(*selectionPtr);
}

void ProcessSelection(char selection, gasPurchase list[], int* count)
//input: the user's selection by copy (input parameter)
//input/output: the gasPurchase list and count 
//display a message that the selection has been entered
//call the required function for each selection (A, P, or S)
{
	if (selection == 'a')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);

		//ask and get the first and last name
		printf("\nEnter the customer last name: ");
		scanf("%s", list[*count].lastName);

		//call the Add Transaction function
		AddTransaction(list,*count);
		//keep track of how manyitems are in the list
		printf("\nThere are now %d gas purchases in the list", *count);

	}
	//add the other options
	else if (selection == 'p')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);

		PrintList(list, count);
	}

	else if (selection == 'e')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);

		PrintE85_purchases(list, count);
	}

	else if (selection == 'd')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);

		PrintDiesel_purchases(list, count);
	}

	else if (selection == 'q')
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);

		return 0;
	}

	else
	{
		printf("\n----------------------------------\n");
		printf("You selected %c\n", selection);
		printf("\nThat is not a valid option\n");

	}
}


void AddTransaction(gasPurchase list[], int* count)
//input/output: the gasPurchase list and count 
//add a gas purchase transaction to the list and 
//add 1 to the "value at" count only if the itemNumber is valid 
{
	int validNumber = 1; // do not know if the user will enter a valid item number

	//list the item numbers and gas types
	printf("\n\nHere are the gas choices\n");
	printf("1. Regular    $2.35 per gallon\n 2. Midgrade    $2.69 per gallon\n 3. Premium    $2.99 per gallon\n 4. Diesel    $2.60 per gallon\n 5. E85     $2.09 per gallon\n");
	//ask and get the item number
	printf("\nPlease enter the item number:\n");
	scanf("%d", &list[*count].itemNumber);

	//ask and get the number of gallons
	printf("How many gallons do you need?\n");
	scanf("%d", &list[*count].numGallons);
	
	//call the set Price function
	validNumber = SetPrice(list, *count);

	if (validNumber == 1)
	{
		//calculate the total (call the function)
		CalculateTotal(list, *count);
		*count = *count + 1;
		printf("\nThe gas purchase transaction has been added to the list\n");

	}
	else// not a valid item number
	{
		printf("\nYou did not enter a valid item number, the gas purchase transaction will not be added to the list\n");
	}

}



int SetPrice(gasPurchase list[], int count)
//input/output: the gasPurchase list
//input count by copy (input parameter)
//checks to see if the itemNumber is valid
//sets the pricePerGallon and gasType
//returns a 1 if the itemNumber is valid and returns 0 if the itemNumber is not valid
{
	int returnValue = 1; // do not know if the user will enter a valid item number

	if (list[count].itemNumber == 1)
	{
		list[count].pricePerGallon = 2.35;
		strcpy(list[count].gasType, "Regular");
	}
	//add item numbers 2 through 5
	else if (list[count].itemNumber == 2)
	{
		list[count].pricePerGallon = 2.69;
		strcpy(list[count].gasType, "Midgrade");
	}
	else if (list[count].itemNumber == 3)
	{
		list[count].pricePerGallon = 2.99;
		strcpy(list[count].gasType, "Premium");
	}
	else if (list[count].itemNumber == 4)
	{
		list[count].pricePerGallon = 2.60;
		strcpy(list[count].gasType, "Diesel");
	}
	else if (list[count].itemNumber == 5)
	{
		list[count].pricePerGallon = 2.09;
		strcpy(list[count].gasType, "E-85");
	}
	else
	{
		printf("\nnot recognized\n");
		returnValue = 0; //the user did not enter a valid item number
	}
	//return a 1 or a 0
	return returnValue;
}


void CalculateTotal(gasPurchase list[], int count)
//input/output: the gasPurchase list
//input count by copy (input parameter)
//and Calculates the totalCost based on the itemNumber
{
	//calculate the total
	list[count].totalCost = list[count].numGallons * list[count].pricePerGallon;
}


void PrintList(gasPurchase list[], int count)
//input/output: the gasPurchase list
//input count by copy (input parameter)
//prints the contents of the list onto the screen 
{
	int i;
	printf("\n-----------------------------------------------------\n");
	if (count == 0)
	{
		printf("\nThe list is empty!\n");
	}
	//use a loop to print the list
	for (i = 0; i < count; i++)
	{
		printf("The first name is: %s", list[i].lastName);
		printf("\nThe last name is: %s", list[i].firstName);
		printf("\nThe gas type is: %s", list[i].gasType);
		printf("\nThe # of gallons is: %d", list[i].numGallons);
		printf("The price per gallon is: %.2f", list[i].pricePerGallon);
		printf("The total is: %.2f", list[i].totalCost);
	}
}





void PrintE85_purchases(gasPurchase list[], int count)
//input/output: the gasPurchase list
//input count by copy (input parameter)
//Searches the array and prints the name and 
//totalCost of any E85 purchases(list and count)
{
	int i;
	printf("\n-----------------------------------------------------\n");
	printf("\nE85 purchases, item number 5:\n");
	if (count == 0)
	{
		printf("\nThe list is empty!\n");
	}
	//use a loop to search the list
	for(i = 0; i < count; i++)
	{
		if (list[i].itemNumber == 5)
		{
			//print the customer first and last name and total cost
			printf("The first name is: %s", list[i].lastName);
			printf("\nThe last name is: %s", list[i].firstName);
			printf("The total is: %.2f", list[i].totalCost);
		}
	}

}

void PrintDiesel_purchases(gasPurchase list[], int count)
//input/output: the gasPurchase list
//input count by copy (input parameter)
//Searches the array and prints the name and 
//totalCost of any Diesel purchases(list and count)
{
	int i;
	printf("\n-----------------------------------------------------\n");
	printf("\nDiesel purchases, item number 4:\n");
	if (count == 0)
	{
		printf("\nThe list is empty!\n");
	}
	//use a loop to search the list
	for (i = 0; i < count; i++)
	{
		if (list[i].itemNumber == 4)
		{
			//print the customer first and last name and total cost
			printf("The first name is: %s", list[i].lastName);
			printf("\nThe last name is: %s", list[i].firstName);
			printf("The total is: %.2f", list[i].totalCost);
		}
	}

}
