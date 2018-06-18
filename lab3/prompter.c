#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

/* Function pointer arrays for user options. 2 arrays because there are 2 possible return types: */
/* return void: only reading from the list */
void (*userReadOptions[8])(Node *) = {totalRevenue, totalWholesaleCost, currentInvestment, totalProfit, totalNumSales, averageProfitPerSale, inStock, outOfStock};
/* return Node*: changing the list somehow and therefore may change list's head pointer */
Node *(*userChangeOptions[2])(Node *) = {addBook, removeBook};

const int kExitOption = 11;

int getUserOption() {
    int i;
    printf("Enter an option (1-11): ");
    if (scanf("%d", &i) != 1 || i < 0 || i > kExitOption) {
        printf("Error reading user option. Make sure it was between 1-11.\n");
        return kExitOption;
    }
    return i;
}

Node *promptForUserOption(Node *head) {
    int option;
    option = getUserOption();
    while (option != kExitOption) { /* Keep prompting until they enter 11 */
        if (option > 8) head = userChangeOptions[option - 9](head); /* Options 9 - 10 mutate the list */
        else userReadOptions[option - 1](head);
        option = getUserOption();
    }
    return head;
}
