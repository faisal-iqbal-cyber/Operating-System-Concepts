#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int wait_time;
};

int main() {
    int n;
    printf("Enter the No. of Processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the Arrival Time of Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the Burst Time of Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    int current_time = 0;
    int sum_turnaround_time = 0;
    int sum_wait_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;

        sum_turnaround_time += processes[i].turnaround_time;
        sum_wait_time += processes[i].wait_time;
    }

    float avg_turnaround_time = (float)sum_turnaround_time / n;
    float avg_wait_time = (float)sum_wait_time / n;

    printf("\nProcesses| Arrival Time | Burst Time | Completion Time | Turnaround Time | Wait Time\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n",processes[i].id,processes[i].arrival_time,processes[i].burst_time,processes[i].completion_time,processes[i].turnaround_time,processes[i].wait_time);
    }

    printf("\nThe Average Turnaround Time is: %.2f\n", avg_turnaround_time);
    printf("The Average Wait Time is: %.2f\n", avg_wait_time);

    return 0;
}

