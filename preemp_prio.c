#include <stdio.h>
#define N 20

int pid[N], at[N], bt[N], rt[N], pr[N], wt[N], tat[N];
int gc[N * 10], gcp[N * 10];
int n, t = 0, done = 0, m = 0;

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Process ID: ");
        scanf("%d", &pid[i]);
        printf("Priority of P%d: ", pid[i]);
        scanf("%d", &pr[i]);
        printf("Arrival time of P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", pid[i]);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // copy burst to remaining time
    }
}

int find_proc() {
    int idx = -1, min_p = 1e9;
    for (int i = 0; i < n; i++) {
        if (at[i] <= t && rt[i] > 0) {
            if (pr[i] < min_p || (pr[i] == min_p && at[i] < at[idx])) {
                min_p = pr[i];
                idx = i;
            }
        }
    }
    return idx;
}

void schedule() {
    int prev = -1;
    while (done < n) {
        int idx = find_proc();
        gc[m] = t;
        if (idx != -1) {
            if (prev != pid[idx]) gcp[m++] = pid[idx]; // only add if process changes
            rt[idx]--;
            if (rt[idx] == 0) {
                done++;
                int end = t + 1;
                wt[idx] = end - at[idx] - bt[idx];
                tat[idx] = end - at[idx];
            }
        } else {
            gcp[m++] = -1; // idle time
        }
        t++;
        prev = (idx != -1) ? pid[idx] : -1;
    }
    gc[m] = t;
}

void print() {
    printf("\nPID\tPrio\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], pr[i], at[i], bt[i], wt[i], tat[i]);
    }
}

void gantt() {
    printf("\nGantt Chart:\n--------------------------------------------------\n");
    for (int i = 0; i < m; i++) {
        if (gcp[i] == -1)
            printf("| IDLE ");
        else
            printf("| P%d ", gcp[i]);
    }
    printf("|\n--------------------------------------------------\n");
    for (int i = 0; i <= m; i++) printf("%d\t", gc[i]);
    printf("\n");
}

float avg(int arr[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return (float)sum / n;
}

int main() {
    input();
    schedule();
    print();
    gantt();
    printf("\nAvg Waiting Time: %.2f", avg(wt));
    printf("\nAvg Turnaround Time: %.2f\n", avg(tat));
    return 0;
}
