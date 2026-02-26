
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void myGuess(char g[20]){
    printf("Make your guess: ");
    scanf("%19s", g);
};

void printMan(int tries){
    if (tries == 1) {
        printf(" o\n");
    }
    else if(tries == 2) {
        printf(" o\n |\n");
    } else if (tries == 3) {
        printf(" o\n/|\n");
    }
    else if (tries == 4) {
        printf(" o\n/|\\ \n");
    }
    else if (tries == 5) {
          printf(" o\n/|\\\n/\n");
    }
      else if (tries == 6) {
          printf(" o\n/|\\\n/ \\\n");
    }
}

int main() {
    srand(time(NULL));
    int num = (rand() % 10);
    int delay = (rand() % 2 + 1);
    int attempts = 1;
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
    while(attempts <= 6) {
        myGuess(guess); 
        if (strcmp(guess, wordsArr[num]) == 0) {
            printf("Congrats you won!\n");
            return 0;
        }else {
            if (attempts <= 6) {
            printf("\nTry again! Tries left: %d\n", (6 - attempts));
            printMan(attempts);
            } 
            attempts++;
        };
    }
    printf("\nGame over");
    printf("\nYour word was %s", wordsArr[num]);
    return 0;
}
