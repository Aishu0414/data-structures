#include <stdio.h>
#define MAX 100

void DFS(int graph[MAX][MAX], int vertex, int visited[MAX], int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i])
            DFS(graph, i, visited, n);
    }
}

int main() {
    int n, graph[MAX][MAX], visited[MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int startVertex;
    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex, visited, n);

    return 0;
}
