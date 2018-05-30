#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define DEBUG 0
/* Author: Sean O'Donnell */

int numberOfValues()
{
    int vals = 0;
    scanf("%d", &vals);
    return (vals);
}

int numberOfDataSets()
{
    int sets = 0;
    printf("Enter the number of data sets: ");
    scanf("%d", &sets);
    return (sets);
}

float* data(int numValues)
{
    float *values;
    float *cursor;
    float value;
    values = malloc((numValues + 1) * sizeof(float));
    cursor = values;
    while (numValues > 0) {
        scanf(" %f", &value);
        *cursor = value;
        cursor++;
        numValues--;
    }
    *cursor = FLT_MIN;
    return (values);
}

float* dataSet(int number)
{
    int count;
    float *dataHead;
    printf("Enter data set %d: ", number);
    count = numberOfValues();
    if (DEBUG) printf("%d values\n", count);
    dataHead = data(count);
    return (dataHead);
}

float** allSets() {
    int numSets, i;
    float **sets;
    float **cursor;
    float *data;
    numSets = numberOfDataSets();
    if (DEBUG) printf("%d sets\n", numSets);
    sets = malloc((numSets + 1) * sizeof(float*));
    cursor = sets;
    for (i = 1; i <= numSets; i++) {
        data = dataSet(i);
        *cursor = data;
        cursor++;
    }
    *cursor = NULL;
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
    printf("Enter the # of the data set you'd like to calculate on: ");
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

float min(float *set)
{
    float *cursor;
    float min;
    cursor = set;
    min = FLT_MAX;
    while (*cursor != FLT_MIN) {
        if (*cursor < min) {
            min = *cursor;
        }
        cursor++;
    }
    return (min);
}

float max(float *set)
{
    float *cursor;
    float max;
    cursor = set;
    max = -1 * FLT_MAX;
    while (*cursor != FLT_MIN) {
        if (*cursor > max) {
            max = *cursor;
        }
        cursor++;
    }
    return (max);
}

float sum(float *set)
{
    float *cursor;
    float sum;
    cursor = set;
    sum = 0;
    while (*cursor != FLT_MIN) {
        sum += *cursor;
        cursor++;
    }
    return (sum);
}

float avg(float *set)
{
    float total, avg;
    float *cursor;
    int count;
    total = sum(set);
    cursor = set;
    count = 0;
    while (*cursor != FLT_MIN) {
        count++;
        cursor++;
    }
    avg = total / count;
    return (avg);
}

void print(float *set)
{
    float *cursor;
    cursor = set;
    while (*cursor != FLT_MIN) {
        printf("\t%f\n", *cursor);
        cursor++;
    }
}

void performCalculation(float **sets, int set, int calc)
{
    float **setsCursor;
    float *dataSet;
    int i;
    float result;
    setsCursor = sets;
    for (i = 1; i < set; i++) setsCursor++;
    dataSet = *setsCursor;
    switch (calc) {
        case 1:
            result = min(dataSet);
            printf("The minimum value of set %d is %f.\n", set, result);
            break;
        case 2:
            result = max(dataSet);
            printf("The maximum value of set %d is %f.\n", set, result);
            break;
        case 3:
            result = sum(dataSet);
            printf("The sum of all values in set %d is %f.\n", set, result);
            break;
        case 4:
            result = avg(dataSet);
            printf("The average of all values in set %d is %f.\n", set, result);
            break;
        case 5:
            printf("Set %d: \n", set);
            print(dataSet);
            break;
        default:
            break;
    }
    printf("\n");
}

void freeSetList(float **sets)
{
    float **setsCursor;
    float *dataCursor;
    void *current;
    setsCursor = sets;
    while (*setsCursor != NULL) {
        dataCursor = *setsCursor;
        free(dataCursor);
        setsCursor++;
    }
    free(sets);
}

int main()
{
    float **setsHead;
    float **setsCursor;
    float *dataCursor;
    int setToCalculate;
    int calculation;
    int i;
    setsHead = allSets();
    setsCursor = setsHead;
    i = 1;
    /*    if (DEBUG) { */
    while (*setsCursor != NULL) {
        printf("\nset %d:\n", i);
        dataCursor = *setsCursor;
        while (*dataCursor != FLT_MIN) {
            printf("\t%f\n", *dataCursor);
            dataCursor++;
        }
        printf("\n");
        setsCursor++;
        i++;
    }
    /*    } */
    setToCalculate = dataSetToCalculate();
    listCalculations();
    calculation = getCalculation();
    while (calculation != 6) {
        performCalculation(setsHead, setToCalculate, calculation);
        
        setToCalculate = dataSetToCalculate();
        listCalculations();
        calculation = getCalculation();
    }
    freeSetList(setsHead);
    
    return (0);
}
