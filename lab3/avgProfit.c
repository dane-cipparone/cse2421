#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

float avgProfit(Node *head) {
    return profit(head) / sales(head);
}

void averageProfitPerSale(Node *head) {
    printf("The average profi per sale is $%.2f.\n", avgProfit(head));
}
