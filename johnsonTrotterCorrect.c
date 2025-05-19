#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

// Function to print a permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Function to find the largest mobile element
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        if ((dir[i] == LEFT && i != 0 && perm[i] > perm[i - 1]) ||
            (dir[i] == RIGHT && i != n - 1 && perm[i] > perm[i + 1])) {
            if (perm[i] > mobile) {
                mobile = perm[i];
            }
        }
    }
    return mobile;
}

// Function to get the index of the mobile element
int findIndex(int perm[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == mobile)
            return i;
    }
    return -1;
}

// Main function implementing Johnson-Trotter
void johnsonTrotter(int n) {
    int perm[n];
    int dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    // Print the first permutation
    printPermutation(perm, n);

    for (int count = 1; count < 1 << n; count++) {
        int mobile = getMobile(perm, dir, n);
        if (mobile == 0) break;

        int pos = findIndex(perm, n, mobile);
        int swapPos = (dir[pos] == LEFT) ? pos - 1 : pos + 1;

        // Swap the mobile element with the adjacent in its direction
        int temp = perm[pos];
        perm[pos] = perm[swapPos];
        perm[swapPos] = temp;

        int tempDir = dir[pos];
        dir[pos] = dir[swapPos];
        dir[swapPos] = tempDir;

        pos = swapPos;

        // Reverse direction of elements greater than mobile
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[i] = -dir[i];
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Permutations using Johnson-Trotter Algorithm:\n");
    johnsonTrotter(n);
    return 0;
}
