#include <stdio.h>

int main() {
    float transactionAmount;
    float dailyTotal;
    float dailyLimit = 5000.0;
    char country;
    int transactionsInHour;
    printf("Please Enter Today's Total Spending: ");
    scanf("%f", &dailyTotal);
    printf("Please Enter Country Code (P for Pakistan, U for UAE): ");
    scanf(" %c", &country);
    printf("Please Enter Number Of Transactions Made This Hour: ");
    scanf("%d", &transactionsInHour);
    printf("Please Enter transaction amount: ");
    scanf("%f", &transactionAmount);
    if (dailyTotal + transactionAmount > dailyLimit) {
        printf("Daily limit exceeded!\n");
    }
    if ((country != 'P') && (country != 'U')) {
        printf("Transaction in unusual country!\n");
    }
    if (transactionsInHour >= 3) {
        printf("Too many transactions in one hour!\n");
    }
    if ((dailyTotal + transactionAmount <= dailyLimit) && (country == 'P' || country == 'U') && (transactionsInHour < 3)) {
        printf("\nTransaction is normal.\n");
    }
    return 0;
}
