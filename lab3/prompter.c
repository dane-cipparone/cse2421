#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

void (*userReadOptions[8])(Node *) = {totalRevenue, totalWholesaleCost, currentInvestment, totalProfit, totalNumSales, averageProfitPerSale, inStock, outOfStock};
Node *(*userChangeOptions[2])(Node *) = {addBook, removeBook};
const int kExitOption = 11;

int getUserOption() {
    int i;
    printf("Enter an option (1-11): ");
    if (scanf("%d", &i) != 1 || i < 0 || i > 11) {
        printf("Error reading user option. Make sure it was between 1-11.\n");
        return kExitOption;
    }
    return i;
}

Node *promptForUserOption(Node *head) {
    int option;
    option = getUserOption();
    while (option != kExitOption) {
        if (option > 8) head = userChangeOptions[option - 9](head);
        else userReadOptions[option - 1](head);
        option = getUserOption();
    }
    return head;
}
