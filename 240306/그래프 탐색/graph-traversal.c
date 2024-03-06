#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1000

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES]; 

void dfs_mat(GraphType *G, int v) {
    visited[v] = 1;
    for (int i = 1; i <= G->n; i++) { 
        if (G->adj_mat[v][i] && !visited[i]) { 
            dfs_mat(G, i);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    g->n = n;
    memset(g->adj_mat, 0, sizeof(g->adj_mat)); 
    memset(visited, 0, sizeof(visited)); 

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g->adj_mat[a][b] = g->adj_mat[b][a] = 1;
    }

    dfs_mat(g, 1);

    int count = 0;
    for (int i = 2; i <= n; i++) { 
        if (visited[i]) {
            count++;
        }
    }

    printf("%d\n", count); 

    free(g); 

    return 0;
}