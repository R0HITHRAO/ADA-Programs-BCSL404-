#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform selection sort
Void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; ++i) {
int minIndex = i;
for (int j = i + 1; j < n; ++j) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}

if (minIndex != i) {
// Swap arr[i] and arr[minIndex]
int temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}
}
}

int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d"
, &n);

// Generate n random numbers
int arr[n];
srand(time(NULL));
for (int i = 0; i < n; ++i) {

arr[i] = rand() % 10000; // Generate random numbers
between 0 and 9999
}

// Measure the time taken for sorting
clock_t start = clock();
selectionSort(arr, n);
clock_t end = clock();

double time_taken = ((double)(end - start)) /
CLOCKS_PER_SEC;

printf("Time taken for sorting: %f seconds\n"
,

time_taken);

return 0;
}