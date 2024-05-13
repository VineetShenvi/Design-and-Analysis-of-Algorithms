#include <stdio.h>

int solution[100];
int weights[100];
int n, target_sum;


void subset_sum(int current_index, int current_sum, int solution_size) 
{
    if (current_sum == target_sum) {
        // Print the solution
        for (int i = 0; i < solution_size; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return;
    }

    // If current_sum exceeds target or we've processed all weights, backtrack
    if (current_sum > target_sum || current_index >= n) {
        return;
    }

    // Include the current weight in the solution
    solution[solution_size] = weights[current_index];
    subset_sum(current_index + 1, current_sum + weights[current_index], solution_size + 1);

    // Exclude the current weight (backtracking)
    subset_sum(current_index + 1, current_sum, solution_size);
}

int main() {
    int n, target_sum;

    printf("Enter the number of weights: ");
    scanf("%d", &n);

    int weights[n];
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    int solution[n]; // Array to store the solution subset
    subset_sum(0, 0, 0);

    return 0;
}
