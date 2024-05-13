#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

float randomFloatInRange(float min, float max);


int main(int argc, char**argv)
{
    
    int a,b,total,gamble;
    float upgrader;
    srand(time(NULL));
    printf("Enter the amount of money you got: ");
    scanf("%d", &total);
    while (total > 0) {
        printf("Enter the amount of money you want to gamble: ");
        scanf("%d", &gamble);
        
        if (gamble <= 0 || gamble > total) {
            printf("Invalid input. Please enter a valid amount.\n");
            continue;
        }

        total -= gamble;

        printf("Choose the upgrade system:\n");
        printf("1. 1.5x\n2. 2x\n3. 5x\n4. 10x\n");
        printf("Enter your choice: ");
        scanf("%f", &upgrader);
        int choice = (int)(upgrader * 10);
        float randomNumber;
        switch (choice) {
            case 15:
                upgrader = 1.5;
                randomNumber = randomFloatInRange(0.00, 100.00);
                if (randomNumber >= 0.00 && randomNumber <= 44.99) {
                    float profit = gamble * upgrader;
                    total += profit;
                    printf("Congratulations! You made your money: %.2f\n", profit);
                } else {
                    printf("Sorry, you lost.\n");
                }
                
                break;
            case 20:
                upgrader = 2.0;
                break;
            case 50:
                upgrader = 5.0;
                break;
            case 100:
                upgrader = 10.0;
                break;
            default:
                printf("Invalid choice. Please choose a valid upgrade system.\n");
                total += gamble; // Refund the gamble amount
                continue;
        }
   }

    
    return 0;
}

float randomFloatInRange(float min, float max) {
    int randomInt = rand() % 10001;
    float randomFloat = randomInt / 100.0;
    return min + randomFloat;
}
