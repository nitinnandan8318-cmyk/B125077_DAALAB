#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10000

int parent[MAX_CELLS];
int rank_arr[MAX_CELLS];
int grid[MAX_CELLS];

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

int union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        if (rank_arr[root_i] < rank_arr[root_j]) {
            parent[root_i] = root_j;
        } else if (rank_arr[root_i] > rank_arr[root_j]) {
            parent[root_j] = root_i;
        } else {
            parent[root_j] = root_i;
            rank_arr[root_i]++;
        }
        return 1; // Merged successfully
    }
    return 0; // Already in same component
}

void num_islands_2(int R, int C, int positions[][2], int k) {
    int total_cells = R * C;
    for (int i = 0; i < total_cells; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
        grid[i] = 0;
    }

    int islands = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    printf("Island count after each landing operation:\n");
    for (int step = 0; step < k; step++) {
        int r = positions[step][0];
        int c = positions[step][1];
        int idx = r * C + c;

        if (grid[idx] == 1) {
            printf("Step %d: Cell (%d, %d) already land. Count = %d\n", step + 1, r, c, islands);
            continue;
        }

        grid[idx] = 1;
        islands++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                int n_idx = nr * C + nc;
                if (grid[n_idx] == 1) {
                    if (union_sets(idx, n_idx)) {
                        islands--;
                    }
                }
            }
        }
        printf("Step %d: Land added at (%d, %d) -> Islands = %d\n", step + 1, r, c, islands);
    }
}

int main() {
    int R = 3, C = 3;
    int positions[][2] = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {1, 1}};
    int k = sizeof(positions) / sizeof(positions[0]);

    num_islands_2(R, C, positions, k);
    return 0;
}