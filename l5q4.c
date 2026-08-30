// QUESTION 4 : 
// Implement Heap Sort to sort N randomly generated elements shared in a file.
// Do the complexity analysis of your algorithm


// CODE---
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){
    int n;
    FILE *fp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }
    fp = fopen("heap_input.txt", "w");
    if (fp == NULL){
        printf("Unable to open file.\n");
        return 1;
    }
    for (int i = 0; i < n; i++){
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    fp = fopen("heap_input.txt", "r");
    if (fp == NULL){
        printf("Unable to open file.\n");
        return 1;
    }
    for (int i = 0; i < n; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    printf("\nElements before sorting:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    heapSort(arr, n);
    printf("\n\nElements after sorting:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
// Complexity Analysis :
// swap() Function — O(1)
// heapify() Function — O(log n)
// Build Max Heap — O(n)
// Heap Sort — O(n log n)
// File Writing — O(n)
// File Reading — O(n)
// Overall Time Complexity — O(n log n)