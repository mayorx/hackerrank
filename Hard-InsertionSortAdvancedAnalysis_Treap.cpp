/*
TLE on 3 cases
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN 100005

typedef struct node {
    node *left, *right;
    int count, priority, value, sum;
} node;

int a[MAXN];

int calcsum(node *root) {
    if (root == NULL) return 0;
    int lsum = root->left == NULL ? 0 : root->left->sum;
    int rsum = root->right == NULL ? 0 : root->right->sum;
    return lsum + rsum + root->count;
}

int findLE(node *root, int value) {
    if (root == NULL) return 0;
    if (root->value == value) {
        return calcsum(root->left) + root->count;
    } else if (value < root->value) {
        return findLE(root->left, value);
    } else {
        return calcsum(root->left) + root->count + findLE(root->right, value);
    }
}

node* insert(node *root, int value) {
    if (root == NULL) {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->count = 1;
        root->sum = 1;
        root->value = value;
        root->priority = rand();
        return root;
    }

    if (root->value == value) {
        root->count++;
        root->sum++;
    } else if (value < root->value) {
        root->left = insert(root->left, value);
        if (root->left->priority > root->priority) {
            node *lch = root->left;
            root->left = lch->right;
            lch->right = root;
            root = lch;
            root->right->sum = calcsum(root->right);
        }
        root->sum = calcsum(root);
    } else {
        root->right = insert(root->right, value);
        if (root->right->priority > root->priority) {
            node * rch = root->right;
            root->right = rch->left;
            rch->left = root;
            root = rch;
            root->left->sum = calcsum(root->left);
        }
        root->sum = calcsum(root);
    }
    return root;
}

void clean(node * root) {
    if (root == NULL) return;
    clean(root->left);
    clean(root->right);
    delete root;
}

void printtree(node *root) {
    if (root == NULL) return;
    printf("value: %d, count %d, sum %d\n", root->value, root->count, root->sum);
    if (root->left) {
        printf("%d leftchild: \n", root->value);
        printtree(root->left);
        printf("%d leftchildend: \n", root->value);
    }
    if (root->right) {
        printf("%d rightchild: \n", root->value);
        printtree(root->right);
        printf("%d rightchildend: \n", root->value);
    }
}

int main() {
    int tasknum;
    scanf("%d", &tasknum);
    while (tasknum--) {
        int n;
        scanf("%d", &n);
        node *root = NULL;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; i++) {
            int x = a[i];
            ans += i - findLE(root, x);
            root = insert(root, x);
        }
        clean(root);

        printf("%lld\n", ans);
    }
    return 0;
}