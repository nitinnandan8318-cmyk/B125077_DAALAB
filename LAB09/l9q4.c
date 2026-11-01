#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[100];
    int size;
} MinHeap;

void insert(MinHeap *hp, int val) {
    hp->data[hp->size] = val;
    int i = hp->size++;
    while (i > 0 && hp->data[(i - 1) / 2] > hp->data[i]) {
        int t = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = hp->data[i];
        hp->data[i] = t;
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap *hp) {
    int top = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, min_i = left;
        if (right < hp->size && hp->data[right] < hp->data[left]) min_i = right;
        if (hp->data[i] <= hp->data[min_i]) break;
        int t = hp->data[i];
        hp->data[i] = hp->data[min_i];
        hp->data[min_i] = t;
        i = min_i;
    }
    return top;
}

int connectSticks(int sticks[], int n) {
    MinHeap hp = { .size = 0 };
    for (int i = 0; i < n; i++) insert(&hp, sticks[i]);

    int total_cost = 0;
    while (hp.size > 1) {
        int first = extractMin(&hp);
        int second = extractMin(&hp);
        int cost = first + second;
        total_cost += cost;
        insert(&hp, cost);
    }
    return total_cost;
}

int main() {
    int sticks[] = {2, 4, 3};
    int n = 3;
    printf("Minimum Cost to Connect Sticks: %d\n", connectSticks(sticks, n));
    return 0;
}