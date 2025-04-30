#include <stdio.h>

void roundRobin(int process[], int n, int burstTime[], int q)
{
    int waitingTime[n];
    int turnaroundTime[n];
    int remainingTime[n];
    float totalTurnaroundTime = 0, totalWaitingTime = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        remainingTime[i] = burstTime[i];
        waitingTime[i] = 0;
    }

    int currentTime = 0;
    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0)
            {
                done = 0;
                if (remainingTime[i] > q)
                {
                    currentTime += q;
                    remainingTime[i] -= q;
                }
                else
                {
                    currentTime += remainingTime[i];
                    waitingTime[i] = currentTime - burstTime[i];
                    turnaroundTime[i] = waitingTime[i] + burstTime[i];
                    remainingTime[i] = 0;
                }
            }
        }

        if (done == 1)
        {
            break;
        }
    }


    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }


    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int i;
    int process[n], burstTime[n], q;
    printf("Enter Burst Time of each Process: \n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        process[i] = i + 1;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &q);

    roundRobin(process, n, burstTime, q);

    return 0;
}
