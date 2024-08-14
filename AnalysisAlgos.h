#ifndef ANALYSISALGOS_H
#define ANALYSISALGOS_H
#include <stdio.h>           // printf()
#include "SchedulingAlgos.h" // Process
#include "DynamicArray.h"    // DynamicArray_int, DynamicArray_double

// Calculuate throughput of a set of processes
double calculate_throughput(Process processes[], int n);
// Calculate average waiting time of a set of processes
double calculate_avg_wait_time(Process processes[], int n);
// Calculate averge turnaround time of a set of processes
double calculate_avg_turnaround_time(Process processes[], int n);
/* Check fairness of scheduling algorithm.         */
/* A function is considered fair if each process   */
/* has a waiting time >= to the previous process's */
/* waiting time                                    */
int check_fairness(Process processes[], int n);

// Find average value of the collection of throughput
void find_avg_throughput(DynamicArray_double* arr);
// Find average value of the collection of waiting time
void find_avg_waiting_time(DynamicArray_double* arr);
// Find average value of the collection of turnaround time
void find_avg_turnaround_time(DynamicArray_double* arr);
// Find percentage of times a simulation was fair
void find_faireness_percentage(DynamicArray_int* arr);


#endif