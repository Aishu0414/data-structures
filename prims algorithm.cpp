#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int n) {
    int min = INF, minIndex;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[MAX][MAX], int n) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim's Algorithm
void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX], key[MAX], mstSet[MAX] = {0};

    // Initialize all keys as infinite and set the first key as 0
    for (int i = 0; i < n; i++) key[i] = INF;
    key[0] = 0;
    parent[0] = -1;

    // Construct the MST
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

// Main function
int main() {
    int n, graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no direct edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}
