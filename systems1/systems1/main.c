//
//  main.c
//  systems1
//
//  Created by Sean O'Donnell on 5/29/18.
//  Copyright © 2018 Sean O'Donnell. All rights reserved.
//

#include <stdio.h>
#include "lab3.h"

int main(int argc, const char * argv[]) {
    char *stringConstant, stringArray[] = "Go Bucks!";
    stringConstant = stringArray;
    printf("%c\n", stringConstant[3]);
    stringConstant[3] = 'v';
    printf("%s\n", stringConstant);
    
    printf("%c\n", stringArray[3]);
    stringArray[3] = 'd';
    printf("%s\n", stringArray);
    
    
    lab3Main(argc, argv);
    return 0;
}
