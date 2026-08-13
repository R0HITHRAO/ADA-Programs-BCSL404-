#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[], int low, int mid, int high)
{
int i = low, j = mid + 1, k = low;
int c[1000000]; // Temporary array for merging

// Merging two sub-arrays
while (i <= mid && j <= high) {
if (a[i] < a[j]) {
c[k] = a[i];
i++;
} else {
c[k] = a[j];
j++;
}
k++;
}

// Copy remaining elements from left sub-array if any
while (i <= mid) {
c[k++] = a[i++];
}

// Copy remaining elements from right sub-array if any
while (j <= high) {
c[k++] = a[j++];
}

// Copy the merged array back to the original array
for (i = low; i <= high; i++) {
a[i] = c[i];
}
}

void mergeSort(int a[], int low, int high)
{
if (low < high)
{
int mid = (low + high) / 2;
mergeSort(a, low, mid); // Sort the left half
mergeSort(a, mid + 1, high); // Sort the right half
merge(a, low, mid, high); // Merge the sorted halves
}
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
// Generate n random numbers
int arr[n];
srand(time(NULL));
for (int i = 0; i < n; ++i) {
arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999

}
// Measure the time taken for sorting
clock_t start = clock();
mergeSort(arr, 0, n - 1);
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

printf("Time taken for sorting: %f seconds\n", time_taken);

return 0;
}