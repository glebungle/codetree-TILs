#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1000

typedef struct {
    int n; // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; // 인접 행렬
} GraphType;

// 방문한 정점을 체크할 배열
int visited[MAX_VERTICES];

// DFS 함수
void dfs_mat(GraphType *G, int v) {
    visited[v] = 1; // 현재 정점을 방문했다고 표시
    for (int i = 0; i < G->n; i++) { // 정점의 수만큼 반복
        if (G->adj_mat[v][i] && !visited[i]) { // 현재 정점과 연결되어 있고, 아직 방문하지 않은 정점이라면
            dfs_mat(G, i); // 해당 정점으로 DFS 재귀 호출
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // 정점의 개수와 간선의 개수 입력 받기
    
    // 그래프 초기화
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    g->n = n;
    memset(g->adj_mat, 0, sizeof(g->adj_mat)); // 인접 행렬 초기화
    memset(visited, 0, sizeof(visited)); // 방문 배열 초기화

    // 간선 정보 입력 받기
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g->adj_mat[a-1][b-1] = g->adj_mat[b-1][a-1] = 1; // 인덱스 조정
    }

    // DFS 수행
    dfs_mat(g, 0); // 1번 정점에서 시작하므로 인덱스 0으로 조정

    int count = 0; // 방문한 정점의 수
    for (int i = 1; i < n; i++) { // 1번 정점을 제외하고 카운트
        if (visited[i]) count++;
    }
    
    printf("%d\n", count); // 결과 출력

    free(g); // 동적 할당한 메모리 해제
    return 0;
}