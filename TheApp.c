#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float randomFloatInRange(float min, float max);

int main(int argc, char** argv) {
    int total, gamble;
    float upgrader;
    srand(time(NULL));

    printf("Enter the amount of money you got: ");
    scanf("%d", &total);

    while (total > 0) {
        printf("Enter the amount of money you want to gamble: ");
        scanf("%d", &gamble);

        if (gamble <= 0 || gamble > total) {
            printf("Invalid input. You cant gamble higher than your total.\n");
            continue;
        }

        total -= gamble;

        printf("Choose the upgrade system:\n");
        printf("1. 1.5x\n2. 2x\n3. 5x\n4. 10x\n");
        printf("Write 1 for 1.5x 2 for 2x etc. Enter your choice: ");
        scanf("%f", &upgrader);

        if (upgrader == 1.5 || upgrader == 2.0 || upgrader == 5.0 || upgrader == 10.0) {
            float randomNumber = randomFloatInRange(0.00, 100.00);
            bool won = false;
            float profit = 0.0;

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

            if (won) {
                total += profit;
                printf("Cool You made your money: %.2f\n", profit);
            } else {
                printf("You lost.\n");
            }
        } else {
            printf("Invalid choice. Choose a valid upgrade.\n");
            total += gamble;
        }

        printf("total money: %d\n", total);
    }

    return 0;
}

float randomFloatInRange(float min, float max) {
    return min + (rand() / (float)RAND_MAX) * (max - min);
}
