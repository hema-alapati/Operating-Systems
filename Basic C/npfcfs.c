#include<stdio.h>

struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void sort_by_arrival_time(struct process p[], int n) {
    int i, j;
    struct process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void FCFS_scheduling(struct process p[], int n)
{
    int i;
    int current_time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;

    sort_by_arrival_time(p, n); // sort the processes based on arrival time

    for (i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].waiting_time = current_time - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        current_time = p[i].completion_time;
        waiting_time += p[i].waiting_time;
        turnaround_time += p[i].turnaround_time;
    }

    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %f", waiting_time * 1.0 / n);
    printf("\nAverage Turnaround Time: %f", turnaround_time * 1.0 / n);
}

int main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter the process ID: ");
        scanf("%d", &p[i].process_id);
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].burst_time);
    }

    FCFS_scheduling(p, n);

    return 0;
}
