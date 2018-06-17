#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

float revenue(Node *head) {
    float rev;
    Node *cursor;
    Data book;
    cursor = head;
    rev = 0;
    while (cursor != NULL) {
        book = cursor->book;
        rev += (book.retailPrice * book.retailQuantity);
        cursor = cursor->next;
    }
    return rev;
}

void totalRevenue(Node *head) {
    printf("The total revenue from all books is $%.2f.\n", revenue(head));
}
