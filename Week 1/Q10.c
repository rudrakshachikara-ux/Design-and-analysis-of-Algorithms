#include <stdio.h>
#include <string.h>

int main() {
    float balance = 0, amount;
    int choice, i, count = 0;
    char trans[5][50];

    do {
        printf("\n\n--- ATM MENU ---");
        printf("\n1. Balance");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Transactions");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Balance = %.2f\n", balance);
        }

        else if (choice == 2) {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if (amount > 0) {
                balance += amount;

                if (count < 5) {
                    sprintf(trans[count], "Deposit %.2f", amount);
                    count++;
                } else {
                    for (i = 0; i < 4; i++)
                        strcpy(trans[i], trans[i + 1]);

                    sprintf(trans[4], "Deposit %.2f", amount);
                }

                printf("Deposit successful.\n");
            } else {
                printf("Invalid amount.\n");
            }
        }

        else if (choice == 3) {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if (amount <= 0)
                printf("Invalid amount.\n");

            else if (amount > balance)
                printf("Insufficient balance.\n");

            else {
                balance -= amount;

                if (count < 5) {
                    sprintf(trans[count], "Withdraw %.2f", amount);
                    count++;
                } else {
                    for (i = 0; i < 4; i++)
                        strcpy(trans[i], trans[i + 1]);

                    sprintf(trans[4], "Withdraw %.2f", amount);
                }

                printf("Withdrawal successful.\n");
            }
        }

        else if (choice == 4) {
            printf("\n--- Last Transactions ---\n");

            if (count == 0)
                printf("No transactions.\n");
            else
                for (i = 0; i < count; i++)
                    printf("%d. %s\n", i + 1, trans[i]);
        }

        else if (choice == 5) {
            printf("Thank you!\n");
        }

        else {
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
