/*
 * Brandon Denardo, 9/15/21 Program 3 stdio.h and ctype.h functions
 *
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //printf and scanf
#include<ctype.h> //toupper and tolower

 //FUNCTION PROTOTYPES
void Greeting(void);
//welcome the user
void InitialPractice(void);
//ask and get the initials from  the user

//display both the lowercase and uppercase versions of the initials

void CalculateGasPrice(void);
//ask and get the number of gallons (double)
//ask and get the price per gallon (double)
//calculate the total and display the result


int main()
{
	
	//welcome the user - call the greeting function
	Greeting();
	//call initial practice function
	InitialPractice();
	//call calculate gas price function
	CalculateGasPrice();
	//say goodbye to the user
	printf("Goodbye Thank You!");
	// do not forget to return SUCCESS (0)
	return 0;
	// type your command here...
}

//FUNCTION DEFINITIONS

void Greeting(void)
//welcome the user
{
printf("Welcome to the program\n");
}

void InitialPractice(void)
//ask and get the initials from  the user
//display both the lowercase and uppercase versions of the initials
{
	char initial, upper, lower;
	printf("Enter your initial: ");
	scanf(" %c", &initial);
	upper = toupper(initial);
	lower = tolower(initial);
	printf("The uppercase letter is : %c\n", upper);
	printf("The lowercase letter is: %c\n", lower);
}

void CalculateGasPrice(void)
{
	//ask and get the number of gallons (double)
	double gallons;
	printf("Enter the number of gallons: \n");
	scanf("%lf", &gallons);
	//ask and get the price per gallon (double)
	double price;
	printf("Enter the price of gas per gallon\n");
	scanf("%lf", &price);
		//calculate the total and display the result
	double total;
	total = gallons * price;
	printf("Your total is: %.2lf\n", total);
	
}


