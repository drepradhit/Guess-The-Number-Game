#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void displayMenu() {
    printf("\n================ Menu ================\n");
    printf("1. Play the game\n");
    printf("2. Quit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    system("color 4");
}

int main() {
    srand(time(0));

    int secret, guess, attempts = 0;
    char username[50];
    int guesses = 1;

    secret = random(1, 100);

    printf("========================================\n");
    printf("\nWelcome to Guess The Number Game!!\n");
    printf("\n========================================\n");

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("\nEnter your username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';

                printf("-----------------------------------------\n");
                printf("Welcome %s! Good luck!\n", username);

                attempts = 0;
                guesses = 1;
                secret = random(1, 100);

                while (attempts < 10) {
                    if (guesses) {
                        printf("\nGuess The Secret Number : ");
                        guesses = 0;
                    } else {
                        printf("\nTry again!\nYour guess: ");
                    }
                    scanf("%d", &guess);

                    attempts++;

                    if (guess == secret) {
                        printf("\nCongrats %s! You win the game after %dx attempts!\n", username, attempts);
                        break;
                    } else {
                        if (guess < secret) {
                            printf("\nToo low!\n");
                        } else {
                            printf("\nToo high!\n");
                        }
                    }
                }

                if (attempts == 10) {
                    printf("\nYou lose. The secret number is %d!\n", secret);
                }
                break;
            case 2:
                printf("\nGoodbye! Thanks for playing.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
