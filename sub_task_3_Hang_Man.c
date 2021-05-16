// libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

// prototypes
int word_selector();
int print_hangman(int x);

// variables
char words[][10] = {"dog",   "cow",   "computer", "onion",   "house",
                    "apple", "pizza", "soda",     "chicken", "potato"};
char letter[10];

int i, word_index, random_number;
int correct = 0, guessed = 0;
int word_hidden[10];
int guess_check;
int hangman = 0;
int playing = 1;

// main
int main() {
  // clear screen at start
  system("cls");

  // value is generated to choose the word
  word_index = word_selector();
  int word_length = strlen(words[word_index]);

  // intro screen with word list
  print_hangman(10);
  printf(" Press any key to begin...");
  getch();
  system("cls");

  // word_hidden is used to check what letters have been guessed
  for (i = 0; i < word_length; i++) {
    word_hidden[i] = 0;
  }

  // print the initial screen with the word blanks
  print_hangman(0);
  for (i = 0; i < word_length; i++) {
    if (!word_hidden[i]) {
      printf(" _ ");
    }
  }

  // game loop
  while (playing) {

    // check to see if guesses are used up or player won
    if (correct == word_length) {
      printf("\n\n YOU WIN!\n\n");
      printf(" Press any key to exit...");
      getch();
      playing = 0;
      continue;
    }

    if (guessed == 5) {
      printf("\n\n You lose!\n\n");
      printf("\n The word was %s ! \n",words[word_index]);
      printf(" Press any key to exit...");
      getch();
      playing = 0;
      continue;
    }

    // ask player to guess
    printf("\n\n Remaining guesses : %d", 5 - guessed);
    printf("\n\n Enter a letter:");
    scanf(" %c", letter);

    // save correct vars to check for incorrect guess
    guess_check = correct;

    // loop through letters to see if it matches player guess
    for (i = 0; i < word_length; i++) {
      if (word_hidden[i] == 1) {
        continue;
      }
      // increase correct count if letter exists in the word
      if (letter[0] == words[word_index][i]) {
        word_hidden[i] = 1;
        correct++;
      }
    }

    // Clear the screen after guessing
    system("cls");

    // check if guess was incorrect
    if (correct > guess_check) {
      printf("\n Correct guess!");
    } else {
      printf("\n Incorrect Guess!");
      guessed++;
      hangman++;
    }

    // print new hangman image and correctly guessed letters
    print_hangman(hangman);
    for (i = 0; i < word_length; i++) {
      if (word_hidden[i]) {
        printf(" %c ", words[word_index][i]);
      } else {
        printf(" _ ");
      }
    }
  }

  return 0;
}

// function to print hanged man
int print_hangman(int x) {

  if (x == 0) {
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
  else if (x == 1) {
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
  else if (x == 2) {
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
  else if (x == 3) {
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
  else if (x == 4) {
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
  else if (x == 5) {
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
  else if (x == 10) {
    printf("\n *** HANG MAN "
           "******************************************************");
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
           "*  \n");
    printf("\n Words: "
           "dog,cow,computer,onion,house,apple,pizza,soda,chicken,potato\n");
    printf("\n "
           "*******************************************************************"
           "*  \n");
  }
}

// generate a number between 0 and 10
int word_selector() {

  srand((unsigned)time(NULL));

  random_number = rand() % 10;

  return random_number;
}
