#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"
#define DEBUG 1
/* Author: Sean O'Donnell */

//typedef struct DataSet {
//    float *head;
//    int count;
//} DataSet;

int numberOfValues()
{
    int vals = 0;
    scanf("%d", &vals);
    return (vals);
}

int numSets()
{
    int sets = 0;
    printf("Enter the number of data sets: ");
    scanf("%d", &sets);
    return (sets);
}

float* data(int numValues)
{
    float *values, *cursor, value;
    values = malloc(numValues * sizeof(float));
    cursor = values;
    while (numValues > 0) {
        scanf(" %f", &value);
        *cursor = value;
        cursor++;
        numValues--;
    }
    return (values);
}

DataSet dataSet(int number)
{
    DataSet dataSet;
    int count;
    printf("Enter data set %d: ", number);
    count = numberOfValues();
    dataSet.head = data(count);
    dataSet.count = count;
    return (dataSet);
}

DataSet *allSets() {
    int count, i;
    DataSet *sets, *cursor, set;
    DataSet terminator = { NULL, 0 };
    count = numSets();
    sets = malloc((count + 1) * sizeof(DataSet));
    cursor = sets;
    for (i = 1; i <= count; i++) {
        set = dataSet(i);
        *cursor = set;
        cursor++;
    }
    *cursor = terminator;
    return (sets);
}

void listCalculations()
{
    printf("1) Find the minimum value.\n");
    printf("2) Find the maximum value.\n");
    printf("3) Calculate the sum of all the values.\n");
    printf("4) Calculate the average of all the values.\n");
    printf("5) Print the values in the data set.\n");
    printf("6) Exit the program.\n\n");
}

int dataSetToCalculate()
{
    int set;
    printf("Enter the number of the data set on which you wish to do calculations: ");
    scanf("%d", &set);
    return (set);
}

int getCalculation()
{
    int calc;
    printf("Enter the calculation you'd like to perform: ");
    scanf("%d", &calc);
    return (calc);
}

float min(DataSet set)
{
    float *cursor, min;
    int i;
    cursor = set.head;
    min = *cursor;
    for (i = 0; i < set.count; i++) {
        if (*cursor < min) min = *cursor;
        cursor++;
    }
    return (min);
}

float max(DataSet set)
{
    float *cursor, max;
    int i;
    cursor = set.head;
    max = *cursor;
    for (i = 0; i < set.count; i++) {
        if (*cursor > max) max = *cursor;
        cursor++;
    }
    return (max);
}

float sum(DataSet set)
{
    float *cursor, sum;
    int i;
    cursor = set.head;
    sum = 0;
    for (i = 0; i < set.count; i++) {
        sum += *cursor;
        cursor++;
    }
    return (sum);
}

float avg(DataSet set)
{
    return sum(set) / set.count;
}

void print(DataSet set)
{
    float *cursor;
    int i;
    cursor = set.head;
    for (i = 0; i < set.count; i++) {
        printf("\t%.2f\n", *cursor);
        cursor++;
    }
}

void performCalculation(DataSet *setsCursor, int setNum, int calc)
{
    int i;
    for (i = 1; i < setNum; i++) setsCursor++;
    switch (calc) {
        case 1:
            printf("The minimum value in set %d is %.2f.\n", setNum, min(*setsCursor));
            break;
        case 2:
            printf("The maximum value in set %d is %.2f.\n", setNum, max(*setsCursor));
            break;
        case 3:
            printf("The sum of all values in set %d is %.2f.\n", setNum, sum(*setsCursor));
            break;
        case 4:
            printf("The average of all values in set %d is %.2f.\n", setNum, avg(*setsCursor));
            break;
        case 5:
            printf("Set %d: \n", setNum);
            print(*setsCursor);
            break;
        default:
            break;
    }
    printf("\n");
}

void promptCalculation(DataSet *sets)
{
    int setNumber, calculation;
    setNumber = dataSetToCalculate();
    listCalculations();
    calculation = getCalculation();
    while (calculation != 6) {
        performCalculation(sets, setNumber, calculation);
        
        setNumber = dataSetToCalculate();
        listCalculations();
        calculation = getCalculation();
    }
}

void freeSetList(DataSet *sets)
{
    DataSet *setsCursor;
    float *dataCursor;
    setsCursor = sets;
    while (setsCursor->head != NULL) {
        dataCursor = setsCursor->head;
        free(dataCursor);
        setsCursor++;
    }
    free(sets);
}

void labMain(void)
/*int main()*/
{
    DataSet *setsHead;
    DataSet *setsCursor;
    float *dataCursor;
    int i, j;
    setsHead = allSets();
    setsCursor = setsHead;
    i = 1;
    /*    if (DEBUG) { */
    while (setsCursor->head != NULL) {
        printf("\nset %d:\n", i);
        dataCursor = setsCursor->head;
        for (j = 0; j < setsCursor->count; j++) {
            printf("\t%.2f\n", *dataCursor);
            dataCursor++;
        }
        printf("\n");
        setsCursor++;
        i++;
    }
    /*    } */
    promptCalculation(setsHead);
    freeSetList(setsHead);
    
    /*return (0);*/
}
