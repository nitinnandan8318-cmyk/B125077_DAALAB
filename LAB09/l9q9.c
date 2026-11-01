#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Dynamic programming evaluation of Alphabetic Tree (equivalent output to Hu-Tucker)
int huTuckerSim(int w[], int n) {
    int cost[100][100];
    int sum[100][100];

    for (int i = 0; i < n; i++) {
        sum[i][i] = w[i];
        cost[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            sum[i][j] = sum[i][j - 1] + w[j];
            cost[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int c = cost[i][k] + cost[k + 1][j] + sum[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int weights[] = {10, 15, 20, 25};
    int n = 4;
    printf("Minimum Weighted External Path Length: %d\n", huTuckerSim(weights, n));
    return 0;
}