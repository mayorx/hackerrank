#include <iostream>

using namespace std;

const int MAXN = 10;
const int region = 1;
const int directions = 8;
const int dx[directions] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[directions] = {-1, 0, 1, -1, 1, -1, 0, 1};

int grid[MAXN][MAXN];
int visited[MAXN][MAXN];

int visit(int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (visited[x][y] || grid[x][y] != region) return 0;
    visited[x][y] = 1;
    int cnt = 1;
    for (int opt = 0; opt < directions; opt++) {
        cnt += visit(dx[opt] + x, dy[opt] + y, n, m);
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        ans = max(ans, visit(i, j, n, m));
    printf("%d\n", ans);
    return 0;
}