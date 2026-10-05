#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int year;
    int type;       
} Event;
int compare(const void *a,const void *b) {
    Event *x = (Event *)a;
    Event *y = (Event *)b;
    if (x->year != y->year)
        return x->year - y->year;
    return x->type - y->type;
}
int best_time(Event events[], int n, int *best_year) {
    int current = 0;
    int maximum = 0;
    for (int i=0;i<2*n;i++) {
        current += events[i].type;
        if (current > maximum) {
            maximum = current;
            *best_year = events[i].year;
        }
    }
    return maximum;
}
int main() {
    int n;
    printf("Enter number of scientists: ");
    scanf("%d",&n);
    Event *events = malloc((2*n) *sizeof(Event));
    printf("Enter all scientists birth and death year:\n");
    for (int i=0;i<n;i++){
        int birth,death;
        printf("\nenter birth year : ");
        scanf("%d",&birth);
        printf("enter death year : ");
        scanf("%d",&death);
        events[2*i].year = birth;
        events[2*i].type = 1;
        events[2*i+1].year = death;
        events[2*i+1].type = -1;
    }
    qsort(events,(2*n),sizeof(Event),compare);
    int best_year;
    int maximum = best_time(events, n, &best_year);
    printf("Time when largest number of scientists were alive: %d\n",best_year);
    printf("Largest number of scientists alive: %d\n", maximum);
    free(events);
    return 0;
}