#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

float profit(Node *head) {
    return revenue(head) - wholesaleCost(head) + investment(head);
}

void totalProfit(Node *head) {
    printf("The total profit for all books is $%.2f.\n", profit(head));
}
