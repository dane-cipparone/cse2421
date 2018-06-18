#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"
/* Author: Sean O'Donnell */

void freeBooks(Node *head) {
    Node *cursor, *next;
    cursor = head;
    while (cursor != NULL) {
        next = cursor->next;
        free(cursor); /* Free each Node pointer's space */
        cursor = next;
    }
}

int main(int argc, const char * argv[]) {
/*void lab3Main(int argc, const char * argv[]) {*/
    const char *inputfName, *outputfName;
    FILE *booksFile, *outputFile;
    Node *booksHead;
    
    /* Get file names and open the files */
    inputfName = argv[argc - 2];
    outputfName = argv[argc - 1];
    booksFile = fopen(inputfName, "r");
    outputFile = fopen(outputfName, "w");
    
    booksHead = readBooks(booksFile); /* Read & pare book inventory into list of Node* */
    printf("%d books were read into the inventory.\n", countBooks(booksHead));
    booksHead = promptForUserOption(booksHead); /* Let user do actions on the list */
    printBooks(booksHead, outputFile); /* Print book inventory to output file */
    freeBooks(booksHead); /* Free allocated memory for book inventory */
    
    /* close files */
    fclose(booksFile);
    fclose(outputFile);
    
    return (0);
}
