#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 20
#define INF INT_MAX

int n;
int dist[MAX_CITIES][MAX_CITIES];
int dp[1 << MAX_CITIES][MAX_CITIES];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos) {
    if (mask == ((1 << n) - 1)) {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    int city;
    for (city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {

    scanf("%d", &n);
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0);
    printf("%d\n", result);

    return 0;
}
