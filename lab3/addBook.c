#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

Data scanBook() {
    Data book;
    char space[100], title[100], author[50];
    int stockNumber, wholesaleQuantity, retailQuantity;
    float wholesalePrice, retailPrice;
    printf("Enter the data for a new book in the correct input format:\n");
    fgets(space, 100, stdin);
    fgets(title, 100, stdin);
    scrubNewline(title);
    strcpy(book.title, title);
    fgets(author, 50, stdin);
    scrubNewline(author);
    strcpy(book.author, author);
    scanf("%d", &stockNumber);
    book.stockNumber = stockNumber;
    scanf("%f", &wholesalePrice);
    book.wholesalePrice = wholesalePrice;
    scanf("%f", &retailPrice);
    book.retailPrice = retailPrice;
    scanf("%d", &wholesaleQuantity);
    book.wholesaleQuantity = wholesaleQuantity;
    scanf("%d", &retailQuantity);
    book.retailQuantity = retailQuantity;
    return book;
}

Node *addBook(Node *head) {
    Data book;
    Node *newNode;
    book = scanBook();
    if (book.stockNumber == -1) {
        printf("There was an error reading the book data.\n");
        return head;
    }
    newNode = malloc(sizeof(Node));
    newNode->book = book;
    newNode->next = NULL;
    return insertBook(head, newNode);
}
