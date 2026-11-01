#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    char start, end;
} edge;
 
typedef struct {
    char *V;
    edge *E;
    int Vsize, Esize;
} graph;

typedef struct {
    int *data;
    int front, back;
} queue;
 
queue create_queue(int size) {
    queue q;
    q.data = malloc(size * sizeof(int));
    q.front = q.back = 0;
    return q;
}
int  q_empty(queue *q){ return q->front == q->back; }
void enqueue(queue *q, int x){ q->data[q->back++] = x; }
int  dequeue(queue *q){ return q->data[q->front++]; }
void free_queue(queue *q){ free(q->data); }

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
 
void voronoi_bfs(graph G, char *hubs, int K, int R) {
    int n = G.Vsize, m = G.Esize;

    int *head = malloc(n * sizeof(int));
    int *nxt  = malloc(2 * m * sizeof(int));
    int *to   = malloc(2 * m * sizeof(int));
    for (int i = 0; i < n; i++) head[i] = -1;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u = idx(G, G.E[i].start), v = idx(G, G.E[i].end);
        to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
        to[cnt] = u; nxt[cnt] = head[v]; head[v] = cnt++;
    }
 
    int *owner = malloc(n * sizeof(int));
    int *dist  = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) owner[i] = dist[i] = -1;
 
    queue q = create_queue(n);

    for (int i = 0; i < K; i++) {
        int h = idx(G, hubs[i]);
        if (h != -1 && owner[h] == -1) {
            owner[h] = i + 1;
            dist[h] = 0;
            enqueue(&q, h);
        }
    }
 
    while (!q_empty(&q)) {
        int u = dequeue(&q);
        if (dist[u] == R) continue;
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (owner[v] == -1){
                owner[v] = owner[u];
                dist[v] = dist[u] + 1;
                enqueue(&q, v);
            }
        }
    }
 
    printf("\nVertex  Owner  Distance\n");
    for (int v = 0; v < n; v++)
        printf("%c       %d      %d\n", G.V[v], owner[v], dist[v]);
 
    free(head); free(nxt); free(to);
    free(owner); free(dist); free_queue(&q);
}
 
int main() {
    int K, R;
    graph G;
 
    G = input_graph();
 
    printf("Enter number of hubs K: ");
    scanf("%d", &K);
    char *hubs = malloc(K * sizeof(char));
    printf("Enter the hub vertices in order h1..hK:\n");
    for (int i = 0; i < K; i++) scanf(" %c", &hubs[i]);
    printf("Enter radius R: ");
    scanf("%d", &R);
 
    voronoi_bfs(G, hubs, K, R);
 
    free(hubs);
    free_graph(&G);
    return 0;
}