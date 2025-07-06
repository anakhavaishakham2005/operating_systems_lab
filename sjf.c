
    #include <stdio.h>

    int main() {
        int i, j, n;
        int p[20], bt[20], at[20], wt[20], tat[20], ct[20];
        int completed[20] = {0}; // Track completed processes
        float avg_wt = 0, avg_tat = 0;
        int current_time = 0;
        int completed_count = 0;
        
        printf("Enter the number of processes: ");
        scanf("%d", &n);
        
        // Input process details
        for (i = 0; i < n; i++) {
            printf("\nProcess %d:\n", i + 1);
            printf("Arrival Time: ");
            scanf("%d", &at[i]);
            printf("Burst Time: ");
            scanf("%d", &bt[i]);
            p[i] = i + 1; // Process ID
        }
        
        // Non-Preemptive SJF Algorithm
        while (completed_count < n) {
            int shortest_job = -1;
            int shortest_burst = 9999;
            
            // Find the shortest job among arrived processes
            for (i = 0; i < n; i++) {
                if (at[i] <= current_time && !completed[i] && bt[i] < shortest_burst) {
                    shortest_burst = bt[i];
                    shortest_job = i;
                }
            }
            
            if (shortest_job == -1) {
                // No process has arrived yet, increment time
                current_time++;
            } else {
                // Execute the shortest job
                printf("P%d executes from %d to %d\n", p[shortest_job], current_time, current_time + bt[shortest_job]);
                
                ct[shortest_job] = current_time + bt[shortest_job];
                current_time = ct[shortest_job];
                completed[shortest_job] = 1;
                completed_count++;
            }
        }
        
        // Calculate waiting time and turnaround time
        for (i = 0; i < n; i++) {
            tat[i] = ct[i] - at[i];      // Turnaround Time = Completion Time - Arrival Time
            wt[i] = tat[i] - bt[i];      // Waiting Time = Turnaround Time - Burst Time
            avg_wt += wt[i];
            avg_tat += tat[i];
        }
        
        avg_wt /= n;
        avg_tat /= n;
        
        // Display results
        printf("\nProcess\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
        printf("ID\tTime\tTime\tTime\t\tTime\tTime\n");
        for (i = 0; i < n; i++) {
            printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
        }
        
        printf("\nAverage Waiting Time: %.2f\n", avg_wt);
        printf("Average Turnaround Time: %.2f\n", avg_tat);
        
        return 0;
    }
