// David Henry -1007604
//
// libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

// prototypes
int word_selector();	//random number to select a random word
int print_hangman(int);	// prints hangman image
int word_print(int, int);	//prints word with blanks and hangman image

// variables
char words[][10] = { "dog", "cow", "computer", "onion", "house",
	"apple", "pizza", "soda", "chicken", "potato" };
//to hold the letter guessed
char letter[10];

int i, word_index, random_number;
int correct = 0, guessed = 0;
int word_hidden[10];	//[0,0,0,0,0,0,0,0,0,0,0]
int guess_check;
int hangman = 0;
int playing = 1;
int chances = 5;

// main
int main()
{
	// clear screen at start
	system("cls");

	// value is generated to choose the word
	word_index = word_selector();
	int word_length = strlen(words[word_index]);	//length of the word

	// intro screen with word list
	print_hangman(10);
	printf("\n Press any key to begin...");
	getch();
	system("cls");

	// print the initial screen with the blanks
	word_print(hangman, word_length);

	// game loop
	while (playing)
	{
		// check to see if guesses are used up or player won
		if (correct == word_length)
		{
			printf("\n\n YOU WIN!\n Press any key to exit..\n");
			getch();
			return 0;
		}

		if (guessed == 5)
		{
			printf("\n\n You lose!\n\n The word was %s !\n Press any key to exit...", words[word_index]);
			getch();
			return 0;
		}

		// ask player to guess
		printf("\n\n Remaining guesses : %d \n\n %d letter word \n\n Enter a letter:", chances - guessed, word_length);
		fgets(letter, 10, stdin);

		// current "correct" value count is stored,a change indicates guess was correct
		guess_check = correct;

		// loop through letters to see if it matches player guess,skip ones that are already guessed
		for (i = 0; i < word_length; i++)
		{
			if (word_hidden[i] == 1)
			{
				continue;
			}

			// increase correct count if letter exists in the word
			if (letter[0] == words[word_index][i])
			{
				word_hidden[i] = 1;
				correct++;
			}
		}

		// Clear the screen after guessing
		system("cls");

		// check if guess was incorrect
		if (correct > guess_check)
		{
			printf("\n Correct guess!");
		}
		else
		{
			printf("\n Incorrect Guess!");
			guessed++;
			hangman++;
		}

		// print new hangman image and correctly guessed letters
		word_print(hangman, word_length);
	}

	return 0;
}

// function that prints the word / blanks and calls the hangman image func
int word_print(int hangman, int word_length)
{
	print_hangman(hangman);

	for (i = 0; i < word_length; i++)
	{
		if (word_hidden[i])
		{
			printf(" %c ", words[word_index][i]);
		}
		else
		{
			printf(" _ ");
		}
	}
}

// function to print hanged man
int print_hangman(int x)
{
	if (x == 0)
	{
		printf("\n");
		printf("\n +----+");
		printf("\n |    |");
		printf("\n |");
		printf("\n |");
		printf("\n |");
		printf("\n |");
		printf("\n |");
		printf("\n +----+\n\n");
	}
	else if (x == 1)
	{
		printf("\n");
		printf("\n +----+");
		printf("\n |    |");
		printf("\n |    0");
		printf("\n |");
		printf("\n |");
		printf("\n |");
		printf("\n |");
		printf("\n +----+\n\n");
	}
	else if (x == 2)
	{
		printf("\n");
		printf("\n +----+");
		printf("\n |    |");
		printf("\n |    0");
		printf("\n |   /|");
		printf("\n |");
		printf("\n |");
		printf("\n |");
		printf("\n +----+\n\n");
	}
	else if (x == 3)
	{
		printf("\n");
		printf("\n +----+");
		printf("\n |    |");
		printf("\n |    0");
		printf("\n |   /|\\");
		printf("\n |");
		printf("\n |");
		printf("\n |");
		printf("\n +----+\n\n");
	}
	else if (x == 4)
	{
		printf("\n");
		printf("\n +----+");
		printf("\n |    |");
		printf("\n |    0");
		printf("\n |   /|\\");
		printf("\n |   / ");
		printf("\n |");
		printf("\n |");
		printf("\n +----+\n\n");
	}
	else if (x == 5)
	{
		printf("\n");
		printf("\n +----+");
		printf("\n |    |");
		printf("\n |    0");
		printf("\n |   /|\\");
		printf("\n |   / \\");
		printf("\n |");
		printf("\n |");
		printf("\n +----+\n\n");
	}
	else if (x == 10)
	{
		printf("\n ****HANG MAN *****************************************************");
		printf("\n      +----+");
		printf("\n      |    |");
		printf("\n      |    0");
		printf("\n      |   /|\\");
		printf("\n      |   / \\");
		printf("\n      |");
		printf("\n      |");
		printf("\n      +----+\n");
		printf("\n "
			"*******************************************************************"
			"*\n");
		printf("\n Words: "
			"dog,cow,computer,onion,house,apple,pizza,soda,chicken,potato\n");
		printf("\n "
			"*******************************************************************"
			"*\n");
	}
}

// generate a number between 0 and 10 - uses as the array index
int word_selector()
{
	srand((unsigned) time(NULL));

	random_number = rand() % 10;

	return random_number;
}