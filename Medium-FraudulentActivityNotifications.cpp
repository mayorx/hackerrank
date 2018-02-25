#include <cstdio>

using namespace std;

#define MAXN 200005
#define MAXRANGE 200

int expend[MAXN];

typedef struct node {
    int left, right, cnt;
} node;

node tree[MAXRANGE * 4];

void init_tree(int root, int left, int right) {
    tree[root].cnt = 0;
    tree[root].left = left;
    tree[root].right = right;
    if (left == right) return;
    int medium = (left + right) / 2;
    init_tree(root * 2, left, medium);
    init_tree(root * 2 + 1, medium + 1, right);
}

void add(int root, int value) {
    tree[root].cnt += 1;
    if (tree[root].left == tree[root].right) return;
    int medium = (tree[root].left + tree[root].right) / 2;

    if (value <= medium) {
        add(root * 2, value);
    } else {
        add(root * 2 + 1, value);
    }
}

void del(int root, int value) {
    tree[root].cnt -= 1;
    if (tree[root].left == tree[root].right) return;
    int medium = (tree[root].left + tree[root].right) / 2;

    if (value <= medium) {
        del(root * 2, value);
    } else {
        del(root * 2 + 1, value);
    }
}

int find(int root, int kth) {
    if (tree[root].left == tree[root].right) return tree[root].left;
    if (tree[2 * root].cnt >= kth) return find(root * 2, kth);
    return find(root * 2 + 1, kth - tree[2 * root].cnt);
}

int main() {
    int n, d, root = 1;
    scanf("%d %d", &n, &d);

    for (int i = 0; i < n; i++) {
        scanf("%d", &expend[i]);
    }

    init_tree(root, 0 , MAXRANGE);
    for (int i = 0; i < d; i++) add(root, expend[i]);


    int ans = 0;
    for (int i = d; i < n; i++) {
        if (expend[i] >= find(root, (d+1) / 2) + find(root, (d + 2)/2)) ans++;
//        printf("i: %d expend[i] : %d, d: %d, find result: %d\n", i, expend[i], d , find(root, (d+1) / 2));
        del(root, expend[i - d]);
        add(root, expend[i]);
    }
    printf("%d\n", ans);

    return 0;
}