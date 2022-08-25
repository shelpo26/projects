/*
 * Brandon Denardo, 8/19/21, Day 2 Bootcamp Code
 *
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler

#include<stdio.h> //for printf and scanf

int main(void)
{
	//start execution
	int number; // whole numbers scanf %d
	char letter; // any characters scanf space%c
	double averages; // floating points 2.0 scanf %lf

	printf("\"Hello World!\"");

	printf("\nEnter a number:");
	scanf("%d", &number);

	printf("Enter you initial:");
	scanf(" %c", &letter);

	printf("Enter a floating point number:");
	scanf("%lf", &averages);
}