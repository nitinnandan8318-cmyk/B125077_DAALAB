#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000

int parent[MAXV];
int rank_arr[MAXV];
long long comp_weight[MAXV];
int active[MAXV];
int v_weights[MAXV];

// Adjacency matrix for edge lookups
int adj[MAXV][MAXV];

void init(int V) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
        comp_weight[i] = v_weights[i];
        active[i] = 0;
    }
}

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

void union_sets(int i, int j, long long *max_w) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        if (rank_arr[root_i] < rank_arr[root_j]) {
            parent[root_i] = root_j;
            comp_weight[root_j] += comp_weight[root_i];
            if (comp_weight[root_j] > *max_w) *max_w = comp_weight[root_j];
        } else if (rank_arr[root_i] > rank_arr[root_j]) {
            parent[root_j] = root_i;
            comp_weight[root_i] += comp_weight[root_j];
            if (comp_weight[root_i] > *max_w) *max_w = comp_weight[root_i];
        } else {
            parent[root_j] = root_i;
            rank_arr[root_i]++;
            comp_weight[root_i] += comp_weight[root_j];
            if (comp_weight[root_i] > *max_w) *max_w = comp_weight[root_i];
        }
    }
}

int main() {
    int V = 5;
    int weights[] = {10, 20, 5, 15, 30};
    for (int i = 0; i < V; i++) v_weights[i] = weights[i];

    // Edges (0-1), (1-2), (2-3), (3-4)
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;

    int P[] = {2, 0, 4, 1, 3}; // Deletion order (0-based)
    long long ans[MAXV];

    init(V);
    long long current_max = 0;

    // Process in reverse order of deletion
    for (int step = V - 1; step >= 0; step--) {
        ans[step] = current_max;
        int u = P[step];
        active[u] = 1;

        if (v_weights[u] > current_max) {
            current_max = v_weights[u];
        }

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && active[v]) {
                union_sets(u, v, &current_max);
            }
        }
    }

    printf("Max component weight after each vertex deletion:\n");
    for (int i = 0; i < V; i++) {
        printf("After deleting vertex %d: Max Sum = %lld\n", P[i], ans[i]);
    }

    return 0;
}