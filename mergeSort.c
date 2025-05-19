#include <stdio.h>
#include <time.h>

void merge_sort(int a[], int low, int high);
void simple_sort(int a[], int low, int mid, int high);

int main() {
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];  // Variable length array

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Time taken to sort: %f seconds\n", time_taken);

    return 0;
}

void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        simple_sort(a, low, mid, high);
    }
}

void simple_sort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[high + 1];  // Temporary array for merging

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid) {
        c[k++] = a[i++];
    }

    while (j <= high) {
        c[k++] = a[j++];
    }

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
