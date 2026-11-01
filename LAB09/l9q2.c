#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char symbol;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    char symbol;
    int len;
    char code[100];
} Code;

Node* createNode(char symbol, int freq) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->symbol = symbol;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

void getLengths(Node* root, int depth, int lengths[]) {
    if (!root) return;
    if (!root->left && !root->right) {
        lengths[(unsigned char)root->symbol] = depth;
        return;
    }
    getLengths(root->left, depth + 1, lengths);
    getLengths(root->right, depth + 1, lengths);
}

int compareCodes(const void* a, const void* b) {
    Code* c1 = (Code*)a;
    Code* c2 = (Code*)b;
    if (c1->len != c2->len) return c1->len - c2->len;
    return c1->symbol - c2->symbol;
}

int main() {
    char symbols[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freqs[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    Node* nodes[100];
    for (int i = 0; i < n; i++) nodes[i] = createNode(symbols[i], freqs[i]);
    int size = n;

    while (size > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[min1]->freq > nodes[min2]->freq) { min1 = 1; min2 = 0; }
        for (int i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1; min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }
        Node* parent = createNode('\0', nodes[min1]->freq + nodes[min2]->freq);
        parent->left = nodes[min1];
        parent->right = nodes[min2];

        nodes[min1] = parent;
        nodes[min2] = nodes[size - 1];
        size--;
    }

    int lengths[256] = {0};
    getLengths(nodes[0], 0, lengths);

    Code codebook[6];
    for (int i = 0; i < n; i++) {
        codebook[i].symbol = symbols[i];
        codebook[i].len = lengths[(unsigned char)symbols[i]];
    }

    qsort(codebook, n, sizeof(Code), compareCodes);

    // Generate Canonical Codes
    int code_val = 0;
    int current_len = codebook[0].len;

    for (int i = 0; i < n; i++) {
        code_val <<= (codebook[i].len - current_len);
        current_len = codebook[i].len;

        for (int b = current_len - 1; b >= 0; b--) {
            codebook[i].code[current_len - 1 - b] = ((code_val >> b) & 1) ? '1' : '0';
        }
        codebook[i].code[current_len] = '\0';
        code_val++;
    }

    printf("Canonical Huffman Codes:\n");
    for (int i = 0; i < n; i++) {
        printf("Symbol: %c | Length: %d | Code: %s\n", codebook[i].symbol, codebook[i].len, codebook[i].code);
    }

    return 0;
}