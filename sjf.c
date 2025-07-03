#include <stdio.h>
#define N 20

int pid[N], at[N], bt[N], ct[N], tat[N], wt[N];
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
    }
}

void sort_by_arrival() {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(at[j] > at[j+1]) {
                // Swap arrival time, burst time, process ID
                int temp;
                temp = at[j]; at[j] = at[j+1]; at[j+1] = temp;
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = pid[j]; pid[j] = pid[j+1]; pid[j+1] = temp;
            }
        }
    }
}

void fcfs() {
    int curr_time = 0;
    gantt[0] = curr_time;

    for(int i = 0; i < n; i++) {
        if(curr_time < at[i])
            curr_time = at[i]; // CPU idle

        curr_time += bt[i];
        ct[i] = curr_time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        gantt[i+1] = curr_time;
    }
}

void print_table() {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}

void print_gantt() {
    printf("\nGantt Chart:\n-------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("|  P%d  ", pid[i]);
    }
    printf("|\n-------------------------------------------------\n");
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
    sort_by_arrival();
    fcfs();
    print_table();
    print_gantt();
    printf("\nAverage Waiting Time: %.2f", avg(wt));
    printf("\nAverage Turnaround Time: %.2f\n", avg(tat));
    return 0;
}
