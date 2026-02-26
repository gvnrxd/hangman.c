
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void myGuess(char g[20]){
    printf("Make your guess: ");
    scanf("%19s", g);
};

int main() {
    srand(time(NULL));
    int num = (rand() % 10);
    int delay = (rand() % 2 + 1);
    int attempts = 0;
    char guess[20];
    int i = 0;
    char wordsArr[10][20] = {
    "computer",
    "keyboard",
    "monitor",
    "program",
    "function",
    "variable",
    "compiler",
    "pointer",
    "integer",
    "algorithm"
    };


    printf("Are you ready to play hangman?\n\n");
    printf("Generating random word\n");
    while (i < delay ) {
        printf("\rLoading   ");
        fflush(stdout);
        sleep(1);

        printf("\rLoading.");
	    fflush(stdout);
        sleep(1);

        printf("\rLoading..");
        fflush(stdout);
        sleep(1);

        printf("\rLoading...");
        fflush(stdout);
        sleep(1);
        i++;
    }   

    printf("\n");
    while(attempts < 3) {
        myGuess(guess); 
        printf("\nYou entered %s\n", guess);
        if (strcmp(guess, wordsArr[num]) == 0) {
            printf("Congrats you won!\n");
            return 0;
        }else {
            printf("\nTry again! Tries left: %d\n", (2 - attempts));
            attempts++;
        };
    }

    printf("\nYour word was %s", wordsArr[num]);
    return 0;
}
