#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dist;
    int fuel;
} Station;

typedef struct {
    int heap[100];
    int size;
} MaxHeap;

void push(MaxHeap *hp, int val) {
    hp->heap[hp->size] = val;
    int i = hp->size++;
    while (i > 0 && hp->heap[(i - 1) / 2] < hp->heap[i]) {
        int tmp = hp->heap[(i - 1) / 2];
        hp->heap[(i - 1) / 2] = hp->heap[i];
        hp->heap[i] = tmp;
        i = (i - 1) / 2;
    }
}

int pop(MaxHeap *hp) {
    if (hp->size == 0) return -1;
    int top = hp->heap[0];
    hp->heap[0] = hp->heap[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, max_idx = left;
        if (right < hp->size && hp->heap[right] > hp->heap[left]) max_idx = right;
        if (hp->heap[i] >= hp->heap[max_idx]) break;
        int tmp = hp->heap[i];
        hp->heap[i] = hp->heap[max_idx];
        hp->heap[max_idx] = tmp;
        i = max_idx;
    }
    return top;
}

int minRefuelStops(int target, int startFuel, Station stations[], int n) {
    MaxHeap max_fuel = { .size = 0 };
    int curr_dist = startFuel;
    int stops = 0;
    int idx = 0;

    while (curr_dist < target) {
        while (idx < n && stations[idx].dist <= curr_dist) {
            push(&max_fuel, stations[idx].fuel);
            idx++;
        }
        if (max_fuel.size == 0) return -1; // Unreachable
        curr_dist += pop(&max_fuel);
        stops++;
    }
    return stops;
}

int main() {
    int target = 100, startFuel = 10;
    Station stations[] = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int n = 4;

    int ans = minRefuelStops(target, startFuel, stations, n);
    printf("Minimum Refueling Stops: %d\n", ans);
    return 0;
}