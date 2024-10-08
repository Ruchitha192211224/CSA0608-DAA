#include <stdio.h>
#include <limits.h>

#define MAX 100

int n;
float p[MAX], q[MAX], e[MAX][MAX], w[MAX][MAX], root[MAX][MAX];

void optimalBST(float p[], float q[], int n) {
	int i,l;
    for (i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for (l = 1; l <= n; l++) {
    	int i,r;
        for (i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (r = i; r <= j; r++) {
                float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}

void printOBST(int i, int j, int r) {
    if (i == j) {
        printf("d%d is the left child of k%d\n", j, r);
        return;
    }
    int k = root[i][j];
    if (k == root[1][n]) {
        printf("k%d is the root\n", k);
    } else if (j < k) {
        printf("k%d is the left child of k%d\n", k, r);
    } else {
        printf("k%d is the right child of k%d\n", k, r);
    }
    printOBST(i, k - 1, k);
    printOBST(k + 1, j, k);
}

int main() {

    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter probabilities for keys: ");
    int i;
    for (i = 1; i <= n; i++) {
        scanf("%f", &p[i]);
    }
    printf("Enter probabilities for dummy keys: ");
    for (i = 0; i <= n; i++) {
        scanf("%f", &q[i]);
    }
    optimalBST(p, q, n);
    printOBST(1, n, root[1][n]);
    return 0;
}
