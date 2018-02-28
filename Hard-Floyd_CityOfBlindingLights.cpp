#include <iostream>

using namespace std;

const int MAXN = 400;
const int INF = 1e9;
const int OFFSET = -1;

int n, m;
int D[MAXN][MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (i != j) D[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        x += OFFSET; y += OFFSET;
        D[x][y] = r;
//        D[y][x] = r;
    }

    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    if (i != k && D[i][k] < INF)
        for (int j = 0; j < n; j++)
        if (j != k && i != j && D[i][k] + D[k][j] < D[i][j]) {
            D[i][j] = D[i][k] + D[k][j];
        }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        x += OFFSET; y += OFFSET;
        if (D[x][y] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", D[x][y]);
        }
    }


    return 0;
}