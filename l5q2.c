// QUESTION 2 : 
// Find the kth smallest element in a given list of N numbers without sorting
// the list. Do the complexity analysis of your algorithm 

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
    int k;
    printf("enter the value of k : ");
    scanf("%d",&k);
    int noOfElements = 0;
    int target = k;
    for (int i = 0; i < range; i++) {
        noOfElements += count[i];
        if (noOfElements >= target) {
            printf("Kth smallest element is : %d\n", (i + min));
            break;
        }
    }   
return 0;
}

// COMPLEXITY ANALYSIS
// Finding Minimum and Maximum — O(n)
// Creating Count Array — O(range)
// Counting Elements — O(n)
// Finding Kth Smallest Element — O(range)
// Overall Time Complexity — O(n + range)
// Space Complexity — O(n + range)