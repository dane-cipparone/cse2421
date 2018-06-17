#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

float investment(Node *head) {
    float inv;
    Node *cursor;
    Data book;
    cursor = head;
    inv = 0;
    while (cursor != NULL) {
        book = cursor->book;
        inv += (book.wholesalePrice * (book.wholesaleQuantity - book.retailQuantity));
        cursor = cursor->next;
    }
    return inv;
}

void currentInvestment(Node *head) {
    printf("The current investment in books is $%.2f.\n", investment(head));
}
