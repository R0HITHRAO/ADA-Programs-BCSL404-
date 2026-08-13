#include <stdio.h>
#define MAX 20

void floyd(int n, int d[MAX][MAX], int w[MAX][MAX]);
int min(int a, int b);

int main() {
int d[MAX][MAX]; // Temporary 2-D array for calculation
int w[MAX][MAX]; // 2-D array to store weight/cost matrix
int i, j, n;

printf("Enter the number of nodes/vertices: ");
scanf("%d", &n);

printf("Enter the Weight/cost matrix:\n");
for(i = 1; i <= n; i++) {
for(j = 1; j <= n; j++) {
scanf("%d", &w[i][j]);
}

}

floyd(n, d, w);

return 0;
}

void floyd(int n, int d[MAX][MAX], int w[MAX][MAX]) {
int i, j, k;

for(i = 1; i <= n; i++) {
for(j = 1; j <= n; j++) {
d[i][j] = w[i][j];
}
}

// Calculation of All-pair shortest paths
for(k = 1; k <= n; k++) {
for(i = 1; i <= n; i++) {
for(j = 1; j <= n; j++) {
d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

}
}

printf("All pair shortest path matrix is:\n");
for(i = 1; i <= n; i++) {
printf("\t%d", i);
}

printf("\n\t--------------------------------------------\n");
for(i = 1; i <= n; i++) {
printf("%d|\t", i);
for(j = 1; j <= n; j++) {
printf("%d\t", d[i][j]);
}
printf("\n");
}
}

// Method to find the minimum of two numbers
int min(int a, int b) {
return (a < b) ? a : b;
}