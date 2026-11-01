#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double v;
    double w;
    double lambda;
    double ratio;
} Item;

// Sort items by value density decay potential or base ratio v/w descending
int compare(const void *a, const void *b) {
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    double r1 = i1->ratio;
    double r2 = i2->ratio;
    if (r2 > r1) return 1;
    if (r2 < r1) return -1;
    return 0;
}

int main() {
    int n = 3;
    double W = 50.0;
    Item items[] = {
        {1, 60, 10, 0.1, 0},
        {2, 100, 20, 0.2, 0},
        {3, 120, 30, 0.15, 0}
    };

    for (int i = 0; i < n; i++) {
        items[i].ratio = items[i].v / items[i].w;
    }

    qsort(items, n, sizeof(Item), compare);

    double total_val = 0.0;
    double current_w = 0.0;
    double time_elapsed = 0.0;

    printf("Processing order:\n");
    for (int i = 0; i < n; i++) {
        if (current_w >= W) break;

        double take_w = (W - current_w < items[i].w) ? (W - current_w) : items[i].w;
        double fraction = take_w / items[i].w;
        
        double effective_density = (items[i].v / items[i].w) - (items[i].lambda * time_elapsed);
        if (effective_density < 0) effective_density = 0;

        double val_gained = take_w * effective_density;
        total_val += val_gained;

        current_w += take_w;
        time_elapsed += fraction; // Assuming unit consumption time per fraction

        printf("Item %d: Fraction = %.2f, Effective Density = %.2f, Gained = %.2f\n",
               items[i].id, fraction, effective_density, val_gained);
    }

    printf("Total Maximum Value: %.2f\n", total_val);
    return 0;
}