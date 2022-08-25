/*
 * COP2220 Intro to Programming in C
 * Brandon Denardo 12/2/21 Prog 9 Structs jumbledGame
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler

#include <string.h>
#include <stdio.h>
#define SIZE 25

typedef struct {
	//add the variables here
	char jumbled[SIZE];
	char solution[SIZE];
	int win;
}jumbleGame; ////CHANGE TO jumbleGame

//Function Prototypes

// fills the data fields of a jumbleGame instance
//returns the filled jumbleGame 
jumbleGame FillGame(); //CHANGE TO FillGame

//fills the data fields of a jumbleGame instance
//by reference using a pointer to a jumbleGame
void FillGamePtr(jumbleGame* gamePtr); //CHANGE TO FillGamePtr

//fills an array of games
void FillGameArray(jumbleGame arrayJ[], int* size); //CHANGE TO FillGameArray

//displays one game
void DisplayGame(jumbleGame anyGame); //CHANGE TO DisplayGame


//from here down make all the changes from card to jumbleGame
int main()
{

	//Declare variables jumbleGame
	jumbleGame myGame1, myGame2, myGame3; //myGame1, myGame2, myGame3
	jumbleGame gameList[SIZE];  //gameList
	int gSize;
	int i;

	//Fill structures with a function
	myGame1 = FillGame();
	myGame2 = FillGame();
	myGame3 = FillGame();

	//print using display function
	printf("\n---------Display myGame1\n");
	DisplayGame(myGame1);
	printf("\n---------Display myGame2\n");
	DisplayGame(myGame2);

	//Fill structure using pointers and display it
	FillGamePtr(&myGame3);
	printf("\n---------Display myGame3\n");
	DisplayGame(myGame3);

	//Fill the array with the function
	printf("\n---------Fill array game list\n");
	FillGameArray(gameList, &gSize);

	//display an array of jumble games
	printf("\n---------Display array game list\n");
	for (i = 0; i < gSize; i++)
	{
		DisplayGame(gameList[i]);
	}

	return 0;
}

//Function Definitions


// fills the data fields of a jumble instance
//returns the temp word
jumbleGame FillGame()
{
	//Declare local variables
	jumbleGame tempG;
	//prompt and get information
	printf("\nplease enter the jumbled word:  ");
	scanf("%s", tempG.jumbled);
	//print to check
	printf("The jumbled word is:  %s\n", tempG.jumbled);

	//prompt and get information
	printf("\nplease enter the solution word:  ");
	scanf("%s", tempG.solution);
	//print to check
	printf("The solution word is:  %s\n", tempG.solution);

	//prompt and get information
	printf("\nplease enter the value of win (1 or 0):  ");
	scanf("%d", &tempG.win);
	printf("Win value is:  %d\n", tempG.win);
	return tempG;
}



//displays one jumbleGame
void DisplayGame(jumbleGame anyGame)
{
	printf("\n\nJumbled word:  %s\n", anyGame.jumbled);
	printf("Solution word:  %s\n", anyGame.solution);
	printf("Win value:  %d\n", anyGame.win);
}


//fills the data fields of a game instance
//by reference using a pointer to a word
void FillGamePtr(jumbleGame* gamePtr)
{
	//prompt and get information
	printf("\nplease enter the jumbled word:  ");
	scanf("%s", (*gamePtr).jumbled);

	//prompt and get information
	printf("\nplease enter the solution word:  ");
	scanf("%s", (*gamePtr).solution);

	//prompt and get information
	printf("\nplease enter the win value (1 or 0):  ");
	scanf("%d", &(*gamePtr).win);
}


//fills an array of letters
void FillGameArray(jumbleGame arrayJ[], int* size)
{
	int i;
	//prompt the user
	printf("\nenter the size of the word:  ");
	scanf("%d", size);

	//print to check
	printf("size:  %d\n", *size);

	for (i = 0; i < *size; i++)
	{
		printf("enter solution:  ");
		scanf("%s", arrayJ[i].solution);

		printf("enter jumbled word:  ");
		scanf("%s", arrayJ[i].jumbled);

		printf("enter win value(1 or 2):  ");
		scanf("%d", &arrayJ[i].win);
	}
}