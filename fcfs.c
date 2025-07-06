#include <stdio.h>
int main() {
    int i, j, n;
    int b[20], g[20], p[20], w[20], t[20], a[20];
    float avgw = 0, avgt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess ID: ");
        scanf("%d", &p[i]);
        printf("Burst Time: ");
        scanf("%d", &b[i]);
        printf("Arrival Time: ");
        scanf("%d", &a[i]);}
    // Sorting based on Arrival Time (FCFS)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                // Swap arrival time
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                // Swap burst time
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                // Swap process ID
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;}}}
    // Calculate completion time (Gantt chart values)
    g[0] = a[0]; // First process starts at its arrival time
    for(i = 0; i < n; i++) {
        if(g[i] < a[i]) g[i] = a[i]; // CPU idle time handling
        g[i + 1] = g[i] + b[i];}
    // Calculate turnaround and waiting times
    for(i = 0; i < n; i++) {
        t[i] = g[i + 1] - a[i];      // Turnaround time
        w[i] = t[i] - b[i];          // Waiting time
        avgw += w[i];
        avgt += t[i];}
    avgw /= n;
    avgt /= n;
    printf("\nPID\tArrivalT\tBurstT\tCompletionT\tWaitingT\tTurnaroundT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t%d\t\t%d\t\t%d\n", p[i], a[i], b[i], g[i + 1], w[i], t[i]);}
    printf("\nAverage Waiting Time: %.2f", avgw);
    printf("\nAverage Turnaround Time: %.2f\n", avgt);
    return 0;
}
