#include<stdio.h> 
int main() 
{ int bt[20], p[20], wt[20], tt[20], pr[20]; 
int i, j, limit, sum = 0, position, temp; 
float avg_wt, avg_tt; 
printf("Enter Total Number of Processes:\t"); 
scanf("%d", &limit); 
printf("\nEnter Burst Time and Priority For %d Processes\n", limit); 
for(i = 0; i < limit; i++) 
{ printf("\nProcess[%d]\n", i + 1); 
printf("Process Burst Time:\t"); 
scanf("%d", &bt[i]); 
printf("Process Priority:\t"); 
scanf("%d", &pr[i]); 
p[i] = i + 1; } 
for(i = 0; i < limit; i++) 
{ position = i; 
for(j = i + 1; j < limit; j++) 
{ if(pr[j] < pr[position]) 
{ position = j; }}
temp = pr[i]; 
pr[i] = pr[position]; 
pr[position] = temp; 
temp = bt[i]; 
bt[i] = bt[position]; 
bt[position] = temp; 
temp = p[i]; 
p[i] = p[position]; 
p[position] = temp; }
wt[0] = 0; 
for(i = 1; i < limit; i++) 
{ wt[i] = 0; 
for(j = 0; j < i; j++) 
wt[i] = wt[i] + bt[j]; 
sum = sum + wt[i];}
avg_wt = sum / limit; 
sum = 0; 
printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n"); 
for(i = 0; i < limit; i++) 
{ tt[i] = bt[i] + wt[i]; 
sum = sum + tt[i]; 
printf("\n%d\t\t%d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tt[i]); }
avg_tt = sum / limit; 
printf("\nAverage Waiting Time:\t%f", avg_wt); 
printf("\nAverage Turnaround Time:\t%f\n", avg_tt); 
return 0; }
