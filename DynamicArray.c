#include <stdlib.h> // malloc(), realloc(), free(), EXIT_FAILURE, NULL
#include <stdio.h> // printf()

#include "DynamicArray.h"

// Initialize dynamic array of ints
void initArray_int(DynamicArray_int *arr, int capacity) 
{
    arr->array = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

// Free memory allocted to the dynamic array and set size/capacity to 0
void freeArray_int(DynamicArray_int *arr) 
{
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

// Resize dynamic array to given capacity
void resizeArray_int(DynamicArray_int *arr, int newCapacity) 
{
    arr->array = (int *)realloc(arr->array, newCapacity * sizeof(int));
    if (arr->array) 
    {
        arr->capacity = newCapacity;
    } else 
    {
        printf("Error: live by the pointer, die by the pointer (realloc failed).\n");
        exit(EXIT_FAILURE);
    }
}

// Append int to dynamic array, resize if necesary
void insertArray_int(DynamicArray_int *arr, int value) 
{
    if (arr->size == arr->capacity) 
    {
        resizeArray_int(arr, 2 * arr->capacity);
    }

    arr->array[arr->size] = value;
    arr->size++;
}

// Initialize dynamic array of doubles
void initArray_double(DynamicArray_double *arr, int capacity) 
{
    arr->array = (double *)malloc(capacity * sizeof(double));
    arr->size = 0;
    arr->capacity = capacity;
}

// Free memory allocted to the dynamic array and set size/capacity to 0
void freeArray_double(DynamicArray_double *arr) 
{
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

// Resize dynamic array to given capacity
void resizeArray_double(DynamicArray_double *arr, int newCapacity) 
{
    arr->array = (double *)realloc(arr->array, newCapacity * sizeof(double));
    if (arr->array) 
    {
        arr->capacity = newCapacity;
    } else 
    {
        printf("Error: live by the pointer, die by the pointer (realloc failed).\n");
        exit(EXIT_FAILURE);
    }
}

// Append double to dynamic array, resize if necesary
void insertArray_double(DynamicArray_double *arr, double value) 
{
    if (arr->size == arr->capacity) 
    {
        resizeArray_double(arr, 2 * arr->capacity);
    }

    arr->array[arr->size] = value;
    arr->size++;
}