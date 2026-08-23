#include <stdio.h>
#include <stdlib.h>

struct interval {
    int left;
    int right;
};

void input_set(struct interval *s, int size){
    for (int i = 0; i < size; i++) {
        printf("Enter the left then right endpoints of the interval:\n");
        scanf("%d %d", &(s[i].left), &(s[i].right));
    }
}

int compare(const void *a, const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int check_intersection(int *arrL, int *arrR, int size){
    int i = 0;
    int j = 0;
    int count = 0;
    int max_count = 0;
    int point = -1;
    while (i < size && j < size) {
        if (arrL[i] <= arrR[j]) {
            count++;
            if (count > max_count) {
                max_count = count;
                point = arrL[i];
            }
            i++;
        }else {
            count--;
            j++;
        }
    }
    printf("Maximum overlap = %d\n", max_count);
    return point;
}
int function(struct interval *s, int size){
    int *arr_left = malloc(size * sizeof(int));
    int *arr_right = malloc(size * sizeof(int));
    if (arr_left == NULL || arr_right == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        arr_left[i] = s[i].left;
        arr_right[i] = s[i].right;
    }
    qsort(arr_left, size, sizeof(int), compare);
    qsort(arr_right, size, sizeof(int), compare);
    int result = check_intersection(arr_left, arr_right, size);
    free(arr_left);
    free(arr_right);
    return result;
}
int main(){
    int size, n;
    printf("Enter the size of set: ");
    scanf("%d", &size);
    struct interval *set = malloc(size * sizeof(struct interval));
    if (set == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    input_set(set, size);
    n = function(set, size);
    if (n == -1)
        printf("No point found\n");
    else
        printf("Point = %d\n", n);
    free(set);
    return 0;
}