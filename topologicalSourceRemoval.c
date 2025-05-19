#include <stdio.h>

int a[10][10], n, result[10], indegree[10];
int stack[10], top = -1;

void computeIndegree(int n, int a[][10]);
void tps_SourceRemoval(int n, int a[][10]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    computeIndegree(n, a);
    tps_SourceRemoval(n, a);

    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

void computeIndegree(int n, int a[][10]) {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            indegree[i] += a[j][i];
        }
    }
}

void tps_SourceRemoval(int n, int a[][10]) {
    int k = 0;

    // Push all nodes with 0 indegree into the stack
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    // Process nodes
    while (top != -1) {
        int v = stack[top--];  // Pop from stack
        result[k++] = v;

        for (int i = 0; i < n; i++) {
            if (a[v][i] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;  // Push to stack if indegree becomes 0
                }
            }
        }
    }
}
