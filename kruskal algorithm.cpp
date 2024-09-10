#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Edge structure
struct Edge {
    int src, dest, weight;
};

// Graph structure
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Subset structure for union-find
struct Subset {
    int parent, rank;
};

// Create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

// Find and Union functions
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x), rootY = find(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank) subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank) subsets[rootY].parent = rootX;
    else { subsets[rootY].parent = rootX; subsets[rootX].rank++; }
}

// Sort edges by weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's MST algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V, e = 0, i = 0;
    struct Edge result[MAX]; 
    struct Subset subsets[MAX];

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1) {
        struct Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

// Main function
int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V, E);
    printf("Enter edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);

    KruskalMST(graph);
    free(graph->edges);
    free(graph);
    return 0;
}
