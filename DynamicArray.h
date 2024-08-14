#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

// no templates in C :(

typedef struct {
    int *array;
    int size;
    int capacity;
} DynamicArray_int;

typedef struct {
    double *array;
    int size;
    int capacity;
} DynamicArray_double;

// Initialize dynamic array of ints
void initArray_int(DynamicArray_int *arr, int capacity);
// Free memory allocted to the dynamic array and set size/capacity to 0
void freeArray_int(DynamicArray_int *arr);
// Resize dynamic array to given capacity
void resizeArray_int(DynamicArray_int *arr, int newCapacity);
// Append int to dynamic array, resize if necesary
void insertArray_int(DynamicArray_int *arr, int value);

// Initialize dynamic array of doubles
void initArray_double(DynamicArray_double *arr, int capacity);
// Free memory allocted to the dynamic array and set size/capacity to 0
void freeArray_double(DynamicArray_double *arr);
// Resize dynamic array to given capacity
void resizeArray_double(DynamicArray_double *arr, int newCapacity);
// Append double to dynamic array, resize if necesary
void insertArray_double(DynamicArray_double *arr, double value);

#endif