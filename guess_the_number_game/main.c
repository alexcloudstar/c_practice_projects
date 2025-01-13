#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

void printInitMessage();
void getDifficulty(int *difficulty);
int genRandomNum(int max);
void game(int range);

int main() {
    int difficulty;
    int range;

    srand(time(NULL));

    printInitMessage();

    getDifficulty(&difficulty);

    switch (difficulty) {
        case 1: range = 10; break; 
        case 2: range = 50; break; 
        case 3: range = 100; break; 
        default:
            printf("Invalid difficulty. Exiting. \n");
            return 1;
    }

    game(range);

    printf("Congratulations! You guessed the number\n");

    return 0;
}

void printInitMessage() {
    printf("----------- Welcome to Guess the Number -----------\n");
    printf("Choose the correct number based on the difficulty!\n");
};

void getDifficulty(int *difficulty) {
    do {
        printf("Please select a difficulty (1: Easy, 2: Medium, 3: Hard): ");
        if(scanf("%d", difficulty) != 1) {
            printf("Invalid input. Please enter a number. \n");
            while(getchar() != '\n');
        }
    } while (*difficulty < 1 || *difficulty > 3);

    printf("Nice, You set the difficulty to: %d.\n", *difficulty);
};

int genRandomNum(int max) {
    return rand() % (max + 1);
};


void game(int range) {
   int userInput, randomNum; 

    randomNum = genRandomNum(range);

    printf("I have selected a number between 0 and %d. Can you guess it?\n", range);

    while (1) {
        printf("Enter your guess: ");

        if(scanf("%d", &userInput) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if(userInput < 0 || userInput > range) {
            printf("Please guess a number within the range 0 to %d.\n", range);
            continue;
        }

        if(userInput < randomNum) {
            printf("Too low! Try again.\n");
            continue;
        }

        if(userInput > randomNum) {
            printf("Too high! Try again.\n");
            continue;
        }

        break;
    };
};
