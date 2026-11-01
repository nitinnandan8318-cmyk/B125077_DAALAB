#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[1000];
    int size;
} MaxHeap;

void push(MaxHeap *hp, int val) {
    hp->data[hp->size] = val;
    int i = hp->size++;
    while (i > 0 && hp->data[(i - 1) / 2] < hp->data[i]) {
        int t = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = hp->data[i];
        hp->data[i] = t;
        i = (i - 1) / 2;
    }
}

int pop(MaxHeap *hp) {
    int top = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, max_i = left;
        if (right < hp->size && hp->data[right] > hp->data[left]) max_i = right;
        if (hp->data[i] >= hp->data[max_i]) break;
        int t = hp->data[i];
        hp->data[i] = hp->data[max_i];
        hp->data[max_i] = t;
        i = max_i;
    }
    return top;
}

int minimumDeviation(int* nums, int numsSize) {
    MaxHeap hp = { .size = 0 };
    int min_val = 1e9;

    for (int i = 0; i < numsSize; i++) {
        int val = (nums[i] % 2 != 0) ? nums[i] * 2 : nums[i];
        push(&hp, val);
        if (val < min_val) min_val = val;
    }

    int min_dev = 1e9;
    while (1) {
        int max_val = pop(&hp);
        if (max_val - min_val < min_dev) min_dev = max_val - min_val;

        if (max_val % 2 == 0) {
            max_val /= 2;
            if (max_val < min_val) min_val = max_val;
            push(&hp, max_val);
        } else {
            break; // Max element is odd, cannot reduce further
        }
    }
    return min_dev;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = 4;
    printf("Minimum Deviation: %d\n", minimumDeviation(nums, n));
    return 0;
}