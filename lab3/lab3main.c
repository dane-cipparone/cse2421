#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

void freeBooks(Node *head) {
    Node *cursor, *next;
    cursor = head;
    while (cursor != NULL) {
        next = cursor->next;
        free(cursor);
        cursor = next;
    }
}

int main(int argc, const char * argv[]) {
/*void lab3Main(int argc, const char * argv[]) {*/
    const char *inputfName, *outputfName;
    FILE *booksFile, *outputFile;
    Node *booksHead;
    
    inputfName = argv[1];
    outputfName = argv[2];
    booksFile = fopen(inputfName, "r");
    outputFile = fopen(outputfName, "w");
    
    booksHead = readBooks(booksFile);
    printf("%d books were read into the inventory.\n", countBooks(booksHead));
    booksHead = promptForUserOption(booksHead);
    printBooks(booksHead, outputFile);
    freeBooks(booksHead);
    
    fclose(booksFile);
    fclose(outputFile);
    
    return (0);
}
