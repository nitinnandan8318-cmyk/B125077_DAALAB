#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

int getMaxChar(CharFreq counts[], int last_pos[], int curr_pos, int K) {
    int max_idx = -1;
    int max_freq = 0;

    for (int i = 0; i < 256; i++) {
        if (counts[i].freq > 0) {
            if (last_pos[i] == -1 || curr_pos - last_pos[i] >= K) {
                if (counts[i].freq > max_freq) {
                    max_freq = counts[i].freq;
                    max_idx = i;
                }
            }
        }
    }
    return max_idx;
}

void rearrangeString(char *s, int K) {
    int n = strlen(s);
    CharFreq counts[256] = {0};
    int last_pos[256];

    for (int i = 0; i < 256; i++) {
        counts[i].ch = (char)i;
        last_pos[i] = -1;
    }
    for (int i = 0; i < n; i++) counts[(unsigned char)s[i]].freq++;

    char *result = (char *)malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        int idx = getMaxChar(counts, last_pos, i, K);
        if (idx == -1) {
            printf("Cannot rearrange string with K-distance apart: \"\"\n");
            free(result);
            return;
        }
        result[i] = (char)idx;
        counts[idx].freq--;
        last_pos[idx] = i;
    }
    result[n] = '\0';
    printf("Reorganized String: %s\n", result);
    free(result);
}

int main() {
    char s[] = "aabbcc";
    int K = 3;
    rearrangeString(s, K);
    return 0;
}