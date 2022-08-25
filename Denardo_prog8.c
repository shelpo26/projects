/*COP 2220  (program 8) -
// jumbled word game
Brandon Denardo 11/24/21 Word game scramble program 8*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings 

#include<stdio.h> //for printf, scanf, and fscanf
#include<ctype.h> //for toupper function
#include<string.h> //for strlen and strcmp functions

#define SIZE 30//size of the character arrays is 30



//function prototypes
void Instructions();
//Welcome the user and display the instructions on how to play the game.

void PlayOneRound(char jumbled[], char solution[]);
//input: solution word and scrambled word
//plays one round ot the game

void PlayAnotherGame(char* againPtr);
//input: character (input/ouptput) parameter
//determines if the player would like to play again. 

void LowercaseWord(char word[]);
//input: a character array with a null character (string)
//sets all of the characters in a word to lowercase letters

void WonOrLost(int win);
//input a 1 or a 0
//tells the user they won if the input is 1 and they lost if the input is 0

int main()
{

	//declare character arrays here
	char jumbled[SIZE] = "", solution[SIZE] = "";
	//declare character and file pointer
	char again;
	FILE* inptr;

	//greet the user and disply the instructions
	Instructions();
	//connect to the input file
	inptr = fopen("jumbledWords.txt", "r");
	do {
		printf("Time to play a round! \n");
		//read 2 words from the file
		fscanf(inptr, " %s", jumbled);
		fscanf(inptr, " %s", solution);
	

		//change both jumbled and solution to lowercase letters
		LowercaseWord(jumbled);
		LowercaseWord(solution);
		//play a round of the game -call the PlayOneGame function
		PlayOneRound(jumbled, solution);
		//again?
		PlayAnotherGame(&again);
	} while (again == 'y' || again == 'Y'); //test


	//say goodbye
	printf("Goodbye, thank you for using the program!");
	//close the file pointer
	fclose(inptr);
	//return Success (0)
		return 0;
}

void Instructions()
//Welcome the user and display the instructions on how to play the game.
{
	//display a welcome message and game instructions
	printf("Welcome to the game.\n You will see the word in scrambled form. \n\nNext you will guess the word. \n\nIf you do not guess the word on the first try The first and last letters will be displayed\n\n");
}

void PlayOneRound(char jumbled[], char solution[])
//input: solution word and scrambled word
//plays one round of the game
{
	//declare variables
	int length, winorlose = 0, count = 1;
	char guess[SIZE];
	//get the length of the solution word
	length = strlen(solution);
	//the user gets a maximum of 3 guesses
	while(count <= 3 && winorlose == 0)
	{
	
		//display the number of letters and the jumbled word
		printf("The word has %d letters\n", length);
		printf("This is the jumbled word %s\n", jumbled);
		//get the guess
		printf("Guess the word: \n");
		printf("This is guess number %d\n", count);
		scanf(" %s", &guess);
		//change the guess to lowercase letters
		LowercaseWord(guess);
		//use strcmp to see if guess and solution match
		if (strcmp(solution, guess) == 0)
		{
			winorlose = 1;
		}
		//stop the loop if they match (DO NOT USE A break statement to stop the loop)

		//else the user did guess correctly
		else
		{
			printf("The first letter is %c and the last letter is %c\n", solution[0], solution[length - 1]);
		}
		count++;
	}
	//display the solution
	printf("The solution is %s\n", solution);
	//tell the user if they won or lost
	WonOrLost(winorlose);
}

void PlayAnotherGame(char* againPtr)
//input: character (input/output) parameter determines if the player would like to play again. 
{
	//again?
	printf("Would you like to play again Y or N?\n");
	scanf(" %c", againPtr);
}


void LowercaseWord(char word[])
//input: a character array with a null character (string)
//sets all of the characters in a word to lowercase letters
{
	//use strlen to get the length of the word
	int length, i;
	length = strlen(word);
	//use a loop to change all the letters of the word to lower case (tolower)
	for (i = 0; i < length; i++)
	{
		word[i] = tolower(word[i]);
	}
}

void WonOrLost(int win)
//input a 1 or a 0
//tells the user they won if the input is 1 and they lost if the input is 0

{
	//let the user know if they won or lost the round
	if (win == 1)
	{
		printf("You won! Great job!\n");
	}

	else if(win == 0)
	{
		printf("Sorry, you did not guess the word you lost\n");
	}
	else
	{
		printf("Not reecognized\n");
	}
}