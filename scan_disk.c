#include <stdio.h>
#include <stdlib.h>
// Function to sort the request queue
void sort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
int temp = arr[j];
arr[j] = arr[j + 1];arr[j + 1] = temp;}}}}
// SCAN Disk Scheduling Algorithm
void scan(int request[], int n, int head, int max) {
int seek_count = 0;
int seek_sequence[n + 2], seq_index = 0;
// Sort the request queue
sort(request, n);
// Find index where head should start processing
int index = 0;
while (index < n && request[index] < head) {
index++;
}
// Move in the increasing direction
for (int i = index; i < n; i++) {
seek_sequence[seq_index++] = request[i];
seek_count += abs(request[i] - head);
head = request[i];}
// Move to max track
if (head < max) {
seek_sequence[seq_index++] = max;
seek_count += abs(max - head);
head = max;}
// Move back towards 0
for (int i = index - 1; i >= 0; i--) {
seek_sequence[seq_index++] = request[i];
seek_count += abs(request[i] - head);
head = request[i];
}
// Print seek sequence and total seek count
printf("\nSeek Sequence: ");
for (int i = 0; i < seq_index; i++) {
printf("%d ", seek_sequence[i]);
}
printf("\nTotal Seek Count: %d\n", seek_count);
}
int main() {
int n, head, max;
// Taking user input
printf("Enter the number of requests: ");
scanf("%d", &n);
int *request = (int *)malloc(n * sizeof(int));
printf("Enter the request queue: ");
for (int i = 0; i < n; i++) {
scanf("%d", &request[i]);
}
printf("Enter the current head position: ");
scanf("%d", &head);
printf("Enter the maximum track number: ");
scanf("%d", &max);
// Call SCAN function
scan(request, n, head, max);
// Free allocated memory
free(request);
return 0;}
