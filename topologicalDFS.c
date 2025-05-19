#include <stdio.h>

int n, a[10][10], res[10], visited[10], top = 0;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (a[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    res[top++] = node;
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    topologicalSort();

    printf("Topological Order: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
