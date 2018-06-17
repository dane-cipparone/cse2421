#include <stdio.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

void outOfStock(Node *head) {
    Node *cursor;
    Data book;
    int stock;
    cursor = head;
    printf("\n");
    while (cursor != NULL) {
        book = cursor->book;
        stock = book.wholesaleQuantity - book.retailQuantity;
        if (stock == 0) {
            printf("Books out of Stock!\n");
            printf("%d\t%s\t%s\n\n", book.stockNumber, book.author, book.title);
        }
        cursor = cursor->next;
    }
}
