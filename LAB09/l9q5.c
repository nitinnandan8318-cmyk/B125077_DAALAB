#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int n) {
    int* candies = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) candies[i] = 1;

    // Left to Right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to Left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            if (candies[i] < candies[i + 1] + 1) {
                candies[i] = candies[i + 1] + 1;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) total += candies[i];

    free(candies);
    return total;
}

int main() {
    int ratings[] = {1, 0, 2};
    int n = 3;
    printf("Minimum Candies Needed: %d\n", candy(ratings, n));
    return 0;
}