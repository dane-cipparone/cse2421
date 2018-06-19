#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

/* Remove the hanging newline char at the end of an fgets read */
void scrubNewline(char *line) {
    line[strlen(line) - 1] = '\0';
}

Data readOneBook(FILE *f) {
    Data d;
    char *line1, *line2, *line3, *line4, *line5, *line6, *line7;
    
    /* malloc char pointer space for fgets */
    line1 = malloc(kTitleCharMax * sizeof(char));
    line2 = malloc(kAuthorCharMax * sizeof(char));
    line3 = malloc(kIntCharMax * sizeof(char));
    line4 = malloc(kFloatCharMax * sizeof(char));
    line5 = malloc(kFloatCharMax * sizeof(char));
    line6 = malloc(kIntCharMax * sizeof(char));
    line7 = malloc(kIntCharMax * sizeof(char));
    
    fgets(line1, kTitleCharMax, f);
    scrubNewline(line1);
    if (strlen(line1) == 0) { /* We have reached a blank line or EOF. Return empty book w/ stockNumber -1 */
        d.stockNumber = -1;
        return d;
    }
    strcpy(d.title, line1);
    free(line1); /* Free char pointer space */
    
    fgets(line2, kAuthorCharMax, f);
    scrubNewline(line2);
    strcpy(d.author, line2);
    free(line2);
    
    fgets(line3, kIntCharMax, f);
    scrubNewline(line3);
    d.stockNumber = atoi(line3);
    free(line3);
    
    fgets(line4, kFloatCharMax, f);
    scrubNewline(line4);
    d.wholesalePrice = (float)atof(line4);
    free(line4);
    
    fgets(line5, kFloatCharMax, f);
    scrubNewline(line5);
    d.retailPrice = (float)atof(line5);
    free(line5);
    
    fgets(line6, kIntCharMax, f);
    scrubNewline(line6);
    d.wholesaleQuantity = atoi(line6);
    free(line6);
    
    fgets(line7, kIntCharMax, f);
    scrubNewline(line7);
    d.retailQuantity = atoi(line7);
    free(line7);
    
    return d;
}

Node *readOneNode(FILE *f) {
    Node *bookNode;
    Data book;
    book = readOneBook(f);
    if (book.stockNumber == -1) { /* We have reached the end of the input file. Return a NULL pointer for the end of the list */
        return NULL;
    }
    bookNode = malloc(sizeof(Node)); /* Allocate space for new node */
    bookNode->book = book;
    bookNode->next = NULL;
    
    return bookNode;
}

Node *insertBook(Node *head, Node *new) {
    Node *cursor, *prev = NULL;
    cursor = head;
    while (cursor != NULL && cursor->book.stockNumber < new->book.stockNumber) {
        /* Iterate until cursor's stockNumber > new's stockNumber or end of list */
        prev = cursor;
        cursor = cursor->next;
    }
    new->next = cursor;
    if (prev != NULL) {
        prev->next = new;
    } else {
        head = new; /* This book's stock number is less than head's */
    }
    return head;
}

void printBooks(Node *head, FILE *outputFile) {
    Node *cursor;
    int i;
    i = 1;
    cursor = head;
    while (cursor != NULL) {
        fprintf(outputFile, "%s\n", cursor->book.title);
        fprintf(outputFile, "%s\n", cursor->book.author);
        fprintf(outputFile, "%d\n", cursor->book.stockNumber);
        fprintf(outputFile, "%.2f\n", cursor->book.wholesalePrice);
        fprintf(outputFile, "%.2f\n", cursor->book.retailPrice);
        fprintf(outputFile, "%d\n", cursor->book.wholesaleQuantity);
        fprintf(outputFile, "%d\n", cursor->book.retailQuantity);
        cursor = cursor->next;
        i++;
    }
}

int countBooks(Node *head) {
    Node *cursor;
    int count;
    count = 0;
    cursor = head;
    while (cursor != NULL) {
        cursor = cursor->next;
        count++;
    }
    return count;
}

Node *readBooks(FILE *f) {
    Node *head = NULL, *new; /* We know there is at least one book */
    do {
        new = readOneNode(f);
        if (head == NULL) head = new;
        else if (new != NULL) head = insertBook(head, new);
    } while (new != NULL);
    
    return head;
}
