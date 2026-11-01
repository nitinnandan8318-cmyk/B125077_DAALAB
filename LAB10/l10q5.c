#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

int parent[MAXN];

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

void union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void lexicographically_smallest_permutation(int A[], int n, int edges[][2], int num_edges) {
    for (int i = 0; i < n; i++) parent[i] = i;

    // Build connected components
    for (int i = 0; i < num_edges; i++) {
        union_sets(edges[i][0], edges[i][1]);
    }

    // Collect elements component-wise
    int ans[MAXN];
    int visited[MAXN] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int comp_indices[MAXN];
            int comp_vals[MAXN];
            int count = 0;

            int root_i = find_set(i);
            for (int j = i; j < n; j++) {
                if (find_set(j) == root_i) {
                    comp_indices[count] = j;
                    comp_vals[count] = A[j];
                    visited[j] = 1;
                    count++;
                }
            }

            // Sort indices and values
            qsort(comp_indices, count, sizeof(int), cmp);
            qsort(comp_vals, count, sizeof(int), cmp);

            // Reassign smallest values to smallest indices
            for (int k = 0; k < count; k++) {
                ans[comp_indices[k]] = comp_vals[k];
            }
        }
    }

    printf("Lexicographically Smallest Permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {4, 3, 2, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);

    // Pairwise swap edges (0-indexed indices)
    int edges[][2] = {{0, 1}, {1, 2}, {0, 3}};
    int num_edges = sizeof(edges) / sizeof(edges[0]);

    printf("Initial Array: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    lexicographically_smallest_permutation(A, n, edges, num_edges);
    return 0;
}