#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXL 12
 
char (*dict)[MAXL + 1];
int N, L;
 
int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int find_word(const char *w) {
    char *p = bsearch(w, dict, N, MAXL + 1, cmp);
    if (p == NULL) return -1;
    return (int)((p - (char *)dict) / (MAXL + 1));
}
 
int bidirectional_bfs(char *A, char *B) {
    if (strcmp(A, B) == 0) return 0;
 
    int target = find_word(B);
    if (target == -1) return -1;
    int source = find_word(A);
 
    int *distF = malloc(N * sizeof(int));
    int *distB = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) distF[i] = distB[i] = -1;
 
    int *frontF = malloc(N * sizeof(int)), *frontB = malloc(N * sizeof(int));
    int *next   = malloc(N * sizeof(int));
    int sizeF = 1, sizeB = 1;
    frontF[0] = source; distF[source] = 0;
    frontB[0] = target; distB[target] = 0;
 
    int answer = -1;
    while (sizeF > 0 && sizeB > 0 && answer == -1) {
        int forward = (sizeF <= sizeB);
        int *front = forward ? frontF : frontB;
        int *mine  = forward ? distF  : distB;
        int *other = forward ? distB  : distF;
        int size   = forward ? sizeF  : sizeB;
        int nsize  = 0;
        int best   = -1;
 
        for (int i = 0; i < size; i++) {
            int u = front[i];
            char word[MAXL + 1];
            strcpy(word, dict[u]);
            for (int pos = 0; pos < L; pos++) {
                char original = word[pos];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    word[pos] = c;
                    int v = find_word(word);
                    if (v == -1) continue;
                    if (other[v] != -1){
                        int total = mine[u] + 1 + other[v];
                        if (best == -1 || total < best) best = total;
                    } else if (mine[v] == -1) {
                        mine[v] = mine[u] + 1;
                        next[nsize++] = v;
                    }
                }
                word[pos] = original;
            }
        }
        answer = best;
        if (forward) { memcpy(frontF, next, nsize * sizeof(int)); sizeF = nsize; }
        else         { memcpy(frontB, next, nsize * sizeof(int)); sizeB = nsize; }
    }
 
    free(distF); free(distB); free(frontF); free(frontB); free(next);
    return answer;
}
 
int main() {
    char A[MAXL + 1], B[MAXL + 1];
 
    printf("Enter number of dictionary words N: ");
    scanf("%d", &N);
    printf("Enter word length L: ");
    scanf("%d", &L);
 
    dict = malloc((N + 1) * (MAXL + 1));
    printf("Enter the dictionary words:\n");
    for (int i = 0; i < N; i++) scanf("%s", dict[i]);
 
    printf("Enter start word A: ");
    scanf("%s", A);
    printf("Enter target word B: ");
    scanf("%s", B);

    int inDict = 0;
    for (int i = 0; i < N; i++)
        if (strcmp(dict[i], A) == 0) { inDict = 1; break; }
    if (!inDict) strcpy(dict[N++], A);
 
    qsort(dict, N, MAXL + 1, cmp);
 
    int k = bidirectional_bfs(A, B);
    if (k == -1) printf("No valid transformation sequence exists (-1)\n");
    else         printf("Minimum number of mutations k = %d\n", k);
 
    free(dict);
    return 0;
}