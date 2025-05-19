#include <stdio.h>

#define INF 999  // Representation of infinity

int a[10][10], D[10][10], n;

void floyd(int [][10], int);
int min(int, int);

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no direct edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    floyd(a, n);

    printf("Distance Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void floyd(int a[][10], int n) {
    int i, j, k;

    // Initialize the distance matrix with input adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = a[i][j];
        }
    }

    // Floyd–Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
