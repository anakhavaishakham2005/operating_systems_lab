#include<stdio.h> 
int main() 
{ 
    int bt[20], p[20], wt[20], tt[20], pr[20], at[20], ct[20];
    int i, j, limit, sum = 0, position, temp;
    int current_time = 0, completed_count = 0;
    int completed[20] = {0};
    float avg_wt, avg_tt;
    
    printf("Enter Total Number of Processes:\t"); 
    scanf("%d", &limit); 
    
    printf("\nEnter Arrival Time, Burst Time and Priority For %d Processes\n", limit); 
    for(i = 0; i < limit; i++) 
    { 
        printf("\nProcess[%d]\n", i + 1); 
        printf("Arrival Time:\t");
        scanf("%d", &at[i]);
        printf("Burst Time:\t"); 
        scanf("%d", &bt[i]); 
        printf("Priority:\t"); 
        scanf("%d", &pr[i]); 
        p[i] = i + 1; 
    } 
    
    // Non-Preemptive Priority Scheduling with Arrival Time
    printf("\nGantt Chart:\n");
    while (completed_count < limit) {
        int highest_priority = -1;
        int min_priority = 9999;
        
        // Find highest priority process among arrived processes
        for(i = 0; i < limit; i++) {
            if(at[i] <= current_time && !completed[i] && pr[i] < min_priority) {
                min_priority = pr[i];
                highest_priority = i;
            }
        }
        
        if(highest_priority == -1) {
            // No process has arrived yet, increment time
            current_time++;
        } else {
            // Execute the highest priority process
            printf("P%d executes from %d to %d\n", p[highest_priority], current_time, current_time + bt[highest_priority]);
            
            ct[highest_priority] = current_time + bt[highest_priority];
            current_time = ct[highest_priority];
            completed[highest_priority] = 1;
            completed_count++;
        }
    }
    
    // Calculate waiting time and turnaround time
    sum = 0;
    for(i = 0; i < limit; i++) 
    { 
        tt[i] = ct[i] - at[i];      // Turnaround Time = Completion Time - Arrival Time
        wt[i] = tt[i] - bt[i];      // Waiting Time = Turnaround Time - Burst Time
        sum = sum + wt[i];
    }
    
    avg_wt = sum / limit; 
    sum = 0; 
    
    printf("\nProcess ID\tArrival\tBurst\tPriority\tCompletion\tWaiting\tTurnaround\n");
    printf("\t\tTime\tTime\t\tTime\t\tTime\tTime\n");
    for(i = 0; i < limit; i++) 
    { 
        sum = sum + tt[i]; 
        printf("\n%d\t\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", p[i], at[i], bt[i], pr[i], ct[i], wt[i], tt[i]); 
    } 
    
    avg_tt = sum / limit; 
    printf("\nAverage Waiting Time:\t%f", avg_wt); 
    printf("\nAverage Turnaround Time:\t%f\n", avg_tt); 
    
    return 0; 
}
