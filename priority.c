#include <stdio.h>
#define N 20

int pid[N], at[N], bt[N], pr[N], wt[N], tat[N], seq[N], done[N], gc[N];
int n = 0, t = 0, m = 0, a = 0;

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
    }
}

int min_pos(int arr[], int len) {
    int min = arr[0], pos = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

void schedule() {
    while (a < n) {
        gc[m++] = t;
        int found = 0, min_p = 1e9, min_at = 1e9, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= t) {
                if (pr[i] < min_p || (pr[i] == min_p && at[i] < min_at)) {
                    min_p = pr[i];
                    min_at = at[i];
                    idx = i;
                    found = 1;
                }
            }
        }

        if (!found) {
            int next_t = 1e9;
            for (int i = 0; i < n; i++) {
                if (!done[i] && at[i] < next_t) next_t = at[i];
            }
            t = next_t;
            gc[m++] = t;
            continue;
        }

        seq[a++] = pid[idx];
        wt[idx] = t - at[idx];
        t += bt[idx];
        tat[idx] = wt[idx] + bt[idx];
        done[idx] = 1;
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
    printf("\nGantt Chart:\n-----------------------------------\n");
    for (int i = 0; i < a; i++) printf("| P%d ", seq[i]);
    printf("|\n-----------------------------------\n");
    for (int i = 0; i <= a; i++) printf("%d\t", gc[i]);
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
