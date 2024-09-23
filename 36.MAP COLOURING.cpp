#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int numNodes, numColors;

bool isSafe(int node, int c) {
    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoring(int node) {
    if (node == numNodes) {
        return true; 
    }

    for (int c = 1; c <= numColors; c++) {
        if (isSafe(node, c)) {
            color[node] = c;

            if (graphColoring(node + 1)) {
                return true; 
            }

            color[node] = 0; 
        }
    }

    return false; 
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    for (int i = 0; i < numNodes; i++) {
        color[i] = 0;
    }

    if (graphColoring(0)) {
        printf("Solution exists:\n");
        for (int i = 0; i < numNodes; i++) {
            printf("Node %d -> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
