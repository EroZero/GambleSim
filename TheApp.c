#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random float between a given range
float randomFloatInRange(float min, float max);

int main(int argc, char** argv) {
    int total, gamble;
    float upgrader;
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the initial amount of money
    printf("Enter the amount of money you got: ");
    scanf("%d", &total);

    // Main game loop, continues while the player has money
    while (total > 0) {
        // Prompt the user for the amount of money to gamble
        printf("Enter the amount of money you want to gamble: ");
        scanf("%d", &gamble);

        // Check for invalid input
        if (gamble <= 0 || gamble > total) {
            printf("Invalid input. You can't gamble more than your total.\n");
            continue;
        }

        // Subtract the gamble amount from the total
        total -= gamble;

        // Display upgrade options
        printf("Choose the upgrade system:\n");
        printf("1. 1.5x\n2. 2x\n3. 5x\n4. 10x\n");
        printf("Write 1 for 1.5x, 2 for 2x, etc. Enter your choice: ");
        scanf("%f", &upgrader);

        // Check if the selected upgrade option is valid
        if (upgrader == 1.5 || upgrader == 2.0 || upgrader == 5.0 || upgrader == 10.0) {
            // Generate a random number between 0.00 and 100.00
            float randomNumber = randomFloatInRange(0.00, 100.00);
            bool won = false;
            float profit = 0.0;

            // Determine if the player wins based on the upgrade option chosen
            if (upgrader == 1.5 && randomNumber <= 58.89) {
                won = true;
                profit = gamble * upgrader;
            } else if (upgrader == 2.0 && randomNumber <= 43.76) {
                won = true;
                profit = gamble * upgrader;
            } else if (upgrader == 5.0 && randomNumber <= 14.68) {
                won = true;
                profit = gamble * upgrader;
            } else if (upgrader == 10.0 && randomNumber <= 9.86) {
                won = true;
                profit = gamble * upgrader;
            }

            // Update total based on win or loss
            if (won) {
                total += profit;
                printf("Congratulations! You won: %.2f\n", profit);
            } else {
                printf("Sorry, you lost.\n");
            }
        } else {
            // Invalid upgrade option selected, refund the gamble amount
            printf("Invalid choice. Please choose a valid upgrade.\n");
            total += gamble;
        }

        // Display the player's total money
        printf("Total money: %d\n", total);
    }

    return 0;
}

// Function to generate a random float in the specified range
float randomFloatInRange(float min, float max) {
    return min + (rand() / (float)RAND_MAX) * (max - min);
}
