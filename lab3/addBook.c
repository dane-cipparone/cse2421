#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

const int kEmptySpaceCharMax = 2; /* 2 characters: a newline and '\0' */

Data scanBook() {
    Data book;
    char *space, *title, *author;
    int stockNumber, wholesaleQuantity, retailQuantity;
    float wholesalePrice, retailPrice;
    
    /* malloc char pointer space for fgets */
    space = malloc(kEmptySpaceCharMax * sizeof(char));
    title = malloc(kTitleCharMax * sizeof(char));
    author = malloc(kAuthorCharMax * sizeof(char));
    
    printf("Enter the data for a new book in the correct input format:\n");
    fgets(space, kEmptySpaceCharMax, stdin); /* Hack: fgets needs to read in a newline before it can start waiting for the user's input */
    free(space);
    
    /* User fgets for string data */
    fgets(title, kTitleCharMax, stdin);
    scrubNewline(title);
    strcpy(book.title, title);
    free(title);
    
    fgets(author, kAuthorCharMax, stdin);
    scrubNewline(author);
    strcpy(book.author, author);
    free(author);
    
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

void addBook(Node **ptr2head) {
    Data book;
    Node *newNode;
    book = scanBook(); /* Assume correct input */
    newNode = malloc(sizeof(Node)); /* Allocate space for new node */
    newNode->book = book;
    newNode->next = NULL;
    *ptr2head = insertBook(*ptr2head, newNode);
}
