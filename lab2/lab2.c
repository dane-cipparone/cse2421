#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
/* Author: Sean O'Donnell */

/* I would have put this in a header file if the lab doc didn't request only one c file */
typedef struct DataSet {
    float *head;
    int count;
    int index;
} DataSet;

int numVals()
{
    int vals = 0;
    scanf("%d", &vals);
    return (vals);
}

int numSets()
{
    int sets = 0;
    printf("enter the number of data sets: ");
    scanf("%d", &sets);
    return (sets);
}

float* data(int numValues)
{
    float *values, *cursor, value;
    values = malloc(numValues * sizeof(float)); /* Allocate enough space for all of the values */
    cursor = values;
    while (numValues > 0) {
        scanf(" %f", &value);
        *cursor = value; /* Set value at this address to the value read by scanf */
        cursor++;
        numValues--;
    }
    return (values);
}

DataSet dataSet(int number)
{
    DataSet dataSet;
    int count;
    printf("enter data set %d: ", number);
    count = numVals();
    dataSet.head = data(count);
    dataSet.count = count;
    dataSet.index = number;
    return (dataSet);
}

DataSet *allSets() {
    int count, i;
    DataSet *sets, *cursor, set;
    DataSet terminator = { NULL, 0 }; /* This DataSet will represent the end of the array */
    count = numSets();
    sets = malloc((count + 1) * sizeof(DataSet)); /* count + 1 for number of sets + the terminator DataSet */
    cursor = sets;
    for (i = 1; i <= count; i++) {
        set = dataSet(i);
        *cursor = set;
        cursor++;
    }
    *cursor = terminator;
    return (sets);
}

void calcList()
{
    printf("1) find the minimum value.\n");
    printf("2) find the maximum value.\n");
    printf("3) calculate the sum of all the values.\n");
    printf("4) calculate the average of all the values.\n");
    printf("5) print the values in the data set.\n");
    printf("6) exit the program.\n\n");
}

int calcSet()
{
    int set;
    printf("enter the number of the data set on which you wish to do calculations: ");
    scanf("%d", &set);
    return (set);
}

int calcNum()
{
    int calc;
    printf("enter the calculation you'd like to perform: ");
    scanf("%d", &calc);
    return (calc);
}

void min(DataSet set)
{
    float *cursor, min;
    int i;
    cursor = set.head;
    min = *cursor;
    for (i = 0; i < set.count; i++) {
        if (*cursor < min) min = *cursor;
        cursor++;
    }
    printf("the minimum value in set %d is %.2f.\n", set.index, min);
}

void max(DataSet set)
{
    float *cursor, max;
    int i;
    cursor = set.head;
    max = *cursor;
    for (i = 0; i < set.count; i++) {
        if (*cursor > max) max = *cursor;
        cursor++;
    }
    printf("the maximum value in set %d is %.2f.\n", set.index, max);
}

float total(DataSet set)
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

void sum(DataSet set)
{
    printf("the sum of all values in set %d is %.2f.\n", set.index, total(set));
}

void avg(DataSet set)
{
    printf("the average of all values in set %d is %.2f.\n", set.index, (total(set) / set.count));
}

void print(DataSet set)
{
    float *cursor;
    int i;
    cursor = set.head;
    printf("set %d: \n", set.index);
    for (i = 0; i < set.count; i++) {
        printf("\t%.2f\n", *cursor);
        cursor++;
    }
}

void (*calculations[5])(DataSet) = { min, max, sum, avg, print }; /* array of function pointers for calculations */

void performCalculation(DataSet *setsCursor, int setIndex, int calc)
{
    int i;
    for (i = 1; i < setIndex; i++) setsCursor++;
    printf("\n");
    calculations[calc - 1](*setsCursor); /* pass setsCursor's value (a data set) to the (calc - 1)th calculation */
    printf("\n");
}

void calcPrompt(DataSet *sets) /* Prompt the user for the data set number and calculation number until they enter 6 for the calculation */
{
    int setNumber, calculation;
    setNumber = calcSet();
    calcList();
    calculation = calcNum();
    while (calculation != 6) {
        performCalculation(sets, setNumber, calculation);
        
        setNumber = calcSet();
        calcList();
        calculation = calcNum();
    }
}

/* debug-only */
void printSets(DataSet *sets)
{
    float *dataCursor;
    int i = 1, j;
    printf("\n");
    while (sets->head != NULL) {
        printf("set %d:\n", i);
        dataCursor = sets->head;
        for (j = 0; j < sets->count; j++) {
            printf("\t%.2f\n", *dataCursor);
            dataCursor++;
        }
        printf("\n");
        sets++;
        i++;
    }
}

int main()
{
    DataSet *setsHead, *setsCursor;
    float *dataCursor;
    setsHead = allSets();
    if (DEBUG) printSets(setsHead);
    calcPrompt(setsHead);
    
    /* free memory allocated for array of data sets, and each data set itself */
    setsCursor = setsHead;
    while (setsCursor->head != NULL) { /* while setsCursor isn't pointing to terminator DataSet */
        dataCursor = setsCursor->head;
        free(dataCursor);
        setsCursor++;
    }
    free(setsHead);
    
    return (0);
}
