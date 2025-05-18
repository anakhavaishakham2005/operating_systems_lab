#include <stdio.h>
#include <stdlib.h>
int main() {
int n;
printf("Input the number of requests: ");
scanf("%d", &n);
int *request = (int *)malloc(n * sizeof(int));
if (request == NULL) { // Check if memory allocation was successful
printf("Memory allocation failed!\n");
return 1;
}
printf("\nInput request array: ");
for (int i = 0; i < n; i++) {
scanf("%d", &request[i]);
}
int head;
printf("\nInput current head position: ");
scanf("%d", &head);
printf("\nSeek sequence is: ");
int seek_count = 0;
for (int i = 0; i < n; i++) {
printf("%d ", request[i]);
int distance = abs(request[i] - head);
seek_count += distance;
head = request[i];
}
printf("\nSeek count is: %d\n", seek_count);
free(request); // Free allocated memory
return 0;
}
