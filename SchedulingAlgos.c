#include "SchedulingAlgos.h"

// Sort array of Processes by ascending arrival time using bubble sort 
void sort_arrival_time(Process processes[], const int n) 
{
	int i, j;
	Process temp;

    // Outer loop iterates over each element in the array except the last one
	for (i = 0; i < n - 1; i++) 
    {
        // Inner loop iterates over the unsorted part of the array
		for (j = 0; j < n - i - 1; j++) 
        {
            // If the current element's arrival time is greater than the next element's arrival time,
			// swap the elements to sort them in ascending order
			if (processes[j].arrival_time > processes[j + 1].arrival_time) 
            {
				temp = processes[j];
				processes[j] = processes[j + 1];
				processes[j + 1] = temp;
			}
		}
	}
}

// Simulate FIFO scheduling algorithm on array of Processes
void fifo(Process processes[], const int n) {
    int current_time = 0, i;

    // Sort the processes based on their arrival times using the 'sort_arrival_time' function
    sort_arrival_time(processes, n);

    // Iterate through each process in the sorted array
    for (i = 0; i < n; i++) {
        // If the current time is less than the arrival time of the current process,
        // set the current time to the process's arrival time
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        // Calculate the waiting time for the current process as the difference
        // between the current time and the process's arrival time
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        // Calculate the turnaround time for the current process as the sum of its
        // waiting time and burst time
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        // Increment the current time by the burst time of the current process
        current_time += processes[i].burst_time;
    }
}

// Simulate SJF scheduling algorithm on array of Processes
void sjf(Process processes[], const int n) 
{
    int current_time = 0, i, j, min_burst_time_index;
    int remaining_processes = n;
    int finished[n];
    
    // Initialize the 'finished' array to track completed processes
    for (i = 0; i < n; i++) 
    {
        finished[i] = 0;
    }

    // Sort the processes based on their arrival times using the 'sort_arrival_time' function
    sort_arrival_time(processes, n);

    // Continue processing while there are still remaining processes
    while (remaining_processes > 0) 
    {
        min_burst_time_index = -1;

        // Iterate through the processes to find the process with the shortest burst time
        // that has arrived and not been completed yet
        for (i = 0; i < n; i++) 
        {
            if (processes[i].arrival_time <= current_time && !finished[i]) 
            {
                if (min_burst_time_index == -1 || processes[i].burst_time < processes[min_burst_time_index].burst_time) 
                {
                    min_burst_time_index = i;
                }
            }
        }

        // If a process with the shortest burst time was found, process it
        if (min_burst_time_index != -1) 
        {
            // Calculate the waiting time and turnaround time for the selected process
            processes[min_burst_time_index].waiting_time = current_time - processes[min_burst_time_index].arrival_time;
            processes[min_burst_time_index].turnaround_time = processes[min_burst_time_index].waiting_time + processes[min_burst_time_index].burst_time;
            // Increment the current time by the burst time of the selected process.
            current_time += processes[min_burst_time_index].burst_time;
            // Mark the process as finished and decrement the remaining processes counter.
            finished[min_burst_time_index] = 1;
            remaining_processes--;
        } else 
        {
            // If no suitable process was found, increment the current time
            current_time++;
        }
    }
}

// Simulate SRT scheduling algorithm on array of Processes
void srt(Process processes[], const int n) 
{
    int current_time = 0, i, j, min_remaining_time_index;
    int remaining_processes = n;
    int remaining_burst_times[n];

    // Initialize the remaining burst times array with the initial burst times of each process
    for (i = 0; i < n; i++) 
    {
        remaining_burst_times[i] = processes[i].burst_time;
    }

     // Sort the processes based on their arrival times using the 'sort_arrival_time' function
    sort_arrival_time(processes, n);

    // Continue processing while there are still remaining processes
    while (remaining_processes > 0) 
    {
        min_remaining_time_index = -1;

        // Iterate through the processes to find the process with the shortest remaining time
        // that has arrived and not been completed yet
        for (i = 0; i < n; i++) 
        {
            if (processes[i].arrival_time <= current_time && remaining_burst_times[i] > 0) 
            {
                if (min_remaining_time_index == -1 || remaining_burst_times[i] < remaining_burst_times[min_remaining_time_index]) 
                {
                    min_remaining_time_index = i;
                }
            }
        }

        // If a process with the shortest remaining time was found, process it
        if (min_remaining_time_index != -1) 
        {
            // Decrement the remaining burst time for the selected process
            remaining_burst_times[min_remaining_time_index]--;

            // If the remaining burst time of the selected process is zero,
            // calculate its waiting time and turnaround time, and decrement
            // the remaining processes counter
            if (remaining_burst_times[min_remaining_time_index] == 0) 
            {
                processes[min_remaining_time_index].waiting_time = current_time + 1 - processes[min_remaining_time_index].arrival_time - processes[min_remaining_time_index].burst_time;
                processes[min_remaining_time_index].turnaround_time = processes[min_remaining_time_index].waiting_time + processes[min_remaining_time_index].burst_time;
                remaining_processes--;
            }

            // Increment the current time
            current_time++;
        } else 
        {
            // If no suitable process was found, increment the current time
            current_time++;
        }
    }
}

// Simulate RR scheduling algorithm on array of Processes
void rr(Process processes[], const int n, const int time_quantum) 
{
    int current_time = 0, i, j;
    int remaining_processes = n;
    int remaining_burst_times[n];

    // Initialize the remaining burst times array with the initial burst times of each process
    for (i = 0; i < n; i++) 
    {
        remaining_burst_times[i] = processes[i].burst_time;
    }

    // Sort the processes based on their arrival times using the 'sort_arrival_time' function
    sort_arrival_time(processes, n);

    // Continue processing while there are still remaining processes
    while (remaining_processes > 0) 
    {
        // Iterate through each process in the sorted array
        for (i = 0; i < n; i++) 
        {
            // Check if the process has arrived and has remaining burst time
            if (processes[i].arrival_time <= current_time && remaining_burst_times[i] > 0) 
            {
                // Calculate the time slice for the current process, based on the time_quantum
                int time_slice = (remaining_burst_times[i] >= time_quantum) ? time_quantum : remaining_burst_times[i];

                // Decrement the remaining burst time and increment the current time
                remaining_burst_times[i] -= time_slice;
                current_time += time_slice;

                // If the remaining burst time of the process is zero,
                // calculate its waiting time and turnaround time, and decrement
                // the remaining processes counter
                if (remaining_burst_times[i] == 0) 
                {
                    processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    remaining_processes--;
                }
            } else if (processes[i].arrival_time > current_time) 
            {
                // If the process has not arrived yet, increment the current time and break the loop
                current_time++;
                break;
            }
        }
    }
}