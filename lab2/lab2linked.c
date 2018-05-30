#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define DEBUG 0
/* Author: Sean O'Donnell */

typedef struct DataNode {
    struct DataNode *next;
    float value;
} DataNode;

typedef struct DataSet {
    DataNode *head;
    int count;
} DataSet;

typedef struct SetNode {
    struct SetNode *next;
    DataSet *data;
} SetNode;

typedef struct SetList {
    SetNode *head;
    int count;
} SetList;

int numberOfValues()
{
    int vals = 0;
    scanf("%d", &vals);
    return (vals);
}

DataNode* data(int numValues)
{
    /*
    DataNode *head;
    DataNode *previous;
    DataNode *new;
    float val;
    head = NULL;
    previous = NULL;
    do {
        if (DEBUG && previous != NULL) printf("previous->value = %f\n", previous->value);
        if (DEBUG && previous == NULL) printf("previous is NULL\n");
        
        scanf(" %f", &val);
        new = malloc(sizeof(DataNode));
        new->next = NULL;
        new->value = val;
        if (previous != NULL) {
            previous->next = new;
        } else {
            head = new;
            if (DEBUG) printf("head->value = %f\n", head->value);
        }
        previous = new;
        numValues--;
        
        if (DEBUG) printf("new->value = %f\n", previous->value);
    } while (numValues > 0);
    return (head);
     */
    
    float *values;
    float *cursor;
    float value;
    values = malloc((numValues + 1) * sizeof(float));
    cursor = values;
    while (numValues > 0) {
        scanf(" %f", &value);
        *cursor = value;
        cursor += sizeof(float);
    }
    *cursor = NULL;
    return values;
}

int numberOfDataSets()
{
    int sets = 0;
    printf("Enter the number of data sets: ");
    scanf("%d", &sets);
    return (sets);
}

DataSet* dataSet(int number)
{
    int count;
    DataNode *dataHead;
    DataSet *dataSet;
    printf("Enter data set %d: ", number);
    count = numberOfValues();
    dataHead = data(count);
    dataSet = malloc(sizeof(DataSet));
    dataSet->head = dataHead;
    dataSet->count = count;
    return (dataSet);
}

SetList* setList() {
    SetList *list;
    SetNode *previous;
    SetNode *new;
    DataSet *data;
    int numSets;
    int i;
    numSets = numberOfDataSets();
    list = malloc(sizeof(SetList));
    list->head = NULL;
    list->count = numSets;
    previous = NULL;
    i = 1;
    while (i <= numSets) {
        if (DEBUG) printf("Okay next set...\n");
        if (DEBUG && previous != NULL) printf("previous->data->count = %d\n", previous->data->count);
        if (DEBUG && previous == NULL) printf("previous is NULL\n");
        
        data = dataSet(i);
        new = malloc(sizeof(SetNode));
        new->next = NULL;
        new->data = data;
        if (previous != NULL) {
            previous->next = new;
        } else {
            list->head = new;
            if (DEBUG) printf("num elements in setlist head: %d\n", list->head->data->count);
        }
        previous = new;
        i++;
        
        if (DEBUG) printf("new->data->count = %d\n", previous->data->count);
    }
    return (list);
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

float min(DataSet *set)
{
    DataNode *cursor;
    float min;
    cursor = set->head;
    min = FLT_MAX;
    while (cursor != NULL) {
        if (cursor->value < min) {
            min = cursor->value;
        }
        cursor = cursor->next;
    }
    return (min);
}

float max(DataSet *set)
{
    DataNode *cursor;
    float max;
    cursor = set->head;
    max = FLT_MIN;
    while (cursor != NULL) {
        if (cursor->value > max) {
            max = cursor->value;
        }
        cursor = cursor->next;
    }
    return (max);
}

float sum(DataSet *set)
{
    DataNode *cursor;
    float sum;
    cursor = set->head;
    sum = 0;
    while (cursor != NULL) {
        sum += cursor->value;
        cursor = cursor->next;
    }
    return (sum);
}

float avg(DataSet *set)
{
    float total;
    float avg;
    total = sum(set);
    avg = total / set->count;
    return (avg);
}

void print(DataSet *set)
{
    DataNode *cursor;
    printf("Here is the set you selected:\n");
    cursor = set->head;
    while (cursor != NULL) {
        printf("\t%f\n", cursor->value);
        cursor = cursor->next;
    }
}

void performCalculation(SetList *list, int set, int calc)
{
    SetNode *setCursor;
    DataSet *dataSet;
    int i;
    float result;
    setCursor = list->head;
    for (i = 0; i < set - 1; i++) {
        setCursor = setCursor->next;
    }
    dataSet = setCursor->data;
    switch (calc) {
        case 1:
            result = min(dataSet);
            printf("The set's min is %f.\n", result);
            break;
        case 2:
            result = max(dataSet);
            printf("The set's max is %f.\n", result);
            break;
        case 3:
            result = sum(dataSet);
            printf("The set's sum is %f.\n", result);
            break;
        case 4:
            result = avg(dataSet);
            printf("The set's average is %f.\n", result);
            break;
        case 5:
            print(dataSet);
            break;
        default:
            break;
    }
    printf("\n");
}

void freeSetList(SetList *list)
{
    SetNode *setCursor;
    DataNode *dataCursor;
    void *current;
    DataSet *dataSet;
    setCursor = list->head;
    while (setCursor != NULL) {
        dataCursor = setCursor->data->head;
        while (dataCursor != NULL) {
            current = dataCursor;
            dataCursor = dataCursor->next;
            free(current);
        }
        free(setCursor->data);
        current = setCursor;
        setCursor = setCursor->next;
        free(current);
    }
    free(list);
}

int main()
{
    SetList *allSets;
    SetNode *setCursor;
    DataNode *dataCursor;
    int setToCalculate;
    int calculation;
    int i;
    allSets = setList();
    setCursor = allSets->head;
    i = 1;
/*    if (DEBUG) { */
        while (setCursor != NULL) {
            printf("\nset %d of %d:\n", i, allSets->count);
            dataCursor = setCursor->data->head;
            while (dataCursor != NULL) {
                printf("\t%f\n", dataCursor->value);
                dataCursor = dataCursor->next;
            }
            printf("\n");
            setCursor = setCursor->next;
            i++;
        }
/*    } */
    setToCalculate = dataSetToCalculate();
    listCalculations();
    calculation = getCalculation();
    while (calculation != 6) {
        performCalculation(allSets, setToCalculate, calculation);
        
        setToCalculate = dataSetToCalculate();
        listCalculations();
        calculation = getCalculation();
    }
    freeSetList(allSets);
    
    return (0);
}
