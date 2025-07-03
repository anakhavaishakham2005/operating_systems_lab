#include <stdio.h>
#define N 20

int pid[N], at[N], bt[N], ct[N], tat[N], wt[N], done[N];
int n, gantt[N];

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Process ID: ");
        scanf("%d", &pid[i]);
        printf("Arrival time of P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", pid[i]);
        scanf("%d", &bt[i]);
        done[i] = 0;
    }
}

int find_shortest(int t) {
    int idx = -1, min_bt = 1e9;
    for(int i = 0; i < n; i++) {
        if(at[i] <= t && !done[i] && bt[i] < min_bt) {
            min_bt = bt[i];
            idx = i;
        }
    }
    return idx;
}

void sjf() {
    int completed = 0, curr = 0, g = 0;
    gantt[g++] = curr;

    while(completed < n) {
        int idx = find_shortest(curr);
        if(idx == -1) {
            curr++; // idle
            continue;
        }

        curr += bt[idx];
        ct[idx] = curr;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        gantt[g++] = curr;
    }
}

void print_table() {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}

void print_gantt() {
    printf("\nGantt Chart:\n--------------------------------------------------\n");
    int last = 0;
    for(int i = 1; i < n+1; i++) {
        for(int j = 0; j < n; j++) {
            if(ct[j] == gantt[i]) {
                printf("|  P%d  ", pid[j]);
                break;
            }
        }
    }
    printf("|\n--------------------------------------------------\n");
    for(int i = 0; i <= n; i++) {
        printf("%d\t", gantt[i]);
    }
    printf("\n");
}

float avg(int arr[]) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return (float)sum / n;
}

int main() {
    input();
    sjf();
    print_table();
    print_gantt();
    printf("\nAverage Waiting Time: %.2f", avg(wt));
    printf("\nAverage Turnaround Time: %.2f\n", avg(tat));
    return 0;
}
