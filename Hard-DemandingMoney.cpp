#include <iostream>

using namespace std;

#define MAXN 34
#define OFFSET -1
#define LIMIT 14
#define INF 1000000

int G[1 << LIMIT];
int Gopt[1 << LIMIT];

int H[1 << LIMIT];

int n, m;
long long connected[MAXN];
int money[MAXN];

//calculate H
void dfsH(int depth, int maxdepth, long long choosed, long long conflicted, int total) {
    if (depth == maxdepth) {
        H[choosed] = total;
        return;
    }
    //1. choose depth
    if (!((1 << depth) & conflicted)) {
        dfsH(depth + 1, maxdepth, choosed | (1 << depth), conflicted | connected[depth], total + money[depth]);
    }

    //2. skip depth
    dfsH(depth + 1, maxdepth, choosed, conflicted, total);
}

void dfsG(int depth, int maxdepth, long long choosed, long long s) {
    if (depth == maxdepth) {
        if (H[choosed] > G[s]) {
            G[s] = H[choosed]; Gopt[s] = 1;
        } else if (H[choosed] == G[s]) {
            Gopt[s]++;
        }
        return;
    }

    if (H[choosed] == -INF) return;
    if (choosed > s) return;

    if ((1 << depth) & s)
        dfsG(depth + 1, maxdepth, choosed | (1 << depth), s);
    dfsG(depth + 1, maxdepth, choosed, s);
}

void dfsWithLimit(int depth, int maxdepth, long long choosed, long long conflicted, int total, int limit, int &best, long long &bestcnt) {
    if (depth == maxdepth) {
        long long preset = (((long long)1 << limit) - 1) & (~conflicted);
        if (total + G[preset] > best) {
            best = total + G[preset];
            bestcnt = Gopt[preset];
        } else if (total + G[preset] == best) {
            bestcnt += Gopt[preset];
        }
        return;
    }
    if (!(((long long)1 << depth) & conflicted)) {
        dfsWithLimit(
            depth + 1,
            maxdepth,
            choosed | ((long long)1 << depth),
            conflicted | connected[depth],
            total + money[depth],
            limit,
            best,
            bestcnt
        );
    }
    dfsWithLimit(depth + 1, maxdepth, choosed, conflicted, total, limit, best, bestcnt);
}

void init(int n) {
    for (int i = 0; i < 1 << n; i++) H[i] = -INF;
    dfsH(0, n, 0, 0, 0);

    for (int s = 0; s < 1 << n; s++) {
        G[s] = -INF;
        dfsG(0, n, 0, s);
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> money[i];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x += OFFSET; y += OFFSET;
        connected[x] |= (long long)1 << y;
        connected[y] |= (long long)1 << x;
    }

    //calculate H, F
    init(min(n, LIMIT));
    int best = -INF;
    long long bestcnt = 0;
    dfsWithLimit(min(n, LIMIT), n, 0, 0, 0, min(n, LIMIT), best, bestcnt);
    cout << best << " " << bestcnt << endl;
    return 0;
}