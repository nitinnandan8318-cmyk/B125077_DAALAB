// QUESTION 3 :
// Implement Quick Sort of N random elements store in a file.

// CODE---
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    fp = fopen("input.txt", "w");
    if (fp == NULL){
        printf("Unable to open file.\n");
        return 1;
    }
    //Write elements into file 
    for (int i = 0; i < n; i++){
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    /* Open file for reading */
    fp = fopen("input.txt", "r");
    if (fp == NULL){
        printf("Unable to open file.\n");
        return 1;
    }
    /* Read elements from file */
    for (int i = 0; i < n; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    printf("\nElements before sorting:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    /* Apply Quick Sort */
    quickSort(arr, 0, n - 1);
    printf("\n\nElements after sorting:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}