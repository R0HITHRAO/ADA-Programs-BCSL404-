#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int a[], int n)
{
    int i, j, k, temp;
        for(i = 0; i < n - 1; i++) {
        j = i; 
        for(k = i + 1; k < n; k++) {
            if(a[k] < a[j]) {
                j = k;
            }
        }
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
}
int main()
{
    int i, n;
    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int a[n];
    srand(time(NULL));
        for(i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }

    clock_t start = clock();
    selectionsort(a, n);
    clock_t end = clock();

    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n", duration);

    printf("The sorted order of the elements: ");
    for(i = 0; i < n; i++) {
    printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}