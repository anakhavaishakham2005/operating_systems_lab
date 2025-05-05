#include<stdio.h>
#define N 20
int pid[N], at[N], bt[N], q[N], a=0,gantt[N], seq[N], ct[N], tat[N], wt[N],sz, curr_time, f=-1, r=-1, m=0;
void get_details() {
printf("Enter the number of processes:");
scanf("%d", &sz);
for(int i=0; i<sz; i++) {printf("Enter process id: ");
scanf("%d", &pid[i]);
printf("Enter arrival time of p%d: ", pid[i]); 
scanf("%d", &at[i]);
printf("Enter burst time of p%d: ", 
pid[i]);scanf("%d", &bt[i]);}}
int min_pos(int a[], int n) {
int min = a[0], pos = 0;
for(int i=1; i<n; i++) {
if(a[i] < min) {
min = a[i];
pos = i;}} return pos;}
void set_curr_time() {
int min_at_pos = min_pos(at, sz);
curr_time = at[min_at_pos];}
void sort_at() {
int t1, t2, t3;
for(int i=0; i<sz-1; i++) {
for(int j=0; j<sz-1-i; j++) {
if(at[j] > at[j+1]) {
t1 = pid[j]; t2 = at[j]; t3 = bt[j];
pid[j] = pid[j+1];
at[j] = at[j+1];
bt[j] = bt[j+1];
pid[j+1] = t1;
at[j+1] = t2;
bt[j+1] = t3;}}}}
void enqueue(int x) {
if(r == (N-1)) {
printf("Queue overflow\n");
return;}
if(f == -1 && r == -1) {
f = 0;}
q[++r] = x;}
void enqueue_procs() {
for(int i=0; i<sz; i++) {
enqueue(pid[i]);}}
int dequeue() {
int x;
if(f == -1) {
printf("Queue underflow\n");
return -1;}
else{ x = q[f];
if(f == r)
f = r = -1;
else
f++;}return x;}
int find_index(int a[],int key,int n) {for(int i=0; i<n; i++) {
if(a[i] == key) return i;}
return -1;}
void get_seq() {
int curr_proc, proc_idx, curr_bt;
while(f != -1) {
gantt[m++] = curr_time;
curr_proc = dequeue();
seq[a++] = curr_proc;
proc_idx = find_index(pid, curr_proc, sz);
curr_bt = bt[proc_idx];
curr_time += curr_bt;
ct[proc_idx] = curr_time;}}
void calc_tat() {
for(int i=0; i<sz; i++) {
tat[i] = ct[i] - at[i];}}
void calc_wt() {
for(int i=0; i<sz; i++) {
wt[i] = tat[i] - bt[i];}}
void print_procs() {
printf("\n\nGantt Chart:\n");
printf("-------------------------------------------\n");
for(int i=0; i<sz; i++) {
printf("|\tP%d\t", pid[i]);
}
printf("|\n-------------------------------------------\n");
for(int i=0; i<sz+1; i++) {
printf("%d\t\t", gantt[i]); }
printf("\n\n");}
int main() {
get_details();set_curr_time();
sort_at();enqueue_procs();get_seq();gantt[m] = curr_time;calc_tat();
calc_wt();print_procs();}
