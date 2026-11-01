#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
typedef struct {
    char start, end;
    int weight;
} edge;
 
typedef struct {
    char *V;
    edge *E;
    int Vsize, Esize;
} graph;

typedef struct {
    int *data;
    int front, back;
} deque;
 
deque create_queue(int max_pushes) {
    deque q;
    q.data = malloc((2 * max_pushes + 2) * sizeof(int));
    q.front = q.back = max_pushes + 1;
    return q;
}
int  dq_empty(deque *q)           { return q->front == q->back; }
void push_front(deque *q, int x)  { q->data[--q->front] = x; }
void push_back(deque *q, int x)   { q->data[q->back++] = x; }
int  pop_front(deque *q)          { return q->data[q->front++]; }
void free_queue(deque *q)         { free(q->data); }

graph input_graph() {
    graph g;

    printf("Enter number of vertices: ");
    scanf("%d", &g.Vsize);
    printf("Enter number of edges: ");
    scanf("%d", &g.Esize);
 
    g.V = malloc(g.Vsize * sizeof(char));
    g.E = malloc(g.Esize * sizeof(edge));
 
    printf("Enter V array:\n");
    for (int i = 0; i < g.Vsize; i++) {
        scanf(" %c", &g.V[i]);
    }
 
    printf("Enter E array:\n");
    for (int i = 0; i < g.Esize; i++) {
        printf("start vertex: ");
        scanf(" %c", &g.E[i].start);
        printf("end vertex: ");
        scanf(" %c", &g.E[i].end);
    }
 
    printf("Enter the weights (0 or 1):\n");
    for (int i = 0; i < g.Esize; i++) {
        printf("%c%c: ", g.E[i].start, g.E[i].end);
        scanf("%d", &g.E[i].weight);
    }
    return g;
}
 
void free_graph(graph *g) {
    free(g->V);
    free(g->E);
}

int idx(graph G, char c) {
    for (int i = 0; i < G.Vsize; i++)
        if (G.V[i] == c) return i;
    return -1;
}

int *parity_01bfs(graph G, char S, int C) {
    int n = G.Vsize, m = G.Esize;
    int src = idx(G, S);
    if (src == -1) return NULL;

    int *head = malloc(n * sizeof(int));
    int *nxt  = malloc(m * sizeof(int));
    int *to   = malloc(m * sizeof(int));
    for (int i = 0; i < n; i++) head[i] = -1;
    for (int i = 0; i < m; i++) {
        int u = idx(G, G.E[i].start), v = idx(G, G.E[i].end);
        to[i] = v;
        nxt[i] = head[u];
        head[u] = i;
    }

    int *d    = malloc(2 * n * sizeof(int));
    char *done = calloc(2 * n, 1);
    for (int i = 0; i < 2 * n; i++) d[i] = INT_MAX;
 
    deque q = create_queue(2 * m + 2);
    d[src * 2] = 0;
    push_back(&q, src * 2);
 
    while (!dq_empty(&q)) {
        int s = pop_front(&q);
        if (done[s]) continue;
        done[s] = 1;
        int u = s / 2, p = s % 2;
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int w = G.E[e].weight;
            int t = to[e] * 2 + (p ^ w);
            if (d[s] + w < d[t]) {
                d[t] = d[s] + w;
                if (w == 0) push_front(&q, t);
                else        push_back(&q, t);
            }
        }
    }
 
    int *ans = malloc(n * sizeof(int));
    for (int v = 0; v < n; v++) {
        long long even = d[2 * v];
        long long odd  = (d[2 * v + 1] == INT_MAX) ? INT_MAX : (long long)d[2 * v + 1] + C;
        long long best = even < odd ? even : odd;
        ans[v] = (best >= INT_MAX) ? INT_MAX : (int)best;
    }
 
    free(head); free(nxt); free(to); free(d); free(done); free_queue(&q);
    return ans;
}
 
int main() {
    int C;
    char S;
    graph G;
 
    G = input_graph();
 
    printf("Enter the source node: ");
    scanf(" %c", &S);
    printf("Enter the penalty cost C: ");
    scanf("%d", &C);
 
    int *ans = parity_01bfs(G, S, C);
    if (ans == NULL) {
        printf("Source vertex not found in V.\n");
        free_graph(&G);
        return 1;
    }
 
    printf("\nMinimum cost from %c:\n", S);
    for (int v = 0; v < G.Vsize; v++) {
        if (ans[v] == INT_MAX) printf("%c: unreachable\n", G.V[v]);
        else printf("%c: %d\n", G.V[v], ans[v]);
    }
 
    free(ans);
    free_graph(&G);
    return 0;
}