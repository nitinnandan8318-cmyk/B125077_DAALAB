#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000

int parent[MAXV];
int rank_arr[MAXV];
int parity[MAXV]; // parity[u] is path length parity to parent[u]

void init(int V) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
        parity[i] = 0;
    }
}

// Find with path compression updating relative parity to root
int find_set(int v, int *p_out) {
    if (v == parent[v]) {
        *p_out = 0;
        return v;
    }
    int p_parent;
    int root = find_set(parent[v], &p_parent);
    parity[v] ^= p_parent;
    parent[v] = root;
    *p_out = parity[v];
    return root;
}

int add_edge(int u, int v) {
    int parity_u, parity_v;
    int root_u = find_set(u, &parity_u);
    int root_v = find_set(v, &parity_v);

    if (root_u == root_v) {
        // Same component: check cycle parity
        if (parity_u == parity_v) {
            // Odd cycle detected!
            return 0;
        }
        return 1; // Even cycle, safe to add
    }

    // Union by rank
    if (rank_arr[root_u] < rank_arr[root_v]) {
        parent[root_u] = root_v;
        parity[root_u] = parity_u ^ parity_v ^ 1;
    } else {
        parent[root_v] = root_u;
        parity[root_v] = parity_u ^ parity_v ^ 1;
        if (rank_arr[root_u] == rank_arr[root_v])
            rank_arr[root_u]++;
    }
    return 1;
}

int main() {
    int V = 5;
    init(V);

    int edges[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};
    int E = sizeof(edges) / sizeof(edges[0]);

    printf("Processing edges online:\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (add_edge(u, v)) {
            printf("Edge (%d, %d) added successfully. Graph is bipartite.\n", u, v);
        } else {
            printf("Edge (%d, %d) VIOLATES bipartiteness (skipped).\n", u, v);
        }
    }
    return 0;
}