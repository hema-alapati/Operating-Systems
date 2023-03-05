// #include<stdio.h>

// struct process {
//     int process_id;
//     int arrival_time;
//     int burst_time;
//     int completion_time;
//     int waiting_time;
//     int turnaround_time;
// };

// int find_earliest_arrival(struct process p[], int n) {
//     int i, earliest_arrival = p[0].arrival_time, earliest_arrival_index = 0;
//     for (i = 1; i < n; i++) {
//         if (p[i].arrival_time < earliest_arrival) {
//             earliest_arrival = p[i].arrival_time;
//             earliest_arrival_index = i;
//         }
//     }
//     return earliest_arrival_index;
// }

// void sort_by_burst_time(struct process p[], int n) {
//     int i, j;
//     struct process temp;
//     for (i = 0; i < n - 1; i++) {
//         for (j = i + 1; j < n; j++) {
//             if (p[i].burst_time > p[j].burst_time) {
//                 temp = p[i];
//                 p[i] = p[j];
//                 p[j] = temp;
//             }
//         }
//     }
// }

// void NPSJF_scheduling(struct process p[], int n)
// {
//     int i, earliest_arrival_index;
//     int current_time = 0;
//     int waiting_time = 0;
//     int turnaround_time = 0;

//     earliest_arrival_index = find_earliest_arrival(p, n);
//     struct process temp = p[0];
//     p[0] = p[earliest_arrival_index];
//     p[earliest_arrival_index] = temp;
//     sort_by_burst_time(p+1, n-1); // sort the remaining processes by burst time
//     for (i = 1; i < n; i++) {
//         p[i].process_id = p[i+1].process_id;
//         p[i].arrival_time = p[i+1].arrival_time;
//         p[i].burst_time = p[i+1].burst_time;
//     }

//     for (i = 0; i < n; i++) {
//         if (current_time < p[i].arrival_time)
//             current_time = p[i].arrival_time;
//         p[i].completion_time = current_time + p[i].burst_time;
//         p[i].waiting_time = current_time - p[i].arrival_time;
//         p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
//         current_time = p[i].completion_time;
//         waiting_time += p[i].waiting_time;
//         turnaround_time += p[i].turnaround_time;
//     }

//     printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
//     for (i = 0; i < n; i++) {
//         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
//     }

//     printf("\nAverage Waiting Time: %f", waiting_time * 1.0 / n);
//     printf("\nAverage Turnaround Time: %f", turnaround_time * 1.0 / n);
// }

// int main()
// {
//     int n, i;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     struct process p[n];
//     for (i = 0; i < n; i++) {
//         printf("\nEnter the process ID: ");
//         scanf("%d", &p[i].process_id);
//         printf("Enter the arrival time: ");
//         scanf("%d", &p[i].arrival_time);
//         printf("Enter the burst time: ");
//         scanf("%d", &p[i].burst_time);
//     }

//     NPSJF_scheduling(p, n);

//     return 0;
// }
#include <stdio.h>
int main()
{
	int A[100][4]; // Matrix for storing Process Id, Burst
				// Time, Average Waiting Time & Average
				// Turn Around Time.
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");
	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}
	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("P	 BT	 WT	 TAT\n");
	// Calculation of Turn Around Time and printing the
	// data.
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("P%d	 %d	 %d	 %d\n", A[i][0],
			A[i][1], A[i][2], A[i][3]);
	}
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
}
