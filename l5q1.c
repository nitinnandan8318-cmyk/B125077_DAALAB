// QUESTION 1 :
// Find the median of a list of N numbers without sorting the list .
// Do the complexity analysis of your algorithm

// CODE---
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter length: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid length.\n");
        return 1;
    }
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }
    if (n == 1) {
        printf("Median is: %.2f\n", (float)arr[0]);
        free(arr);
        return 0;
    }
    if (n == 2) {
        printf("Median is: %.2f\n", (arr[0] + arr[1]) / 2.0);
        free(arr);
        return 0;
    }
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    int range = max - min + 1;
    int* count = (int*) calloc(range, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    int noOfElements = 0;
    if (n % 2 != 0) {
        int target = n / 2 + 1;
        for (int i = 0; i < range; i++) {
            noOfElements += count[i];
            if (noOfElements >= target) {
                printf("Median is: %.2f\n", (float)(i + min));
                break;
            }
        }
    } else {
        int target1 = n / 2;
        int target2 = n / 2 + 1;
        int mid1 = 0, mid2 = 0;
        int found1 = 0, found2 = 0;
        for (int i = 0; i < range; i++) {
            noOfElements += count[i];
            if (!found1 && noOfElements >= target1) {
                mid1 = i + min;
                found1 = 1;
            }
            if (!found2 && noOfElements >= target2) {
                mid2 = i + min;
                found2 = 1;
            }
            if (found1 && found2) {
                printf("Median is: %.2f\n", (mid1 + mid2) / 2.0);
                break;
            }
        }
    }
    free(count);
    free(arr);
    return 0;
}

// COMPLEXITY ANALYSIS
// Finding Minimum and Maximum — O(n)
// Creating Count Array — O(range)
// Counting Elements — O(n)
// Finding Median — O(range)
// Overall Time Complexity — O(n + range)
// Space Complexity — O(n + range)