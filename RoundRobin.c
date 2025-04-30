#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turn_arround_time;
};

void calculate_round_robin(struct Process processes[], int n, int Quantum_time) {
    int time = 0;
    int Completed = 0;
    while (Completed < n) {
        int i;
        int process_executed_in_this_round = 0; // Flag to track if any process is executed in this round
        for (i = 0; i < n; i++) {
            // Only consider processes that have arrived and still have remaining time
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time) {
                process_executed_in_this_round = 1; // Mark that a process was executed

                // If process can be completed in this round (remaining time is less than or equal to quantum time)
                if (processes[i].remaining_time <= Quantum_time) {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = time;
                    processes[i].turn_arround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turn_arround_time - processes[i].burst_time;
                    Completed++;
                } else {
                    // Process runs for the quantum time and remains in the queue for the next round
                    time += Quantum_time;
                    processes[i].remaining_time -= Quantum_time;
                }
            }
        }

        // If no process was executed in this round, increment time (idle time)
        if (!process_executed_in_this_round) {
            time++;
        }
    }
}

void display_processes(struct Process processes[], int n) {
    printf("Processor | Arrival time | Burst Time | Completion time | Turn Around Time | Wait Time\n");
    int j;
    for (j = 0; j < n; j++) {
        printf("Process %d\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n",
               j + 1, processes[j].arrival_time, processes[j].burst_time,
               processes[j].completion_time, processes[j].turn_arround_time, processes[j].waiting_time);
        printf("\n");
    }
}

int main() {
    int n;
    int Quantum_time;

    printf("\nEnter the No. of Processes: ");
    scanf("%d", &n);

    printf("\nEnter the Quantum Time (Fixed): ");
    scanf("%d", &Quantum_time);

    struct Process processes[n];

    printf("\nEnter the Details of the Processes\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter the Arrival Time of Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("\nEnter the Burst Time of Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        // Initialize remaining time to burst time
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculate_round_robin(processes, n, Quantum_time);

    printf("\n");

    display_processes(processes, n);

    return 0;
}
