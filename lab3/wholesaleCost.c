#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

float wholesaleCost(Node *head) {
    float cost;
    Node *cursor;
    Data book;
    cursor = head;
    cost = 0;
    while (cursor != NULL) {
        book = cursor->book;
        cost += (book.wholesalePrice * book.wholesaleQuantity);
        cursor = cursor->next;
    }
    return cost;
}

void totalWholesaleCost(Node *head) {
    printf("The total wholesale cost for all books is $%.2f.\n", wholesaleCost(head));
}
