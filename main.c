#include <stdio.h> // printf()
#include <stdlib.h> // rand(), srand(), NULL
#include <time.h> // time()

#include "DynamicArray.h"     // DyanmicArray_int, DynamicArray_double
#include "SchedulingAlgos.h"  // Process, fifo(), sjf(), srt(), rr()
#include "AnalysisAlgos.h"    // calculate_throughput(), calculate_avg_wait_time(), calculate_avg_turnaround_time(), check_fairness()
                              // find_avg_throughput(), find_avg_waiting_time(), find_avg_turnaround_time(), find_fairness_percentage()

int main() 
{
	// Give random seed for number generation
    srand(time(NULL));

    const int NUM_FOR_PROCESSES1 = 5;
    const int MAX_ARRIVAL_TIME_1 = 10;
    const int MAX_BURST_TIME_1 = 10;

    const int NUM_FOR_PROCESSES2 = 10;
    const int MAX_ARRIVAL_TIME_2 = 20;
    const int MAX_BURST_TIME_2 = 20;

    const int NUM_FOR_PROCESSES3 = 50;
    const int MAX_ARRIVAL_TIME_3 = 100;
    const int MAX_BURST_TIME_3 = 100;

    const int NUM_FOR_PROCESSES4 = 100;
    const int MAX_ARRIVAL_TIME_4 = 1000;
    const int MAX_BURST_TIME_4 = 1000;

    const int TIME_QUANTUM_1 = 1;
    const int TIME_QUANTUM_3 = 3;
    const int TIME_QUANTUM_5 = 5;
    const int TIME_QUANTUM_10 = 10;

    // Hold the processes for each simulation
    Process processes1[NUM_FOR_PROCESSES1];
    Process processes2[NUM_FOR_PROCESSES2];
    Process processes3[NUM_FOR_PROCESSES3];
    Process processes4[NUM_FOR_PROCESSES4];

    /* If I had enough time, I would have combined each set of DynamicArray_doubles into one 2D dynamic array to decrease clutter */

    DynamicArray_double FIFO_AvgThroughput;        initArray_double(&FIFO_AvgThroughput, 1);
    DynamicArray_double FIFO_AvgWaitTime;          initArray_double(&FIFO_AvgWaitTime, 1);
    DynamicArray_double FIFO_AvgTurnaroundTime;    initArray_double(&FIFO_AvgTurnaroundTime, 1);
    DynamicArray_int FIFO_TotalFairness;           initArray_int(&FIFO_TotalFairness, 1);

    DynamicArray_double SJF_AvgThroughput;         initArray_double(&SJF_AvgThroughput, 1);
    DynamicArray_double SJF_AvgWaitTime;           initArray_double(&SJF_AvgWaitTime, 1);
    DynamicArray_double SJF_AvgTurnaroundTime;     initArray_double(&SJF_AvgTurnaroundTime, 1);
    DynamicArray_int SJF_TotalFairness;            initArray_int(&SJF_TotalFairness, 1);

    DynamicArray_double SRT_AvgThroughput;         initArray_double(&SRT_AvgThroughput, 1);
    DynamicArray_double SRT_AvgWaitTime;           initArray_double(&SRT_AvgWaitTime, 1);
    DynamicArray_double SRT_AvgTurnaroundTime;     initArray_double(&SRT_AvgTurnaroundTime, 1);
    DynamicArray_int SRT_TotalFairness;            initArray_int(&SRT_TotalFairness, 1);

    DynamicArray_double RR1_AvgThroughput;         initArray_double(&RR1_AvgThroughput, 1);
    DynamicArray_double RR1_AvgWaitTime;           initArray_double(&RR1_AvgWaitTime, 1);
    DynamicArray_double RR1_AvgTurnaroundTime;     initArray_double(&RR1_AvgTurnaroundTime, 1);
    DynamicArray_int RR1_TotalFairness;            initArray_int(&RR1_TotalFairness, 1);

    DynamicArray_double RR3_AvgThroughput;         initArray_double(&RR3_AvgThroughput, 1);
    DynamicArray_double RR3_AvgWaitTime;           initArray_double(&RR3_AvgWaitTime, 1);
    DynamicArray_double RR3_AvgTurnaroundTime;     initArray_double(&RR3_AvgTurnaroundTime, 1);
    DynamicArray_int RR3_TotalFairness;            initArray_int(&RR3_TotalFairness, 1);

    DynamicArray_double RR5_AvgThroughput;         initArray_double(&RR5_AvgThroughput, 1);
    DynamicArray_double RR5_AvgWaitTime;           initArray_double(&RR5_AvgWaitTime, 1);
    DynamicArray_double RR5_AvgTurnaroundTime;     initArray_double(&RR5_AvgTurnaroundTime, 1);
    DynamicArray_int RR5_TotalFairness;            initArray_int(&RR5_TotalFairness, 1);    

    DynamicArray_double RR10_AvgThroughput;         initArray_double(&RR10_AvgThroughput, 1);
    DynamicArray_double RR10_AvgWaitTime;           initArray_double(&RR10_AvgWaitTime, 1);
    DynamicArray_double RR10_AvgTurnaroundTime;     initArray_double(&RR10_AvgTurnaroundTime, 1);
    DynamicArray_int RR10_TotalFairness;            initArray_int(&RR10_TotalFairness, 1);


// perform simulations of a queue of 5 processes
for (int i = 0; i < 1000; i++)
{
    for (int i = 0; i < NUM_FOR_PROCESSES1; i++)
    {
        processes1[i].process_id = i + 1;
        processes1[i].arrival_time = rand() % (MAX_ARRIVAL_TIME_1 + 1);
        processes1[i].burst_time = rand() % MAX_BURST_TIME_1 + 1;
        processes1[i].waiting_time = 0;
        processes1[i].turnaround_time = 0;
    }

    fifo(processes1, NUM_FOR_PROCESSES1);
    insertArray_double(&FIFO_AvgThroughput, calculate_throughput(processes1, NUM_FOR_PROCESSES1)); // append new value to the array
    insertArray_double(&FIFO_AvgWaitTime, calculate_avg_wait_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&FIFO_AvgTurnaroundTime, calculate_avg_turnaround_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_int(&FIFO_TotalFairness, check_fairness(processes1, NUM_FOR_PROCESSES1));

    sjf(processes1, NUM_FOR_PROCESSES1);
    insertArray_double(&SJF_AvgThroughput, calculate_throughput(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&SJF_AvgWaitTime, calculate_avg_wait_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&SJF_AvgTurnaroundTime, calculate_avg_turnaround_time(processes1, NUM_FOR_PROCESSES1));    
    insertArray_int(&SJF_TotalFairness, check_fairness(processes1, NUM_FOR_PROCESSES1));

    srt(processes1, NUM_FOR_PROCESSES1);
    insertArray_double(&SRT_AvgThroughput, calculate_throughput(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&SRT_AvgWaitTime, calculate_avg_wait_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&SRT_AvgTurnaroundTime, calculate_avg_turnaround_time(processes1, NUM_FOR_PROCESSES1));    
    insertArray_int(&SRT_TotalFairness, check_fairness(processes1, NUM_FOR_PROCESSES1));

    rr(processes1, NUM_FOR_PROCESSES1, TIME_QUANTUM_1);
    insertArray_double(&RR1_AvgThroughput, calculate_throughput(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR1_AvgWaitTime, calculate_avg_wait_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR1_AvgTurnaroundTime, calculate_avg_turnaround_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_int(&RR1_TotalFairness, check_fairness(processes1, NUM_FOR_PROCESSES1));

    rr(processes1, NUM_FOR_PROCESSES1, TIME_QUANTUM_3);
    insertArray_double(&RR3_AvgThroughput, calculate_throughput(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR3_AvgWaitTime, calculate_avg_wait_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR3_AvgTurnaroundTime, calculate_avg_turnaround_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_int(&RR3_TotalFairness, check_fairness(processes1, NUM_FOR_PROCESSES1));
    
    rr(processes1, NUM_FOR_PROCESSES1, TIME_QUANTUM_5);
    insertArray_double(&RR5_AvgThroughput, calculate_throughput(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR5_AvgWaitTime, calculate_avg_wait_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR5_AvgTurnaroundTime, calculate_avg_turnaround_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_int(&RR5_TotalFairness, check_fairness(processes1, NUM_FOR_PROCESSES1));
    

    rr(processes1, NUM_FOR_PROCESSES1, TIME_QUANTUM_10);
    insertArray_double(&RR10_AvgThroughput, calculate_throughput(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR10_AvgWaitTime, calculate_avg_wait_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_double(&RR10_AvgTurnaroundTime, calculate_avg_turnaround_time(processes1, NUM_FOR_PROCESSES1));
    insertArray_int(&RR10_TotalFairness, check_fairness(processes1, NUM_FOR_PROCESSES1));
}
    printf("Set of 5 processes results:");
    printf("\n---------------------------");
    printf("\nFIFO:");
    find_avg_throughput(&FIFO_AvgThroughput);    
    find_avg_waiting_time(&FIFO_AvgWaitTime);
    find_avg_turnaround_time(&FIFO_AvgTurnaroundTime);
    find_faireness_percentage(&FIFO_TotalFairness);

    printf("\nSJF:");
    find_avg_throughput(&SJF_AvgThroughput);
    find_avg_waiting_time(&SJF_AvgWaitTime);
    find_avg_turnaround_time(&SJF_AvgTurnaroundTime);
    find_faireness_percentage(&SJF_TotalFairness);

    printf("\nSRT:");
    find_avg_throughput(&SRT_AvgThroughput);
    find_avg_waiting_time(&SRT_AvgWaitTime);
    find_avg_turnaround_time(&SRT_AvgTurnaroundTime);
    find_faireness_percentage(&SRT_TotalFairness);

    printf("\nRR Quantum 1:");
    find_avg_throughput(&RR1_AvgThroughput);
    find_avg_waiting_time(&RR1_AvgWaitTime);
    find_avg_turnaround_time(&RR1_AvgTurnaroundTime);
    find_faireness_percentage(&RR1_TotalFairness);

    printf("\nRR Quantum 3:");
    find_avg_throughput(&RR3_AvgThroughput);
    find_avg_waiting_time(&RR3_AvgWaitTime);
    find_avg_turnaround_time(&RR3_AvgTurnaroundTime);
    find_faireness_percentage(&RR3_TotalFairness);

    printf("\nRR Quantum 5:");
    find_avg_throughput(&RR5_AvgThroughput);
    find_avg_waiting_time(&RR5_AvgWaitTime);
    find_avg_turnaround_time(&RR5_AvgTurnaroundTime);
    find_faireness_percentage(&RR5_TotalFairness);

    printf("\nRR Quantum 10:");
    find_avg_throughput(&RR10_AvgThroughput);
    find_avg_waiting_time(&RR10_AvgWaitTime);
    find_avg_turnaround_time(&RR10_AvgTurnaroundTime);
    find_faireness_percentage(&RR10_TotalFairness);

    freeArray_double(&FIFO_AvgThroughput); freeArray_double(&FIFO_AvgTurnaroundTime); freeArray_double(&FIFO_AvgWaitTime); freeArray_int(&FIFO_TotalFairness);
    freeArray_double(&SJF_AvgThroughput); freeArray_double(&SJF_AvgTurnaroundTime); freeArray_double(&SJF_AvgWaitTime); freeArray_int(&SJF_TotalFairness);
    freeArray_double(&SRT_AvgThroughput); freeArray_double(&SRT_AvgTurnaroundTime); freeArray_double(&SRT_AvgWaitTime); freeArray_int(&SRT_TotalFairness);
    freeArray_double(&RR1_AvgThroughput); freeArray_double(&RR1_AvgTurnaroundTime); freeArray_double(&RR1_AvgWaitTime); freeArray_int(&RR1_TotalFairness);
    freeArray_double(&RR3_AvgThroughput); freeArray_double(&RR3_AvgTurnaroundTime); freeArray_double(&RR3_AvgWaitTime); freeArray_int(&RR3_TotalFairness);
    freeArray_double(&RR5_AvgThroughput); freeArray_double(&RR5_AvgTurnaroundTime); freeArray_double(&RR5_AvgWaitTime); freeArray_int(&RR5_TotalFairness);
    freeArray_double(&RR10_AvgThroughput); freeArray_double(&RR10_AvgTurnaroundTime); freeArray_double(&RR10_AvgWaitTime); freeArray_int(&RR10_TotalFairness);

    DynamicArray_double FIFO_AvgThroughput2;        initArray_double(&FIFO_AvgThroughput2, 1);
    DynamicArray_double FIFO_AvgWaitTime2;          initArray_double(&FIFO_AvgWaitTime2, 1);
    DynamicArray_double FIFO_AvgTurnaroundTime2;    initArray_double(&FIFO_AvgTurnaroundTime2, 1);
    DynamicArray_int FIFO_TotalFairness2;           initArray_int(&FIFO_TotalFairness2, 1);

    DynamicArray_double SJF_AvgThroughput2;         initArray_double(&SJF_AvgThroughput2, 1);
    DynamicArray_double SJF_AvgWaitTime2;           initArray_double(&SJF_AvgWaitTime2, 1);
    DynamicArray_double SJF_AvgTurnaroundTime2;     initArray_double(&SJF_AvgTurnaroundTime2, 1);
    DynamicArray_int SJF_TotalFairness2;            initArray_int(&SJF_TotalFairness2, 1);

    DynamicArray_double SRT_AvgThroughput2;         initArray_double(&SRT_AvgThroughput2, 1);
    DynamicArray_double SRT_AvgWaitTime2;           initArray_double(&SRT_AvgWaitTime2, 1);
    DynamicArray_double SRT_AvgTurnaroundTime2;     initArray_double(&SRT_AvgTurnaroundTime2, 1);
    DynamicArray_int SRT_TotalFairness2;            initArray_int(&SRT_TotalFairness2, 1);

    DynamicArray_double RR1_AvgThroughput2;         initArray_double(&RR1_AvgThroughput2, 1);
    DynamicArray_double RR1_AvgWaitTime2;           initArray_double(&RR1_AvgWaitTime2, 1);
    DynamicArray_double RR1_AvgTurnaroundTime2;     initArray_double(&RR1_AvgTurnaroundTime2, 1);
    DynamicArray_int RR1_TotalFairness2;            initArray_int(&RR1_TotalFairness2, 1);

    DynamicArray_double RR3_AvgThroughput2;         initArray_double(&RR3_AvgThroughput2, 1);
    DynamicArray_double RR3_AvgWaitTime2;           initArray_double(&RR3_AvgWaitTime2, 1);
    DynamicArray_double RR3_AvgTurnaroundTime2;     initArray_double(&RR3_AvgTurnaroundTime2, 1);
    DynamicArray_int RR3_TotalFairness2;            initArray_int(&RR3_TotalFairness2, 1);

    DynamicArray_double RR5_AvgThroughput2;         initArray_double(&RR5_AvgThroughput2, 1);
    DynamicArray_double RR5_AvgWaitTime2;           initArray_double(&RR5_AvgWaitTime2, 1);
    DynamicArray_double RR5_AvgTurnaroundTime2;     initArray_double(&RR5_AvgTurnaroundTime2, 1);
    DynamicArray_int RR5_TotalFairness2;            initArray_int(&RR5_TotalFairness2, 1);    

    DynamicArray_double RR10_AvgThroughput2;         initArray_double(&RR10_AvgThroughput2, 1);
    DynamicArray_double RR10_AvgWaitTime2;           initArray_double(&RR10_AvgWaitTime2, 1);
    DynamicArray_double RR10_AvgTurnaroundTime2;     initArray_double(&RR10_AvgTurnaroundTime2, 1);
    DynamicArray_int RR10_TotalFairness2;            initArray_int(&RR10_TotalFairness2, 1);


// perform simulations of a queue of 10 processes
for (int i = 0; i < 1000; i++)
{

    for (int i = 0; i < NUM_FOR_PROCESSES2; i++)
    {
        processes2[i].process_id = i + 1;
        processes2[i].arrival_time = rand() % (MAX_ARRIVAL_TIME_2 + 1);
        processes2[i].burst_time = rand() % MAX_BURST_TIME_2 + 1;
        processes2[i].waiting_time = 0;
        processes2[i].turnaround_time = 0;
    }

    fifo(processes2, NUM_FOR_PROCESSES2);
    insertArray_double(&FIFO_AvgThroughput2, calculate_throughput(processes2, NUM_FOR_PROCESSES2)); // append new value to the array
    insertArray_double(&FIFO_AvgWaitTime2, calculate_avg_wait_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&FIFO_AvgTurnaroundTime2, calculate_avg_turnaround_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_int(&FIFO_TotalFairness2, check_fairness(processes2, NUM_FOR_PROCESSES2));

    sjf(processes2, NUM_FOR_PROCESSES2);
    insertArray_double(&SJF_AvgThroughput2, calculate_throughput(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&SJF_AvgWaitTime2, calculate_avg_wait_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&SJF_AvgTurnaroundTime2, calculate_avg_turnaround_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_int(&SJF_TotalFairness2, check_fairness(processes2, NUM_FOR_PROCESSES2));

    srt(processes2, NUM_FOR_PROCESSES2);
    insertArray_double(&SRT_AvgThroughput2, calculate_throughput(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&SRT_AvgWaitTime2, calculate_avg_wait_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&SRT_AvgTurnaroundTime2, calculate_avg_turnaround_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_int(&SRT_TotalFairness2, check_fairness(processes2, NUM_FOR_PROCESSES2));

    rr(processes2, NUM_FOR_PROCESSES2, TIME_QUANTUM_1);
    insertArray_double(&RR1_AvgThroughput2, calculate_throughput(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR1_AvgWaitTime2, calculate_avg_wait_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR1_AvgTurnaroundTime2, calculate_avg_turnaround_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_int(&RR1_TotalFairness2, check_fairness(processes2, NUM_FOR_PROCESSES2));

    rr(processes2, NUM_FOR_PROCESSES2, TIME_QUANTUM_3);
    insertArray_double(&RR3_AvgThroughput2, calculate_throughput(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR3_AvgWaitTime2, calculate_avg_wait_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR3_AvgTurnaroundTime2, calculate_avg_turnaround_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_int(&RR3_TotalFairness2, check_fairness(processes2, NUM_FOR_PROCESSES2));

    rr(processes2, NUM_FOR_PROCESSES2, TIME_QUANTUM_5);
    insertArray_double(&RR5_AvgThroughput2, calculate_throughput(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR5_AvgWaitTime2, calculate_avg_wait_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR5_AvgTurnaroundTime2, calculate_avg_turnaround_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_int(&RR5_TotalFairness2, check_fairness(processes2, NUM_FOR_PROCESSES2));

    rr(processes2, NUM_FOR_PROCESSES2, TIME_QUANTUM_10);
    insertArray_double(&RR10_AvgThroughput2, calculate_throughput(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR10_AvgWaitTime2, calculate_avg_wait_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_double(&RR10_AvgTurnaroundTime2, calculate_avg_turnaround_time(processes2, NUM_FOR_PROCESSES2));
    insertArray_int(&RR10_TotalFairness2, check_fairness(processes2, NUM_FOR_PROCESSES2));
}

    printf("\n---------------------------\n");
    printf("Set of 10 processes results:");
    printf("\n---------------------------");
    printf("\nFIFO:");
    find_avg_throughput(&FIFO_AvgThroughput2);    
    find_avg_waiting_time(&FIFO_AvgWaitTime2);
    find_avg_turnaround_time(&FIFO_AvgTurnaroundTime2);
    find_faireness_percentage(&FIFO_TotalFairness2);

    printf("\nSJF:");
    find_avg_throughput(&SJF_AvgThroughput2);
    find_avg_waiting_time(&SJF_AvgWaitTime2);
    find_avg_turnaround_time(&SJF_AvgTurnaroundTime2);
    find_faireness_percentage(&SJF_TotalFairness2);

    printf("\nSRT:");
    find_avg_throughput(&SRT_AvgThroughput2);
    find_avg_waiting_time(&SRT_AvgWaitTime2);
    find_avg_turnaround_time(&SRT_AvgTurnaroundTime2);
    find_faireness_percentage(&SRT_TotalFairness2);

    printf("\nRR Quantum 1:");
    find_avg_throughput(&RR1_AvgThroughput2);
    find_avg_waiting_time(&RR1_AvgWaitTime2);
    find_avg_turnaround_time(&RR1_AvgTurnaroundTime2);
    find_faireness_percentage(&RR1_TotalFairness2);

    printf("\nRR Quantum 3:");
    find_avg_throughput(&RR3_AvgThroughput2);
    find_avg_waiting_time(&RR3_AvgWaitTime2);
    find_avg_turnaround_time(&RR3_AvgTurnaroundTime2);
    find_faireness_percentage(&RR3_TotalFairness2);

    printf("\nRR Quantum 5:");
    find_avg_throughput(&RR5_AvgThroughput2);
    find_avg_waiting_time(&RR5_AvgWaitTime2);
    find_avg_turnaround_time(&RR5_AvgTurnaroundTime2);
    find_faireness_percentage(&RR5_TotalFairness2);

    printf("\nRR Quantum 10:");
    find_avg_throughput(&RR10_AvgThroughput2);
    find_avg_waiting_time(&RR10_AvgWaitTime2);
    find_avg_turnaround_time(&RR10_AvgTurnaroundTime2);
    find_faireness_percentage(&RR10_TotalFairness2);

    freeArray_double(&FIFO_AvgThroughput2); freeArray_double(&FIFO_AvgTurnaroundTime2); freeArray_double(&FIFO_AvgWaitTime2); freeArray_int(&FIFO_TotalFairness2);
    freeArray_double(&SJF_AvgThroughput2); freeArray_double(&SJF_AvgTurnaroundTime2); freeArray_double(&SJF_AvgWaitTime2); freeArray_int(&SJF_TotalFairness2);
    freeArray_double(&SRT_AvgThroughput2); freeArray_double(&SRT_AvgTurnaroundTime2); freeArray_double(&SRT_AvgWaitTime2); freeArray_int(&SRT_TotalFairness2);
    freeArray_double(&RR1_AvgThroughput2); freeArray_double(&RR1_AvgTurnaroundTime2); freeArray_double(&RR1_AvgWaitTime2); freeArray_int(&RR1_TotalFairness2);
    freeArray_double(&RR3_AvgThroughput2); freeArray_double(&RR3_AvgTurnaroundTime2); freeArray_double(&RR3_AvgWaitTime2); freeArray_int(&RR3_TotalFairness2);
    freeArray_double(&RR5_AvgThroughput2); freeArray_double(&RR5_AvgTurnaroundTime2); freeArray_double(&RR5_AvgWaitTime2); freeArray_int(&RR5_TotalFairness2);
    freeArray_double(&RR10_AvgThroughput2); freeArray_double(&RR10_AvgTurnaroundTime2); freeArray_double(&RR10_AvgWaitTime2); freeArray_int(&RR10_TotalFairness2);

    DynamicArray_double FIFO_AvgThroughput3;        initArray_double(&FIFO_AvgThroughput3, 1);
    DynamicArray_double FIFO_AvgWaitTime3;          initArray_double(&FIFO_AvgWaitTime3, 1);
    DynamicArray_double FIFO_AvgTurnaroundTime3;    initArray_double(&FIFO_AvgTurnaroundTime3, 1);
    DynamicArray_int FIFO_TotalFairness3;           initArray_int(&FIFO_TotalFairness3, 1);

    DynamicArray_double SJF_AvgThroughput3;         initArray_double(&SJF_AvgThroughput3, 1);
    DynamicArray_double SJF_AvgWaitTime3;           initArray_double(&SJF_AvgWaitTime3, 1);
    DynamicArray_double SJF_AvgTurnaroundTime3;     initArray_double(&SJF_AvgTurnaroundTime3, 1);
    DynamicArray_int SJF_TotalFairness3;            initArray_int(&SJF_TotalFairness3, 1);

    DynamicArray_double SRT_AvgThroughput3;         initArray_double(&SRT_AvgThroughput3, 1);
    DynamicArray_double SRT_AvgWaitTime3;           initArray_double(&SRT_AvgWaitTime3, 1);
    DynamicArray_double SRT_AvgTurnaroundTime3;     initArray_double(&SRT_AvgTurnaroundTime3, 1);
    DynamicArray_int SRT_TotalFairness3;            initArray_int(&SRT_TotalFairness3, 1);

    DynamicArray_double RR1_AvgThroughput3;         initArray_double(&RR1_AvgThroughput3, 1);
    DynamicArray_double RR1_AvgWaitTime3;           initArray_double(&RR1_AvgWaitTime3, 1);
    DynamicArray_double RR1_AvgTurnaroundTime3;     initArray_double(&RR1_AvgTurnaroundTime3, 1);
    DynamicArray_int RR1_TotalFairness3;            initArray_int(&RR1_TotalFairness3, 1);

    DynamicArray_double RR3_AvgThroughput3;         initArray_double(&RR3_AvgThroughput3, 1);
    DynamicArray_double RR3_AvgWaitTime3;           initArray_double(&RR3_AvgWaitTime3, 1);
    DynamicArray_double RR3_AvgTurnaroundTime3;     initArray_double(&RR3_AvgTurnaroundTime3, 1);
    DynamicArray_int RR3_TotalFairness3;            initArray_int(&RR3_TotalFairness3, 1);

    DynamicArray_double RR5_AvgThroughput3;         initArray_double(&RR5_AvgThroughput3, 1);
    DynamicArray_double RR5_AvgWaitTime3;           initArray_double(&RR5_AvgWaitTime3, 1);
    DynamicArray_double RR5_AvgTurnaroundTime3;     initArray_double(&RR5_AvgTurnaroundTime3, 1);
    DynamicArray_int RR5_TotalFairness3;            initArray_int(&RR5_TotalFairness3, 1);    

    DynamicArray_double RR10_AvgThroughput3;         initArray_double(&RR10_AvgThroughput3, 1);
    DynamicArray_double RR10_AvgWaitTime3;           initArray_double(&RR10_AvgWaitTime3, 1);
    DynamicArray_double RR10_AvgTurnaroundTime3;     initArray_double(&RR10_AvgTurnaroundTime3, 1);
    DynamicArray_int RR10_TotalFairness3;            initArray_int(&RR10_TotalFairness3, 1);

// perform simulations of a queue of 50 processes
for (int i = 0; i < 1000; i++)
{
    for (int i = 0; i < NUM_FOR_PROCESSES3; i++)
    {
        processes3[i].process_id = i + 1;
        processes3[i].arrival_time = rand() % (MAX_ARRIVAL_TIME_3 + 1);
        processes3[i].burst_time = rand() % MAX_BURST_TIME_3 + 1;
        processes3[i].waiting_time = 0;
        processes3[i].turnaround_time = 0;
    }

    fifo(processes3, NUM_FOR_PROCESSES3);
    insertArray_double(&FIFO_AvgThroughput3, calculate_throughput(processes3, NUM_FOR_PROCESSES3)); // append new value to the array
    insertArray_double(&FIFO_AvgWaitTime3, calculate_avg_wait_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&FIFO_AvgTurnaroundTime3, calculate_avg_turnaround_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_int(&FIFO_TotalFairness3, check_fairness(processes3, NUM_FOR_PROCESSES3));

    sjf(processes3, NUM_FOR_PROCESSES3);
    insertArray_double(&SJF_AvgThroughput3, calculate_throughput(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&SJF_AvgWaitTime3, calculate_avg_wait_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&SJF_AvgTurnaroundTime3, calculate_avg_turnaround_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_int(&SJF_TotalFairness3, check_fairness(processes3, NUM_FOR_PROCESSES3));

    srt(processes3, NUM_FOR_PROCESSES3);
    insertArray_double(&SRT_AvgThroughput3, calculate_throughput(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&SRT_AvgWaitTime3, calculate_avg_wait_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&SRT_AvgTurnaroundTime3, calculate_avg_turnaround_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_int(&SRT_TotalFairness3, check_fairness(processes3, NUM_FOR_PROCESSES3));

    rr(processes3, NUM_FOR_PROCESSES3, TIME_QUANTUM_1);
    insertArray_double(&RR1_AvgThroughput3, calculate_throughput(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR1_AvgWaitTime3, calculate_avg_wait_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR1_AvgTurnaroundTime3, calculate_avg_turnaround_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_int(&RR1_TotalFairness3, check_fairness(processes3, NUM_FOR_PROCESSES3));

    rr(processes3, NUM_FOR_PROCESSES3, TIME_QUANTUM_3);
    insertArray_double(&RR3_AvgThroughput3, calculate_throughput(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR3_AvgWaitTime3, calculate_avg_wait_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR3_AvgTurnaroundTime3, calculate_avg_turnaround_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_int(&RR3_TotalFairness3, check_fairness(processes3, NUM_FOR_PROCESSES3));

    rr(processes3, NUM_FOR_PROCESSES3, TIME_QUANTUM_5);
    insertArray_double(&RR5_AvgThroughput3, calculate_throughput(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR5_AvgWaitTime3, calculate_avg_wait_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR5_AvgTurnaroundTime3, calculate_avg_turnaround_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_int(&RR5_TotalFairness3, check_fairness(processes3, NUM_FOR_PROCESSES3));

    rr(processes3, NUM_FOR_PROCESSES3, TIME_QUANTUM_10);
    insertArray_double(&RR10_AvgThroughput3, calculate_throughput(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR10_AvgWaitTime3, calculate_avg_wait_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_double(&RR10_AvgTurnaroundTime3, calculate_avg_turnaround_time(processes3, NUM_FOR_PROCESSES3));
    insertArray_int(&RR10_TotalFairness3, check_fairness(processes3, NUM_FOR_PROCESSES3));

}

    printf("\n---------------------------\n");
    printf("Set of 50 processes results:");
    printf("\n---------------------------");
    printf("\nFIFO:");
    find_avg_throughput(&FIFO_AvgThroughput3);    
    find_avg_waiting_time(&FIFO_AvgWaitTime3);
    find_avg_turnaround_time(&FIFO_AvgTurnaroundTime3);
    find_faireness_percentage(&FIFO_TotalFairness3);

    printf("\nSJF:");
    find_avg_throughput(&SJF_AvgThroughput3);
    find_avg_waiting_time(&SJF_AvgWaitTime3);
    find_avg_turnaround_time(&SJF_AvgTurnaroundTime3);
    find_faireness_percentage(&SJF_TotalFairness3);

    printf("\nSRT:");
    find_avg_throughput(&SRT_AvgThroughput3);
    find_avg_waiting_time(&SRT_AvgWaitTime3);
    find_avg_turnaround_time(&SRT_AvgTurnaroundTime3);
    find_faireness_percentage(&SRT_TotalFairness3);

    printf("\nRR Quantum 1:");
    find_avg_throughput(&RR1_AvgThroughput3);
    find_avg_waiting_time(&RR1_AvgWaitTime3);
    find_avg_turnaround_time(&RR1_AvgTurnaroundTime3);
    find_faireness_percentage(&RR1_TotalFairness3);

    printf("\nRR Quantum 3:");
    find_avg_throughput(&RR3_AvgThroughput3);
    find_avg_waiting_time(&RR3_AvgWaitTime3);
    find_avg_turnaround_time(&RR3_AvgTurnaroundTime3);
    find_faireness_percentage(&RR3_TotalFairness3);

    printf("\nRR Quantum 5:");
    find_avg_throughput(&RR5_AvgThroughput3);
    find_avg_waiting_time(&RR5_AvgWaitTime3);
    find_avg_turnaround_time(&RR5_AvgTurnaroundTime3);
    find_faireness_percentage(&RR5_TotalFairness3);

    printf("\nRR Quantum 10:");
    find_avg_throughput(&RR10_AvgThroughput3);
    find_avg_waiting_time(&RR10_AvgWaitTime3);
    find_avg_turnaround_time(&RR10_AvgTurnaroundTime3);
    find_faireness_percentage(&RR10_TotalFairness3);

    freeArray_double(&FIFO_AvgThroughput3); freeArray_double(&FIFO_AvgTurnaroundTime3); freeArray_double(&FIFO_AvgWaitTime3); freeArray_int(&FIFO_TotalFairness3);
    freeArray_double(&SJF_AvgThroughput3); freeArray_double(&SJF_AvgTurnaroundTime3); freeArray_double(&SJF_AvgWaitTime3); freeArray_int(&SJF_TotalFairness3);
    freeArray_double(&SRT_AvgThroughput3); freeArray_double(&SRT_AvgTurnaroundTime3); freeArray_double(&SRT_AvgWaitTime3); freeArray_int(&SRT_TotalFairness3);
    freeArray_double(&RR1_AvgThroughput3); freeArray_double(&RR1_AvgTurnaroundTime3); freeArray_double(&RR1_AvgWaitTime3); freeArray_int(&RR1_TotalFairness3);
    freeArray_double(&RR3_AvgThroughput3); freeArray_double(&RR3_AvgTurnaroundTime3); freeArray_double(&RR3_AvgWaitTime3); freeArray_int(&RR3_TotalFairness3);
    freeArray_double(&RR5_AvgThroughput3); freeArray_double(&RR5_AvgTurnaroundTime3); freeArray_double(&RR5_AvgWaitTime3); freeArray_int(&RR5_TotalFairness3);
    freeArray_double(&RR10_AvgThroughput3); freeArray_double(&RR10_AvgTurnaroundTime3); freeArray_double(&RR10_AvgWaitTime3); freeArray_int(&RR10_TotalFairness3);

    DynamicArray_double FIFO_AvgThroughput4;        initArray_double(&FIFO_AvgThroughput4, 1);
    DynamicArray_double FIFO_AvgWaitTime4;          initArray_double(&FIFO_AvgWaitTime4, 1);
    DynamicArray_double FIFO_AvgTurnaroundTime4;    initArray_double(&FIFO_AvgTurnaroundTime4, 1);
    DynamicArray_int FIFO_TotalFairness4;           initArray_int(&FIFO_TotalFairness4, 1);

    DynamicArray_double SJF_AvgThroughput4;         initArray_double(&SJF_AvgThroughput4, 1);
    DynamicArray_double SJF_AvgWaitTime4;           initArray_double(&SJF_AvgWaitTime4, 1);
    DynamicArray_double SJF_AvgTurnaroundTime4;     initArray_double(&SJF_AvgTurnaroundTime4, 1);
    DynamicArray_int SJF_TotalFairness4;            initArray_int(&SJF_TotalFairness4, 1);

    DynamicArray_double SRT_AvgThroughput4;         initArray_double(&SRT_AvgThroughput4, 1);
    DynamicArray_double SRT_AvgWaitTime4;           initArray_double(&SRT_AvgWaitTime4, 1);
    DynamicArray_double SRT_AvgTurnaroundTime4;     initArray_double(&SRT_AvgTurnaroundTime4, 1);
    DynamicArray_int SRT_TotalFairness4;            initArray_int(&SRT_TotalFairness4, 1);

    DynamicArray_double RR1_AvgThroughput4;         initArray_double(&RR1_AvgThroughput4, 1);
    DynamicArray_double RR1_AvgWaitTime4;           initArray_double(&RR1_AvgWaitTime4, 1);
    DynamicArray_double RR1_AvgTurnaroundTime4;     initArray_double(&RR1_AvgTurnaroundTime4, 1);
    DynamicArray_int RR1_TotalFairness4;            initArray_int(&RR1_TotalFairness4, 1);

    DynamicArray_double RR3_AvgThroughput4;         initArray_double(&RR3_AvgThroughput4, 1);
    DynamicArray_double RR3_AvgWaitTime4;           initArray_double(&RR3_AvgWaitTime4, 1);
    DynamicArray_double RR3_AvgTurnaroundTime4;     initArray_double(&RR3_AvgTurnaroundTime4, 1);
    DynamicArray_int RR3_TotalFairness4;            initArray_int(&RR3_TotalFairness4, 1);

    DynamicArray_double RR5_AvgThroughput4;         initArray_double(&RR5_AvgThroughput4, 1);
    DynamicArray_double RR5_AvgWaitTime4;           initArray_double(&RR5_AvgWaitTime4, 1);
    DynamicArray_double RR5_AvgTurnaroundTime4;     initArray_double(&RR5_AvgTurnaroundTime4, 1);
    DynamicArray_int RR5_TotalFairness4;            initArray_int(&RR5_TotalFairness4, 1);    

    DynamicArray_double RR10_AvgThroughput4;         initArray_double(&RR10_AvgThroughput4, 1);
    DynamicArray_double RR10_AvgWaitTime4;           initArray_double(&RR10_AvgWaitTime4, 1);
    DynamicArray_double RR10_AvgTurnaroundTime4;     initArray_double(&RR10_AvgTurnaroundTime4, 1);
    DynamicArray_int RR10_TotalFairness4;            initArray_int(&RR10_TotalFairness4, 1);



// perform simulations of a queue of 100 processes
for (int i = 0; i < 1000; i++)
{


    for (int i = 0; i < NUM_FOR_PROCESSES4; i++)
    {
        processes4[i].process_id = i + 1;
        processes4[i].arrival_time = rand() % (MAX_ARRIVAL_TIME_4 + 1);
        processes4[i].burst_time = rand() % MAX_BURST_TIME_4 + 1;
        processes4[i].waiting_time = 0;
        processes4[i].turnaround_time = 0;
    }

    fifo(processes4, NUM_FOR_PROCESSES4);
    insertArray_double(&FIFO_AvgThroughput4, calculate_throughput(processes4, NUM_FOR_PROCESSES4)); // append new value to the array
    insertArray_double(&FIFO_AvgWaitTime4, calculate_avg_wait_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&FIFO_AvgTurnaroundTime4, calculate_avg_turnaround_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_int(&FIFO_TotalFairness4, check_fairness(processes4, NUM_FOR_PROCESSES4));

    sjf(processes4, NUM_FOR_PROCESSES4);
    insertArray_double(&SJF_AvgThroughput4, calculate_throughput(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&SJF_AvgWaitTime4, calculate_avg_wait_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&SJF_AvgTurnaroundTime4, calculate_avg_turnaround_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_int(&SJF_TotalFairness4, check_fairness(processes4, NUM_FOR_PROCESSES4));

    srt(processes4, NUM_FOR_PROCESSES4);
    insertArray_double(&SRT_AvgThroughput4, calculate_throughput(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&SRT_AvgWaitTime4, calculate_avg_wait_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&SRT_AvgTurnaroundTime4, calculate_avg_turnaround_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_int(&SRT_TotalFairness4, check_fairness(processes4, NUM_FOR_PROCESSES4));

    rr(processes4, NUM_FOR_PROCESSES4, TIME_QUANTUM_1);
    insertArray_double(&RR1_AvgThroughput4, calculate_throughput(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR1_AvgWaitTime4, calculate_avg_wait_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR1_AvgTurnaroundTime4, calculate_avg_turnaround_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_int(&RR1_TotalFairness4, check_fairness(processes4, NUM_FOR_PROCESSES4));

    rr(processes4, NUM_FOR_PROCESSES4, TIME_QUANTUM_3);
    insertArray_double(&RR3_AvgThroughput4, calculate_throughput(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR3_AvgWaitTime4, calculate_avg_wait_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR3_AvgTurnaroundTime4, calculate_avg_turnaround_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_int(&RR3_TotalFairness4, check_fairness(processes4, NUM_FOR_PROCESSES4));

    rr(processes4, NUM_FOR_PROCESSES4, TIME_QUANTUM_5);
    insertArray_double(&RR5_AvgThroughput4, calculate_throughput(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR5_AvgWaitTime4, calculate_avg_wait_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR5_AvgTurnaroundTime4, calculate_avg_turnaround_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_int(&RR5_TotalFairness4, check_fairness(processes4, NUM_FOR_PROCESSES4));

    rr(processes4, NUM_FOR_PROCESSES4, TIME_QUANTUM_10);
    insertArray_double(&RR10_AvgThroughput4, calculate_throughput(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR10_AvgWaitTime4, calculate_avg_wait_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_double(&RR10_AvgTurnaroundTime4, calculate_avg_turnaround_time(processes4, NUM_FOR_PROCESSES4));
    insertArray_int(&RR10_TotalFairness4, check_fairness(processes4, NUM_FOR_PROCESSES4));

}

    printf("\n---------------------------\n");
    printf("Set of 100 processes results:");
    printf("\n---------------------------");
    printf("\nFIFO:");
    find_avg_throughput(&FIFO_AvgThroughput4);    
    find_avg_waiting_time(&FIFO_AvgWaitTime4);
    find_avg_turnaround_time(&FIFO_AvgTurnaroundTime4);
    find_faireness_percentage(&FIFO_TotalFairness4);

    printf("\nSJF:");
    find_avg_throughput(&SJF_AvgThroughput4);
    find_avg_waiting_time(&SJF_AvgWaitTime4);
    find_avg_turnaround_time(&SJF_AvgTurnaroundTime4);
    find_faireness_percentage(&SJF_TotalFairness4);

    printf("\nSRT:");
    find_avg_throughput(&SRT_AvgThroughput4);
    find_avg_waiting_time(&SRT_AvgWaitTime4);
    find_avg_turnaround_time(&SRT_AvgTurnaroundTime4);
    find_faireness_percentage(&SRT_TotalFairness4);

    printf("\nRR Quantum 1:");
    find_avg_throughput(&RR1_AvgThroughput4);
    find_avg_waiting_time(&RR1_AvgWaitTime4);
    find_avg_turnaround_time(&RR1_AvgTurnaroundTime4);
    find_faireness_percentage(&RR1_TotalFairness4);

    printf("\nRR Quantum 3:");
    find_avg_throughput(&RR3_AvgThroughput4);
    find_avg_waiting_time(&RR3_AvgWaitTime4);
    find_avg_turnaround_time(&RR3_AvgTurnaroundTime4);
    find_faireness_percentage(&RR3_TotalFairness4);

    printf("\nRR Quantum 5:");
    find_avg_throughput(&RR5_AvgThroughput4);
    find_avg_waiting_time(&RR5_AvgWaitTime4);
    find_avg_turnaround_time(&RR5_AvgTurnaroundTime4);
    find_faireness_percentage(&RR5_TotalFairness4);

    printf("\nRR Quantum 10:");
    find_avg_throughput(&RR10_AvgThroughput4);
    find_avg_waiting_time(&RR10_AvgWaitTime4);
    find_avg_turnaround_time(&RR10_AvgTurnaroundTime4);
    find_faireness_percentage(&RR10_TotalFairness4);

    freeArray_double(&FIFO_AvgThroughput4); freeArray_double(&FIFO_AvgTurnaroundTime4); freeArray_double(&FIFO_AvgWaitTime4); freeArray_int(&FIFO_TotalFairness4);
    freeArray_double(&SJF_AvgThroughput4); freeArray_double(&SJF_AvgTurnaroundTime4); freeArray_double(&SJF_AvgWaitTime4); freeArray_int(&SJF_TotalFairness4);
    freeArray_double(&SRT_AvgThroughput4); freeArray_double(&SRT_AvgTurnaroundTime4); freeArray_double(&SRT_AvgWaitTime4); freeArray_int(&SRT_TotalFairness4);
    freeArray_double(&RR1_AvgThroughput4); freeArray_double(&RR1_AvgTurnaroundTime4); freeArray_double(&RR1_AvgWaitTime4); freeArray_int(&RR1_TotalFairness4);
    freeArray_double(&RR3_AvgThroughput4); freeArray_double(&RR3_AvgTurnaroundTime4); freeArray_double(&RR3_AvgWaitTime4); freeArray_int(&RR3_TotalFairness4);
    freeArray_double(&RR5_AvgThroughput4); freeArray_double(&RR5_AvgTurnaroundTime4); freeArray_double(&RR5_AvgWaitTime4); freeArray_int(&RR5_TotalFairness4);
    freeArray_double(&RR10_AvgThroughput4); freeArray_double(&RR10_AvgTurnaroundTime4); freeArray_double(&RR10_AvgWaitTime4); freeArray_int(&RR10_TotalFairness4);

	return 0;
}