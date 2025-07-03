#include <stdio.h> 
# define N 20
int pid[N], at[N], bt[N], wt[N],tat[N], seq[N], sz = 0, gantt[N] ={0}, done[N] = {0}, time = 0, m = 0,a = 0;
void get_details() {
printf("Enter number of processes:");
scanf("%d", &sz);
for (int i = 0; i < sz; i++) {
printf("Enter process id: ");
scanf("%d", &pid[i]);
printf("Enter arrival time of P%d: ",pid[i]);
scanf("%d", &at[i]);
printf("Enter burst time of P%d: ",pid[i]);
scanf("%d", &bt[i]);}}
int min_pos(int arr[N], int n) {
int min = arr[0], pos = 0;
for (int i = 1; i < n; i++) {
if (arr[i] < min) min = arr[i], pos =i;} return pos;}
void find_proc() {
int j = 0, k, cb[N], cp[N],min_pos_proc, cur_proc;
gantt[m++] = time;
for (int i = 0; i < sz; i++) {
if (at[i] <= time && !done[i]) cb[j]= bt[i], cp[j++] = pid[i];}
if (j > 0) {
min_pos_proc = min_pos(cb, j);
cur_proc = cp[min_pos_proc];
seq[a++] = cur_proc;
for (k = 0; k < sz; k++) {
if (cur_proc == pid[k]) {
done[k] = 1;break;}}
time += bt[k];}else time++;}
void set_time() {
time = at[min_pos(at, sz)];}

void calc_wt() {
for (int j = 0; j < sz; j++) {
for (int i = 0; i < a; i++) {
if (seq[i] == pid[j]) {
wt[j] = gantt[i] - at[j];break;}}}}
void calc_tat() {
for (int i = 0; i < sz; i++) 
  tat[i] =bt[i] + wt[i];}
float avg_wt() {
int sum = 0;
for (int i = 0; i < sz; i++) sum +=wt[i];return (float) sum / sz;}
float avg_tat() {
int sum = 0;
for (int i = 0; i < sz; i++) sum +=tat[i]; return (float) sum / sz;}
void print_proc() {
printf("PID\tAT\tBT\tWT\tTAT\n");
for (int i = 0; i < sz; i++)
printf("%d\t%d\t%d\t%d\t%d\n",pid[i], at[i], bt[i], wt[i], tat[i]);
printf("\nGantt Chart:\n-------------------------------------------------------\n");
for (int i = 0; i < a; i++)
printf("|\tP%d\t", seq[i]);
printf("|\n-------------------------------------------------------\n"); for (int i = 0; i <= m; i++)
printf("%d\t", gantt[i]);
printf("\n\n");}
int main() {
get_details();set_time();
for (int i = 0; i < sz; i++)
find_proc();
gantt[m] = time;calc_wt();calc_tat();
print_proc(); printf("Avg WT =%.4f\nAvg TAT = %.4f\n", avg_wt(),
avg_tat()); return 0;}
// 3 1 0 5 2 1 7 3 2 2 (063)(5 13 5)(3.000,7.6667)
