#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findOverlap(const char *str1, const char *str2, char *merged) {
    int max_overlap = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(str1 + len1 - i, str2, i) == 0) {
            max_overlap = i;
        }
    }

    strcpy(merged, str1);
    strcat(merged, str2 + max_overlap);
    return max_overlap;
}

void greedySuperstring(char strings[][100], int n) {
    int active = n;
    while (active > 1) {
        int max_len = -1;
        int best_i = -1, best_j = -1;
        char best_merged[200] = "";

        for (int i = 0; i < n; i++) {
            if (strings[i][0] == '\0') continue;
            for (int j = 0; j < n; j++) {
                if (i == j || strings[j][0] == '\0') continue;

                char temp[200];
                int overlap = findOverlap(strings[i], strings[j], temp);
                if (overlap > max_len) {
                    max_len = overlap;
                    best_i = i;
                    best_j = j;
                    strcpy(best_merged, temp);
                }
            }
        }

        if (max_len == -1) break;

        strcpy(strings[best_i], best_merged);
        strings[best_j][0] = '\0';
        active--;
    }

    printf("Approximate Shortest Superstring:\n");
    for (int i = 0; i < n; i++) {
        if (strings[i][0] != '\0') {
            printf("%s\n", strings[i]);
        }
    }
}

int main() {
    char strings[4][100] = {"CATGC", "CTAAGT", "GCTA", "TTCA"};
    int n = 4;
    greedySuperstring(strings, n);
    return 0;
}