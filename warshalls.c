#include <stdio.h>

int n;
int a[10][10];
int p[10][10];

// Function to read adjacency matrix
void read_data() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to compute path matrix (transitive closure)
void path_matrix() {
    int i, j, k;

    // Copy adjacency matrix to path matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = a[i][j];
        }
    }

    // Warshall's algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (p[i][k] && p[k][j])
                    p[i][j] = 1;
            }
        }
    }
}

// Function to display path matrix
void write_data() {
    int i, j;
    printf("The path matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

int main() {
    read_data();
    path_matrix();
    write_data();
    return 0;
}
