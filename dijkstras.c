#include <stdio.h>

#define MAX 20
#define INF 999

int main() {
    int i, j, n, v, k, min, u;
    int c[MAX][MAX], s[MAX], d[MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &v);

    // Initialization
    for (i = 1; i <= n; i++) {
        s[i] = 0;             // Not visited
        d[i] = c[v][i];       // Initial distances from source
    }

    d[v] = 0;  // Distance to itself is 0
    s[v] = 1;  // Mark source as visited

    for (k = 2; k <= n; k++) {
        min = INF;
        u = -1;

        // Find the vertex with minimum distance
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1) break; // No reachable vertex

        s[u] = 1;

        // Update distances
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] > d[u] + c[u][i]) {
                d[i] = d[u] + c[u][i];
            }
        }
    }

    // Print result
    printf("\nThe shortest distance from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        if (d[i] != INF)
            printf("%d --> %d = %d\n", v, i, d[i]);
        else
            printf("%d --> %d = Unreachable\n", v, i);
    }

    return 0;
}
