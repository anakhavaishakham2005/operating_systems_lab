#include <stdio.h>
int main() {
    int i, j, n, temp;
    int p[20], b[20], a[20], w[20], t[20], g[21];
    int k = 1, min, btime = 0;
    float avgw = 0, avgt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nProcess ID: ");
        scanf("%d", &p[i]);
        printf("Burst Time: ");
        scanf("%d", &b[i]);
        printf("Arrival Time: ");
        scanf("%d", &a[i]);}
    // Sort based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // Swap arrival times
                temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
                // Swap burst times
                temp = b[j]; b[j] = b[j + 1]; b[j + 1] = temp;
                // Swap process IDs
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;}}}
    // Rearranging based on shortest job that has arrived
    for (i = 0; i < n; i++) {
        btime += b[i];
        min = b[k];
        for (j = k; j < n; j++) {
            if (btime >= a[j] && b[j] < min) {
                // Swap everything
                temp = a[k]; a[k] = a[j]; a[j] = temp;
                temp = b[k]; b[k] = b[j]; b[j] = temp;
                temp = p[k]; p[k] = p[j]; p[j] = temp;}}
        k++;}
    // Gantt chart construction
    g[0] = (a[0] > 0) ? a[0] : 0;
    for (i = 0; i < n; i++) {
        if (g[i] < a[i]) {
            g[i] = a[i];}
        g[i + 1] = g[i] + b[i];}
    // Calculating waiting time and turnaround time
    for (i = 0; i < n; i++) {
        t[i] = g[i + 1] - a[i];
        w[i] = t[i] - b[i];
        avgw += w[i];
        avgt += t[i];}
    avgw /= n;
    avgt /= n;
    printf("\nPID\tBurstTime\tGantt Chart\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) 
        printf("%d\t%d\t\t%d-%d\t\t%d\t\t%d\n", p[i], b[i], g[i], g[i + 1], w[i], t[i]);
    printf("\nAverage Waiting Time: %.2f", avgw);
    printf("\nAverage Turnaround Time: %.2f\n", avgt);
    return 0;}
