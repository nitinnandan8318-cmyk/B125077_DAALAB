#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000

int parent[MAXV];
int rank_arr[MAXV];
int comp_size[MAXV];
long long comp_weight[MAXV];
int weight[MAXV];

void init(int V) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
        comp_size[i] = 1;
        comp_weight[i] = weight[i];
    }
}

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

void add_edge(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        if (rank_arr[root_u] < rank_arr[root_v]) {
            parent[root_u] = root_v;
            comp_size[root_v] += comp_size[root_u];
            comp_weight[root_v] += comp_weight[root_u];
        } else if (rank_arr[root_u] > rank_arr[root_v]) {
            parent[root_v] = root_u;
            comp_size[root_u] += comp_size[root_v];
            comp_weight[root_u] += comp_weight[root_v];
        } else {
            parent[root_v] = root_u;
            rank_arr[root_u]++;
            comp_size[root_u] += comp_size[root_v];
            comp_weight[root_u] += comp_weight[root_v];
        }
    }
}

long long get_max_weight(int V, int K) {
    long long max_w = -1;
    for (int i = 0; i < V; i++) {
        if (parent[i] == i) { // Component root
            if (comp_size[i] <= K) {
                if (comp_weight[i] > max_w) {
                    max_w = comp_weight[i];
                }
            }
        }
    }
    return max_w;
}

int main() {
    int V = 5, K = 2;
    int v_weights[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < V; i++) weight[i] = v_weights[i];

    init(V);

    int edges[][2] = {{0, 1}, {1, 2}, {3, 4}};
    int E = sizeof(edges) / sizeof(edges[0]);

    printf("Initial Max Weight (Size <= %d): %lld\n", K, get_max_weight(V, K));

    for (int i = 0; i < E; i++) {
        add_edge(edges[i][0], edges[i][1]);
        printf("After edge (%d, %d) -> Max Weight (Size <= %d): %lld\n",
               edges[i][0], edges[i][1], K, get_max_weight(V, K));
    }
    return 0;
}