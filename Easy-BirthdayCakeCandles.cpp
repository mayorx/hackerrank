#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int total = 0, max = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x > max) {
            max = x;
            total = 1;
        } else if (x == max) {
            total += 1;
        }
    }
    printf("%d\n", total);
    return 0;
}