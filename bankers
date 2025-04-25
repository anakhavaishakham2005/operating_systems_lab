#include <stdio.h>
int available[10], allocation[10][10], max[10][10], need[10][10];
void main() {
int n, m;
printf("Input the number of processes: ");
scanf("%d", &n);
printf("Input the number of resource types: ");
scanf("%d", &m);
printf("\nAvailable Resources:\n");
for (int i = 0; i < m; i++)
scanf("%d", &available[i]);
printf("\nMax Matrix:\n");
for (int i = 0; i < n; i++) {
printf("Process %d: ", i);
for (int j = 0; j < m; j++)
scanf("%d", &max[i][j]);
}
printf("\nAllocation Matrix:\n");
for (int i = 0; i < n; i++) {
printf("Process %d: ", i);
for (int j = 0; j < m; j++) {
scanf("%d", &allocation[i][j]);
need[i][j] = max[i][j] - allocation[i][j];
}
}
int finish[10] = {0}, safe_sequence[10], z = 0;
for (int k = 0; k < n; k++) {
int allocated = 0;
for (int i = 0; i < n; i++) {
if (finish[i] == 0) {
int flag = 0;
for (int j = 0; j < m; j++) {
if (need[i][j] > available[j]) {
flag = 1;
break;
}
}
if (flag == 0) {
safe_sequence[z++] = i;
for (int y = 0; y < m; y++)
available[y] += allocation[i][y];
finish[i] = 1;
allocated = 1;
}
}
}
if (allocated == 0)
break;
}
int is_safe = 1;
for (int i = 0; i < n; i++) {
if (finish[i] == 0) {
is_safe = 0;
break;
}
}
if (is_safe) {
printf("\nSAFE Sequence is:\n");
for (int i = 0; i < n - 1; i++)
printf("P%d -> ", safe_sequence[i]);
printf("P%d\n", safe_sequence[n - 1]);
} else {
printf("\nThe system is in a DEADLOCK state!\n");}}
