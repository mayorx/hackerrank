#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define OFFSET -1
#define MAXM 200005


typedef struct rec {
    int x, y;
} rec;

typedef struct pack {
    int groupnum, edgenum;
} pack;

bool myfunc(pack a, pack b) {
    return a.groupnum > b.groupnum;
}

int f[MAXN], g[MAXN];
rec edge[MAXM];

int group(int x) {
    if (x != f[x]) {
        f[x] = group(f[x]);
    }
    return f[x];
}

int main() {
    int tasknum;
    cin >> tasknum;
    while (tasknum--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            f[i] = i;
            g[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x += OFFSET; y += OFFSET;
            edge[i].x = x; edge[i].y = y;
            if (group(x) != group(y)) {
                g[group(x)] += g[group(y)];
                f[group(y)] = group(x);
            }
        }
        vector <int> cnt(n, 0);
        for (int i = 0; i < m; i++) {
            int x = edge[i].x;
            int y = edge[i].y;
            int z = group(x);
            cnt[z]++;
        }

        vector <pack> groups;
        for (int i = 0; i < n; i++)
        if (cnt[i] > 0) {
            pack p;
            p.groupnum = g[i];
            p.edgenum = cnt[i];
            groups.push_back(p);
        }
        sort(groups.begin(), groups.end(), myfunc);

        long long ans = 0, sum = 0, edges = 0;
        for (int i = 0; i < groups.size(); i++) {
            for (int j = 2; j <= groups[i].groupnum; j++) {
                ans += sum + (long long) j * (j - 1);
            }
            sum += (long long)groups[i].groupnum * (groups[i].groupnum - 1);
            edges += groups[i].edgenum - groups[i].groupnum + 1;
        }
        ans += edges * sum;
        cout << ans << endl;
    }
    return 0;
}