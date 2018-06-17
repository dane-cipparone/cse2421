#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

int sales(Node *head) {
    float sum;
    Node *cursor;
    cursor = head;
    sum = 0;
    while (cursor != NULL) {
        sum += cursor->book.retailQuantity;
        cursor = cursor->next;
    }
    return sum;
}

void totalNumSales(Node *head) {
    printf("The total number of books sold is %d.\n", sales(head));
}
