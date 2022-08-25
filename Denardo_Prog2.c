/*
 * COP2220
 * Brandon Denardo, 9/8/21, Program 2 Input/Output
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf and scanf

	 int main()
 {
		 char inputLetter;

		 char uppercaseLetter, lowercaseLetter;

		 int inputNumber, product;

		 printf("Please input a letter: \n";

		 scanf(" %c", &inputLetter);

		 printf("Please input a number: \n");

		 scanf("%d", &inputNumber);

		 uppercaseLetter = toupper(inputLetter);

		 lowercaseLetter = tolower(inputLetter);

		 printf("The uppercase letter is %c\n", uppercaseLetter);

		 printf("The lowercase letter is %c\n", lowercaseLetter);

		 product = inputNumber * 5;

		 printf("The product is %.1d", product);


	 
	 return 0;
 }