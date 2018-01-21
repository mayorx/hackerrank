#include <iostream>

using namespace std;

#define inf 10000

int sgn(int x) {
    if (x == 0) return 0;
    return x < 0 ? -1 : 1;
}

int available(int position, int n, int direction) {
    switch (direction) {
        case  1: return n - position;
        case -1: return position - 1;
        default: return inf;
    }
}

int ans[3][3];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int rq, cq;
    scanf("%d %d", &rq, &cq);
    for (int dirR = -1; dirR <= 1; dirR++)
    for (int dirC = -1; dirC <= 1; dirC++)
    if (dirR != 0 || dirC != 0)
        ans[dirR+1][dirC+1] = min(available(rq, n, dirR), available(cq, n, dirC));

    for (int i = 0; i < k; i++) {
        int ro, co;
        scanf("%d %d", &ro, &co);
        int dirR, dirC;
        if (ro == rq || co == cq || abs(ro - rq) == abs(co - cq)) {
            dirR = sgn(ro - rq);
            dirC = sgn(co - cq);
            ans[dirR+1][dirC+1] = min(ans[dirR+1][dirC+1], max(abs(ro-rq), abs(co-cq)) - 1);
        }
    }

    int result = 0;
    for (int dirR = -1; dirR <= 1; dirR++)
    for (int dirC = -1; dirC <= 1; dirC++)
    if (dirR != 0 || dirC != 0)
        result += ans[dirR + 1][dirC + 1];

    printf("%d\n", result);
    return 0;
}