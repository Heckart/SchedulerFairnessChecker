#ifndef SCHEDULINGALGOS_H
#define SCHEDULINGALGOS_H

typedef struct {
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turnaround_time;
} Process;

// Sort array of Processes by ascending arrival time using bubble sort 
void sort_arrival_time(Process processes[], int n);

// Simulate FIFO scheduling algorithm on array of Processes
void fifo(Process processes[], int n);
// Simulate SJF scheduling algorithm on array of Processes
void sjf(Process processes[], int n);
// Simulate SRT scheduling algorithm on array of Processes
void srt(Process processes[], int n);
// Simulate RR scheduling algorithm on array of Processes
void rr(Process processes[], int n, int time_quantum);

#endif