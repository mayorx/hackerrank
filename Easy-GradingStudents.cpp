#include <iostream>

using namespace std;

int round(int x) {
    if (x < 38) return x;
    if (x % 5 >= 3) return x + 5 - x % 5;
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", round(x));
    }
    return 0;
}