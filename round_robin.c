#include <stdio.h>

void roundRobin(int n, int at[], int bt[], int tq) {
    int rt[10], ct[10], tat[10], wt[10];
    int time = 0, remain = 0, queue[10], front = 0, rear = 0, inQueue[10] = {0};
    float avg_tat = 0, avg_wt = 0;
    int timeline[100]; // To store time after each process slice
    int timeline_index = 0;

    for (int i = 0; i < n; i++) 
        rt[i] = bt[i];

    for (int i = 0; i < n; i++) {
        if (at[i] == 0) {
            queue[rear++] = i;
            inQueue[i] = 1;
        }
    }

    printf("\nGantt Chart:\n|");
    timeline[timeline_index++] = time; // Store starting time (0)

    while (remain < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (at[i] == time && !inQueue[i]) {
                    queue[rear++] = i;
                    inQueue[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];
        printf(" P%d |", i + 1);

        if (rt[i] > tq) {
            time += tq;
            rt[i] -= tq;
        } else {
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
            remain++;
        }

        timeline[timeline_index++] = time; // Add current time to timeline

        for (int j = 0; j < n; j++) {
            if (at[j] <= time && !inQueue[j] && rt[j] > 0) {
                queue[rear++] = j;
                inQueue[j] = 1;
            }
        }

        if (rt[i] > 0) {
            queue[rear++] = i;
        }
    }

    // Print timeline below Gantt chart
    printf("\n");
    for (int i = 0; i < timeline_index; i++) {
        printf("%-5d", timeline[i]);
    }

    // Calculate TAT & WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];   // Turnaround Time = Completion Time - Arrival Time
        wt[i] = tat[i] - bt[i];   // Waiting Time = Turnaround Time - Burst Time
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
    printf("Average Waiting Time: %.2f\n", avg_wt / n);
}

int main() {
    int n, tq, at[10], bt[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    roundRobin(n, at, bt, tq);

    return 0;
}
