#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define MAXN 100005
#define ROOT 1
#define DEBUG 0

typedef struct node {
    int l, r, count;
} node;

void discrete(vector <int> &a) {
    map <int, int> m;
    for (int i = 0; i < a.size(); i++) m[a[i]] = 1;
    int cnt = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cnt++;
        it->second = cnt;
    }
    for (int i = 0; i < a.size(); i++) a[i] = m[a[i]];
}

void init(vector <node> &tree, int root, int l, int r) {
    tree[root].l = l; tree[root].r = r; tree[root].count = 0;
    if (root > 4 * MAXN && DEBUG) printf("wtf %d\n", root);
    if (tree[root].l == tree[root].r) return;
    int m = (l + r) / 2;
    init(tree, root * 2, l, m);
    init(tree, root * 2 + 1, m + 1, r);
}

int findle(vector <node> &tree, int root, int value) {
    if (tree[root].l == tree[root].r) return tree[root].count;
    int m = (tree[root].l + tree[root].r) / 2;
    if (value <= m) return findle(tree, root * 2, value);
    return tree[root * 2].count + findle(tree, root * 2 + 1, value);
}

void add(vector <node> &tree, int root, int value) {
    tree[root].count ++;
    if (tree[root].l == tree[root].r) return;
    int m = (tree[root].l + tree[root].r) / 2;
    if (value <= m) {
        add(tree, root * 2, value);
    } else {
        add(tree, root * 2 + 1, value);
    }
}

long long calc(vector <int> &a, vector <node> &tree) {
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int kth = findle(tree, ROOT, a[i]);
        ans += i - kth;
        add(tree, ROOT, a[i]);
    }
    return ans;
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

        if (DEBUG) {
            printf("discrete result:");
            for (int i = 0; i < n; i++) printf(" %d", a[i]);
            printf("\n");
        }

        vector <node> tree(n * 4);
        init(tree, ROOT, 1, n);
        printf("%lld\n", calc(a, tree));
    }


    return 0;
}