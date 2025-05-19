#include <stdio.h>
#include <time.h>

// Heapify subtree rooted at index i in array a[], size n
void heapify(int a[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // left child index
    int right = 2 * i + 2;  // right child index

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest); // Recursively heapify affected subtree
    }
}

void heapsort(int a[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}

int main() {
    int n, choice = 1;

    while (choice) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);
        int a[n];

        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        clock_t start = clock();
        heapsort(a, n);
        clock_t end = clock();

        printf("\nSorted elements:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %lf seconds\n", time_taken);

        printf("Do you wish to run again? (1/0): ");
        scanf("%d", &choice);
    }

    return 0;
}
