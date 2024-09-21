#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int dist[MAX_VERTICES][MAX_VERTICES];
int V;

void floydWarshall() {
    int i, j, k;

    scanf("%d", &V);

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == 0 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
  
    floydWarshall();
    return 0;
}
