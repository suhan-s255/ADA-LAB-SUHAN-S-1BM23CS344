#include <stdio.h>

#define INF 999

int cost[10][10], t[10][2], sum;
int n;

void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    printf("Edges of the minimal spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }

    printf("Sum of minimal spanning tree: %d\n", sum);

    return 0;
}

void kruskal(int cost[10][10], int n) {
    int parent[10];
    int u, v, i, j, k = 0, count = 0;
    int min;

    sum = 0;

    // Initialize the parent array
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    while (count < n - 1) {
        min = INF;
        u = -1;
        v = -1;

        // Find the minimum edge (u, v) such that u and v are in different sets
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (find(parent, i) != find(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            int root_u = find(parent, u);
            int root_v = find(parent, v);

            // Union the sets
            parent[root_u] = root_v;

            t[k][0] = u;
            t[k][1] = v;
            k++;
            sum += min;
            count++;
        }
    }
}

int find(int parent[10], int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}
