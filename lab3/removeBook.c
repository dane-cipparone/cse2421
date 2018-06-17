#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

int getStockNumber() {
    int stockNum;
    printf("Enter the stock number of the book you'd like to remove: ");
    if (scanf("%d", &stockNum) != 1 || stockNum < 0) {
        printf("Error reading stock number. Make sure it's a positive integer.\n");
        return -1;
    }
    return stockNum;
}

Node *removeNode(Node *head, int stockNumber) {
    Node *cursor, *prev = NULL;
    cursor = head;
    while (cursor != NULL && cursor->book.stockNumber != stockNumber) {
        prev = cursor;
        cursor = cursor->next;
    }
    if (cursor != NULL) {
        if (prev == NULL) {
            head = cursor->next;
        } else {
            prev->next = cursor->next;
        }
        free(cursor);
    } else {
        printf("Error removing book with stock number %d. Make sure that this book is in the current inventory.\n", stockNumber);
    }
    return head;
}

Node *removeBook(Node *head) {
    return removeNode(head, getStockNumber());
}
