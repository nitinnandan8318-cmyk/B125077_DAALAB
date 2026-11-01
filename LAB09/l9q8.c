#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareStarts(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int compareEnds(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(Interval intervals[], int n) {
    int starts[n], ends[n];
    for (int i = 0; i < n; i++) {
        starts[i] = intervals[i].start;
        ends[i] = intervals[i].end;
    }

    qsort(starts, n, sizeof(int), compareEnds);
    qsort(ends, n, sizeof(int), compareEnds);

    int rooms = 0, end_ptr = 0;

    for (int i = 0; i < n; i++) {
        if (starts[i] < ends[end_ptr]) {
            rooms++;
        } else {
            end_ptr++;
        }
    }
    return rooms;
}

int main() {
    Interval intervals[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = 3;
    printf("Minimum Meeting Rooms Required: %d\n", minMeetingRooms(intervals, n));
    return 0;
}