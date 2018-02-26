#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 3000;
const int INF = 300000005;
const int OFFSET = -1;

int dis[MAXN][MAXN];

int main() {
    int tasknums;
    scanf("%d", &tasknums);
    while (tasknums--) {
        int n, m, s;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dis[i][j] = 0;
                } else {
                    dis[i][j] = INF;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            x += OFFSET; y += OFFSET;
            if (dis[x][y] > z) {
                dis[x][y] = z;
                dis[y][x] = z;
            }
        }

        scanf("%d", &s);
        s += OFFSET;

        vector <int> shortest(n);
        vector <int> finished(n, 0);
        for (int i = 0; i < n; i++)
            shortest[i] = i == s ? 0 : INF;

        for (int k = 0; k < n; k++) {
            int j, best = INF;
            for (int i = 0; i < n; i++)
                if (!finished[i] && shortest[i] < best) {
                    best = shortest[i];
                    j = i;
                }
            finished[j] = 1;
            for (int i = 0; i < n; i++)
                if (!finished[i] && shortest[j] + dis[j][i] < shortest[i])
                    shortest[i] = shortest[j] + dis[j][i];
        }
        bool first = true;
        for (int i = 0; i < n; i++)
        if (i != s) {
            if (first) {
                first = false;
            } else {
                printf(" ");
            }

            printf("%d", shortest[i] >= INF ? -1 : shortest[i]);
        }
        printf("\n");
    }
    return 0;
}