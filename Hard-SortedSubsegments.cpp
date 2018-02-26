/*
hint from editorial
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define RANGE 1000000000
#define ROOT 1
//#define STEPS 10000000

typedef struct query {
    int l, r;
} query;

typedef struct seg {
    int l, r, count;
    bool filled;
    int filled_value;
} seg;

void init(vector <seg> &tree, int root, int l, int r, vector <int> &values, int x) {
    tree[root].l = l;
    tree[root].r = r;
    tree[root].filled = false;
    if (l == r) {
        tree[root].count = values[l] >= x;
    } else {
        int m = (l + r) / 2;
        init(tree, root * 2, l, m, values, x);
        init(tree, root * 2 + 1, m + 1, r, values, x);
        tree[root].count = tree[root * 2].count + tree[root * 2 + 1].count;
    }
}

void fill(vector <seg> &tree, int root, int value) {
//    static int counter = 0;
//    counter++;
//    if (counter % STEPS == 0) printf("function fill counter: %d\n", counter / STEPS);

    tree[root].count = value * (tree[root].r - tree[root].l + 1);
    tree[root].filled_value = value;
    tree[root].filled = true;
}

void pass(vector <seg> &tree, int root) {
//    static int counter = 0;
//    counter++;
//    if (counter % STEPS == 0) printf("function pass counter: %d\n", counter / STEPS);

    fill(tree, root * 2, tree[root].filled_value);
    fill(tree, root * 2 + 1, tree[root].filled_value);
    tree[root].filled = false;
}

int calc(vector <seg> &tree, int root, int l, int r) {
//    static int counter = 0;
//    counter++;
//    if (counter % STEPS == 0) printf("function calc counter: %d\n", counter / STEPS);

    if (l <= tree[root].l && tree[root].r <= r) return tree[root].count;
    if (r < tree[root].l || tree[root].r < l) return 0;
    if (tree[root].filled) {
        return tree[root].filled_value * (min(r, tree[root].r) - max(l, tree[root].l) + 1);
    } else {
        return calc(tree, root * 2, l, r) + calc(tree, root * 2 + 1, l, r);
    }
}

void set(vector <seg> &tree, int root, int l, int r, int value) {
//    static int counter = 0;
//    counter++;
//    if (counter % STEPS == 0) printf("function set counter: %d\n", counter / STEPS);

    if (l <= tree[root].l && tree[root].r <= r) {
        fill(tree, root, value);
        return;
    }
    if (r < tree[root].l || tree[root].r < l) return;
    if (tree[root].filled) {
        if (tree[root].filled_value == value) return;
        pass(tree, root);
    }
    set(tree, root * 2, l, r, value);
    set(tree, root * 2 + 1, l, r, value);
    tree[root].count = tree[root * 2].count + tree[root * 2 + 1].count;
    for (int filled_value = 0; filled_value < 2; filled_value ++) {
        if (tree[root].count == filled_value * (tree[root].r - tree[root].l + 1)) {
            tree[root].filled_value = filled_value;
            tree[root].filled = true;
            break;
        }
    }
    return;
}

/**
    sorted values[k] >= x
*/
int work(vector <int> &values, vector <query> &querys, int x, int k) {
    int n = values.size();
    vector <seg> tree(4 * n);
    //initialize segment tree
    init(tree, ROOT, 0, n-1, values, x);
    for (vector <query>::iterator it = querys.begin(); it != querys.end(); it++) {
//        printf("query l:%d, r:%d\n", it->l, it->r);
        int total = calc(tree, ROOT, it->l, it->r);
        set(tree, ROOT, it->l, (it->r) - total, 0);
        set(tree, ROOT, (it->r) - total + 1, it->r, 1);
    }
    return calc(tree, ROOT, k, k);
}

int main() {
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);
    vector <int> values(n);
    for (int i = 0; i < n; i++) scanf("%d", &values[i]);
    vector <query> querys(q);

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &querys[i].l, &querys[i].r);
    }

    int L = -RANGE, R = RANGE;
    while (L < R) {
        int Mid = (L + R + 1) / 2;
        if (work(values, querys, Mid, k)) {
            L = Mid;
        } else {
            R = Mid - 1;
        }
    }
    printf("%d\n", L);
    return 0;
}