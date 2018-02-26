/*
100% cases
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

typedef struct rec {
    int value, ith;
} rec;

bool cmp(rec a, rec b) {
    return a.value < b.value;
}

void discrete(vector <int> &a) {
    vector <rec> help(a.size());
    for (int i = 0; i < a.size(); i++) {
        help[i].value = a[i];
        help[i].ith = i;
    }
    sort(help.begin(), help.end(), cmp);

    int cnt = 0;
    for (int i = 0; i < help.size(); i++) {
        if (i == 0 || help[i-1].value != help[i].value) cnt++;
        a[help[i].ith] = cnt;
    }
}

int calc(vector <int> &tree, int value, int n) {
    int sum = 0;
    while (value) {
        sum += tree[value];
        value = value - (value & ((value-1) ^ value));
    }
    return sum;
}

void add(vector <int> &tree, int value, int n) {
    while (value <= n) {
        tree[value] += 1;
        value = value + (value & ((value - 1) ^ value));
    }
}

int main() {
    int tasknum;
    scanf("%d", &tasknum);
    while (tasknum--) {
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        discrete(a);

        vector <int> tree(n+1, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i - calc(tree, a[i], n);
            add(tree, a[i], n);
        }
        printf("%lld\n", ans);
    }


    return 0;
}