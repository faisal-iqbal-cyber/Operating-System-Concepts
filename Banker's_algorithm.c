#include <stdio.h>
#include <stdbool.h>

#define N 5 // Number of processes
#define M 3 // Number of resources

void calculateNeed(int need[N][M], int max[N][M], int alloc[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

bool isSafe(int available[M], int max[N][M], int alloc[N][M]) {
    int need[N][M];
    calculateNeed(need, max, alloc);
    
    bool finish[N] = {false};
    int safeSequence[N];
    int work[M];
    for (int i = 0; i < M; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < N) {
        bool found = false;
        for (int i = 0; i < N; i++) {
            if (!finish[i]) {
                bool canExecute = true;
                for (int j = 0; j < M; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    for (int j = 0; j < M; j++) {
                        work[j] += alloc[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is in an unsafe state! Deadlock detected.\n");
            return false;
        }
    }
    printf("System is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < N; i++) {
        printf("P%d ", safeSequence[i] + 1); // Start from P1 instead of P0
        if (i < N - 1) printf("-> ");
    }
    printf("\n");
    return true;
}

int main() {
    int available[M] = {3, 3, 2};
    int allocation[N][M] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    int max[N][M] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {4, 2, 2},
        {5, 3, 3}
    };
    isSafe(available, max, allocation);
    return 0;
}

