#include "AnalysisAlgos.h" // Process

/* The calculate functions calculate values for one run. The find functions calculate the average after multiple runs. */

// Calculuate throughput of a set of processes
double calculate_throughput(Process processes[], int n)
{
	// Calculate the end time of the last process by adding its arrival time and turnaround time
	double end_time = (double)processes[n - 1].arrival_time + processes[n - 1].turnaround_time;
	// Calculate and return the throughput by dividing the total number of processes by the end time
	return n / end_time;
}

// Calculate average waiting time of a set of processes
double calculate_avg_wait_time(Process processes[], int n) 
{
	int i;
	double total_wait_time = 0.0;

	// Iterate through the processes and sum up their waiting times
	for (i = 0; i < n; i++) 
    {
		total_wait_time += processes[i].waiting_time;
	}
	// Calculate and return the average waiting time by dividing the total waiting time by the number of processes
	return total_wait_time / n;
}

// Calculate averge turnaround time of a set of processes
double calculate_avg_turnaround_time(Process processes[], int n) 
{
	int i;
	double total_turnaround_time = 0.0;

	// Iterate through the processes and sum up their turnaround times
	for (i = 0; i < n; i++) 
    {
		total_turnaround_time += processes[i].turnaround_time;
	}
	// Calculate and return the average turnaround time by dividing the total turnaround time by the number of processes
	return total_turnaround_time / n;
}

/* Check fairness of scheduling algorithm.         */
/* A function is considered fair if each process   */
/* has a waiting time >= to the previous process's */
/* waiting time                                    */
int check_fairness(Process processes[], int n) 
{
	int i;

	// Iterate through the processes starting from the second one (index 1)
	for (i = 1; i < n; i++) 
    {
		// If the current process has a smaller waiting time than the previous process,
        // the scheduling is considered unfair, and the function returns 0
		if (processes[i].waiting_time < processes[i - 1].waiting_time) 
        {
			return 0;
		}
	}
	// If the waiting times of all processes follow the fairness criteria, the function returns 1
	return 1;
}

// Find average value of the collection of throughput
void find_avg_throughput(DynamicArray_double* arr)
{
	double total_throughput_arr = 0.0;
	double total_throughput_arr_avg = 0.0;
	// Iterate through the elements in the dynamic array and sum up the throughput values
	for (int i = 0; i < arr->size; i++)
	{
		total_throughput_arr += arr->array[i];
	}
	// Calculate the average throughput by dividing the total throughput by the number of elements in the dynamic array
	total_throughput_arr_avg = (double)total_throughput_arr/arr->size;
	printf("\nAverage throughput: %.5f", total_throughput_arr_avg);
	return;
}

// Find average value of the collection of waiting time
void find_avg_waiting_time(DynamicArray_double* arr)
{
	double total_waiting_time_arr = 0.0;
	double total_waiting_time_arr_avg = 0.0;
	// Iterate through the elements in the dynamic array and sum up the waiting time values
	for (int i = 0; i < arr->size; i++)
	{
		total_waiting_time_arr += arr->array[i];
	}
	// Calculate the average waiting time by dividing the total waiting time by the number of elements in the dynamic array
	total_waiting_time_arr_avg = (double)total_waiting_time_arr/arr->size;
	printf("\nAverage waiting time: %.5f", total_waiting_time_arr_avg);
	return;
}

// Find average value of the collection of turnaround time
void find_avg_turnaround_time(DynamicArray_double* arr)
{
	double total_turnaround_time_arr = 0.0;
	double total_turnaround_time_arr_avg = 0.0;
	// Iterate through the elements in the dynamic array and sum up the turnaround time values
	for (int i = 0; i < arr->size; i++)
	{
		total_turnaround_time_arr += arr->array[i];
	}
	// Calculate the average turnaround time by dividing the total turnaround time by the number of elements in the dynamic array
	total_turnaround_time_arr_avg = (double)total_turnaround_time_arr/arr->size;
	printf("\nAverage turnaround time: %.5f", total_turnaround_time_arr_avg);
	return;
}

// Find percentage of times a simulation was fair
void find_faireness_percentage(DynamicArray_int* arr)
{
    int total_fair=0;
    double fair_percentage = 0.0;
    // Iterate through the elements in the dynamic array and sum up the fairness values
	for (int i = 0; i < arr->size; i++)
    {
        total_fair = total_fair + arr->array[i];
    }
    // Calculate the fairness percentage by dividing the total number of fair cases by the number of elements in the dynamic array and multiplying by 100
	fair_percentage = (double)total_fair/arr->size * 100;
    printf("\nFair %.5f%% of the time\n", fair_percentage);
    return;
}