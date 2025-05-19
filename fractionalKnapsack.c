#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], profits[n];
    float ratio[n];
    int used[n];
    
    printf("Enter weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter profits of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    int capacity;
    printf("Enter capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Initialize used array to 0
    for (i = 0; i < n; i++) {
        used[i] = 0;
        ratio[i] = (float)profits[i] / weights[i];  // profit/weight ratio
    }

    int current_weight = capacity;
    float total_value = 0.0;

    while (current_weight > 0) {
        int maxi = -1;
        for (i = 0; i < n; i++) {
            if (!used[i]) {
                if (maxi == -1 || ratio[i] > ratio[maxi]) {
                    maxi = i;
                }
            }
        }
        if (maxi == -1) break;  // No items left

        used[maxi] = 1;

        if (weights[maxi] <= current_weight) {
            // Take whole item
            current_weight -= weights[maxi];
            total_value += profits[maxi];
            printf("Added item %d (%d weight, %d profit) completely. Space left: %d\n",
                   maxi + 1, weights[maxi], profits[maxi], current_weight);
        } else {
            // Take fraction of item
            float fraction = (float)current_weight / weights[maxi];
            total_value += profits[maxi] * fraction;
            printf("Added %.2f%% of item %d (%d weight, %d profit)\n",
                   fraction * 100, maxi + 1, weights[maxi], profits[maxi]);
            current_weight = 0;
        }
    }

    printf("Total profit in knapsack = %.2f\n", total_value);

    return 0;
}
